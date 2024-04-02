#include <stdio.h>
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
                total_cheese_volume -= intersecting_height * intersecting_height * M_PI * R * R;
            }
            double thickness = total_cheese_volume / (10000.0 * S); // Convert to millimeters
            printf("%.7lf\n", thickness);
        }
    }

    return 0;
}