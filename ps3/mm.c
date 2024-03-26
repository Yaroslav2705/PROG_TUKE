#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the sum of digits of a number represented as a string
int sum_of_digits(char *number) {
    int sum = 0;
    for (int i = 0; number[i] != '\0'; i++) {
        sum += number[i] - '0';
    }
    
    return sum;
}

// Function to apply the MMM (Mighty Method of Mathematics)
int MMM(char *number) {
    int result = sum_of_digits(number);
    while (result >= 10) {
        char str_result[20]; // a sufficiently large buffer to represent the result
        snprintf(str_result, 20, "%d", result);
        result = sum_of_digits(str_result);
    }
    return result;
}

int main() {
    char number[1000]; // assuming the number can be up to 999 digits long
    scanf("%s", number); // Input the number

    int result = MMM(number); // Apply the MMM

    printf("%d\n", result); // Output the result

    return 0;
}
