#include <stdio.h>

int main() {
    // Функция для вычисления суммы цифр числа
    int sum_of_digits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    // Функция для применения метода ММ
    int mighty_method(int n) {
        while (n >= 10) {
            n = sum_of_digits(n);
        }
        return n;
    }

    int student_id;
    printf(" ");
    scanf("%d", &student_id);

    int result = mighty_method(student_id);
    printf("%d\n", result);

    return 0;
}