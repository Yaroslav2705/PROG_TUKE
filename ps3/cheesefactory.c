/*#include <stdio.h>
#include <math.h>

int main() {
    int M, S;
    scanf("%d %d", &M, &S);

    if (M == 0) {
        double thickness = 100.0 / S;
        for (int i = 0; i < S; i++) {
            printf("%.7lf\n", thickness);
        }
    } else {
        for (int i = 0; i < S; i++) {
            double total_cheese_volume = 100.0 * 100.0 * 100.0;
            for (int j = 0; j < M; j++) {
                double R, X, Y, Z;
                scanf("%lf %lf %lf %lf", &R, &X, &Y, &Z);
                double intersecting_height = fmin(100.0, fmax(0.0, R + Z));
                total_cheese_volume -= intersecting_height * intersecting_height * 3.14159265358979323846 * R * R;
            }
            double thickness = total_cheese_volume / (10000.0 * S); // Convert to millimeters
            printf("%.7lf\n", thickness);
        }
    }

    return 0;
}*/

#include <stdio.h>
#include <math.h>

int main() {
    int M, S;
    scanf("%d %d", &M, &S);

    const double PI = 3.14159265358979323846;

    if (M == 0) {
        double thickness = 100.0 / S;
        for (int i = 0; i < S; i++) {
            printf("%.7lf\n", thickness);
        }
    } else {
        int processed_slices = 0; // Переменная для отслеживания количества обработанных ломтей
        for (int i = 0; i < S; i++) {
            double total_cheese_volume = 100.0 * 100.0 * 100.0;
            for (int j = 0; j < M; j++) {
                double R, X, Y, Z;
                scanf("%lf %lf %lf %lf", &R, &X, &Y, &Z);
                double h = fmin(1.0, fmax(0.0, (Z + R) / 100.0));
                double intersecting_volume = PI * (h - 1.0 / 3.0 + pow(1.0 - h, 3) / 3.0) * R * R;
                total_cheese_volume -= intersecting_volume;
            }
            double thickness = total_cheese_volume / (10000.0 * M); // Convert to millimeters
            printf("%.7lf\n", thickness);
            processed_slices++; // Увеличиваем количество обработанных ломтей
            if (processed_slices == S) // Если обработано достаточно ломтей, выходим из цикла
                break;
        }
    }

    return 0;
}
