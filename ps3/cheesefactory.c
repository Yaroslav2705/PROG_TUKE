/*#include <stdio.h>
#include <math.h>

int main() {
    int M, S;
    scanf("%d %d", &M, &S);

    const double PI = 3.14159265358979323846;

    double R, X, Y, Z;

    if (M == 0) {
        double thickness = 100.0 / S;
        for (int i = 0; i < S; i++) {
            printf("%.7lf\n", thickness);
        }
    } else {
        for (int i = 0; i < S; i++) {
            double total_cheese_volume = 100.0 * 100.0 * 100.0;
            for (int j = 0; j < M; j++) {
                scanf("%lf %lf %lf %lf", &R, &X, &Y, &Z);
                // Делаем преобразование координат и радиуса
                R /= 1000.0;
                X /= 1000.0;
                Y /= 1000.0;
                Z /= 1000.0;
                double h = fmin(1.0, fmax(0.0, (Z + R) / 100.0));
                double intersecting_volume = PI * (h - 1.0 / 3.0 + pow(1.0 - h, 3) / 3.0) * R * R;
                total_cheese_volume -= intersecting_volume;
            }
            double thickness = total_cheese_volume / (10000.0 * M); // Convert to millimeters
            printf("%.7lf\n", thickness);
        }
    }

    return 0;
}
*/

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