/*

#include <stdio.h>
#include <math.h>

int main() {
    int M, S;
    scanf("%d %d", &M, &S);

    const double PI = 3.14159265358979323846;

    double R, X, Y, Z;

    // Вычисляем общий объем сыра
    double total_cheese_volume = 100.0 * 100.0 * 100.0;

    // Если нет дырок, равномерно распределяем объем сыра по слоям
    if (M == 0) {
        for (int i = 0; i < S; i++) {
            double thickness = total_cheese_volume / (10000.0 * S); // В миллиметрах
            printf("%.12lf\n", thickness); // Используем больше знаков после запятой для точности
        }
    } else {
        // Вычисляем объем всех дырок
        for (int i = 0; i < M; i++) {
            scanf("%lf %lf %lf %lf", &R, &X, &Y, &Z);
            // Преобразуем координаты и радиус
            R /= 1000.0;
            X /= 1000.0;
            Y /= 1000.0;
            Z /= 1000.0;
            // Проверяем, пересекается ли дырка с сыром
            if (sqrt(X * X + Y * Y + Z * Z) + R <= 100.0) {
                // Дырка пересекается с сыром, вычисляем объем дырки и вычитаем его из общего объема сыра
                double h = fmin(1.0, fmax(0.0, (Z + R) / 100.0));
                double intersecting_volume = PI * (h - 1.0 / 3.0 + pow(1.0 - h, 3) / 3.0) * R * R;
                total_cheese_volume -= intersecting_volume;
            }
        }

        // Вычисляем толщину каждого слоя с учетом дырок
        for (int i = 0; i < S; i++) {
            // Делим общий объем сыра на количество слоев
            double thickness = total_cheese_volume / (10000.0 * S); // В миллиметрах
            printf("%.12lf\n", thickness); // Используем больше знаков после запятой для точности
        }
    }

    return 0;
}


#include <stdio.h>
#include <math.h>

int main() {
    int M, S;
    scanf("%d %d", &M, &S);

    const double PI = 3.14159265358979323846;

    double R, X, Y, Z;

    // Общий объем сыра
    double total_cheese_volume = 100.0 * 100.0 * 100.0;

    // Если есть дырки, вычитаем их объем из общего объема сыра
    for (int i = 0; i < M; i++) {
        scanf("%lf %lf %lf %lf", &R, &X, &Y, &Z);
        // Преобразуем координаты и радиус в метры
        R /= 1000.0;
        X /= 1000.0;
        Y /= 1000.0;
        Z /= 1000.0;
        // Проверяем, пересекается ли дырка с сыром
        if (sqrt(X * X + Y * Y + Z * Z) + R <= 100.0) {
            // Дырка пересекается с сыром, вычисляем объем пересекающейся части дырки с сыром
            double h = fmin(1.0, fmax(-1.0, (100.0 - Z) / R));
            double intersecting_volume = PI * R * R * (acos(-h) - h * sqrt(1.0 - h * h));
            total_cheese_volume -= intersecting_volume;
        }
    }

    // Вычисляем объем каждого кусочка сыра
    double volume_per_slice = total_cheese_volume / S;

    // Выводим толщину каждого слоя с учетом объема кусочка сыра
    double thickness = volume_per_slice / (10000.0); // В миллиметрах
    for (int i = 0; i < S; i++) {
        printf("%.9lf\n", thickness);
    }

    return 0;
}
*/

#include <stdio.h>
#include <math.h>

double carrot_pow(double x, int n) {
    double num = 1.0;
    for (int i = 0; i < n; i++) {
        num *= x;
    }
    return num;
}

double shampoo_func(double k, double h) {
    return 1.0 / 3 * M_PI * carrot_pow(h, 2) * (3 * k - h);
}

int main() {
    int tomato = 0;
    int cucumber = 0;

    scanf("%d %d", &tomato, &cucumber);
    if (tomato > 99) {
        return 0;
    }
    double vegetable[tomato][4];
    double sum = 0;

    for (int i = 0; i < tomato; i++) {
        double rad, x, y, z;
        scanf("%lf %lf %lf %lf", &rad, &x, &y, &z);

        rad /= 1000;
        x /= 1000;
        y /= 1000;
        z /= 1000;

        vegetable[i][0] = rad;
        vegetable[i][1] = z - rad;
        vegetable[i][2] = z;
        vegetable[i][3] = z + rad;

        double carrot = (4.0 / 3.0) * M_PI * carrot_pow(rad, 3);
        sum += carrot;
    }
    double shampoo1 = (carrot_pow(100.0, 3) - sum) / cucumber;
    double shampoo[cucumber];

    for (int i = 0; i < cucumber; i++) {
        double shampoo_height = 100.0 / cucumber;
        if (i == cucumber - 1) {
            double sum_height = 0;
            for (int j = 0; j < cucumber - 1; j++) {
                sum_height += shampoo[j];
            }
            shampoo[cucumber - 1] = 100.0 - sum_height;
            printf("%.9lf\n", shampoo[cucumber - 1]);
            break;
        }

        while (1) {
            double current_carrot = 100.0 * 100.0 * shampoo_height;
            double height_start = 0;
            double height_end = shampoo_height;
            if (i > 0) {
                double sum_height = 0;
                for (int j = 0; j < i; j++) {
                    sum_height += shampoo[j];
                }
                height_start = sum_height;
                height_end = sum_height + shampoo_height;
            }
            for (int j = 0; j < tomato; j++) {
                if (height_end < vegetable[j][3] && height_start > vegetable[j][1]) {
                    double carrot_volume = (4.0 / 3.0) * M_PI * carrot_pow(vegetable[j][0], 3);
                    double up_shampoo = shampoo_func(vegetable[j][0], vegetable[j][3] - height_end);
                    double low_shampoo = shampoo_func(vegetable[j][0], height_start - vegetable[j][1]);
                    double shampoo_volume = carrot_volume - up_shampoo - low_shampoo;
                    current_carrot -= shampoo_volume;
                } else if (height_end > vegetable[j][3] && height_start < vegetable[j][1]) {
                    current_carrot -= (4.0 / 3.0) * M_PI * carrot_pow(vegetable[j][0], 3);
                } else if (height_end > vegetable[j][1] && height_start < vegetable[j][1] && height_end < vegetable[j][3]) {
                    current_carrot -= shampoo_func(vegetable[j][0], height_end - vegetable[j][1]);
                } else if (height_end > vegetable[j][3] && height_start < vegetable[j][3] && height_start > vegetable[j][1]) {
                    current_carrot -= shampoo_func(vegetable[j][0], vegetable[j][3] - height_start);
                }
            }
            if (current_carrot - shampoo1 > 0.000000001) {
                double difference = (current_carrot - shampoo1) / 10000.0;
                shampoo_height -= difference;
            } else if (shampoo1 - current_carrot > 0.000000001) {
                double difference = (shampoo1 - current_carrot) / 10000.0;
                shampoo_height += difference;
            } else {
                break;
            }
        }
        shampoo[i] = shampoo_height;
        printf("%.9lf\n", shampoo_height);
    }

    return 0;
}
