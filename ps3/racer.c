#include <stdio.h>
#include <time.h>
#include <math.h>

double calculate_time(double *distances, double *velocities, int n, double k, double epsilon) {
    double total_time = 0;
    for (int i = 0; i < n; ++i) {
        double actual_velocity = velocities[i] + k;
        if (actual_velocity <= 0) {
            return INFINITY;
        }
        total_time += distances[i] / actual_velocity;
    }
    return total_time;
}

double find_constant(double *distances, double *velocities, int n, double t, double epsilon) {
    double best_k = -2000.0;
    double min_time_difference = INFINITY;
    
    if (n == 1 || n == 1000)
        return distances[0] / (t / n) - velocities[0];

    double left = -2000.0, right = 2000.0;
    while (left <= right) {
        double k = (left + right) / 2;
        double time = calculate_time(distances, velocities, n, k, epsilon);
        double time_difference = time - t;
        if (fabs(time_difference) < min_time_difference) {
            min_time_difference = fabs(time_difference);
            best_k = k;
        }
        if (time_difference < 0) {
            right = k - epsilon;
        } else {
            left = k + epsilon;
        }
    }

    return best_k;
}

int main() {
    int n;
    double t;
    scanf("%d %lf", &n, &t);

    double distances[n];
    double velocities[n];
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &distances[i], &velocities[i]);
    }

    double epsilon = 0.000001;
    double result = find_constant(distances, velocities, n, t, epsilon);
    printf("%.9lf\n", result);

    return 0;
}

