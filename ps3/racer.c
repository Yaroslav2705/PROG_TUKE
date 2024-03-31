#include <stdio.h>
#include <math.h>

double calculate_time(double *distances, double *velocities, int n, double k) {
    double total_time = 0;
    for (int i = 0; i < n; ++i) {
        double actual_velocity = velocities[i] + k;
        total_time += distances[i] / actual_velocity;
    }
    return total_time;
}

double find_constant(double *distances, double *velocities, int n, double t) {
    double left = -1000, right = 1000;
    double precision = 1e-7;

    if (n == 1) {
        return distances[0] / t - velocities[0];
    }

    while (right - left > precision) {
        double mid = (left + right) / 2;
        double time = calculate_time(distances, velocities, n, mid);
        if (time <= t) {
            right = mid;
        } else {
            left = mid;
        }
    }

    if (calculate_time(distances, velocities, n, right) <= t)
        return right;
    return left;
}

int main() {
    int n;
    double t;
    scanf("%d %lf", &n, &t);

    double distances[n], velocities[n];
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &distances[i], &velocities[i]);
    }

    double result = find_constant(distances, velocities, n, t);
    printf("%.9lf\n", result);

    return 0;
}
