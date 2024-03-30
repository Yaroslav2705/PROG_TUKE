#include <stdio.h>
#include <math.h>

int n;
double t;
double s[1005], v[1005];

double total_time(double k, double max_speed, double min_speed) {
    double total = 0;
    for (int i = 0; i < n; ++i) {
        double actual_speed = v[i] + k;
        total += s[i] / (fabs(actual_speed) > fabs(min_speed) ? fabs(actual_speed) : fabs(min_speed));
    }
    return total;
}

double binary_search(double low, double high, double max_speed, double min_speed) {
    double epsilon = 1e-7;
    while (high - low > epsilon) {
        double mid = (low + high) / 2.0;
        if (total_time(mid, max_speed, min_speed) > t)
            high = mid;
        else
            low = mid;
    }
    return low;
}

int main() {
    scanf("%d %lf", &n, &t);
    double max_speed = 0, min_speed = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", &s[i], &v[i]);
        max_speed = fmax(max_speed, v[i]);
        min_speed = fmin(min_speed, v[i]);
    }

    double result = binary_search(-max_speed, -min_speed, max_speed, min_speed);
    printf("%.7lf\n", result);

    return 0;
}
