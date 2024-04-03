#include <stdio.h>
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
