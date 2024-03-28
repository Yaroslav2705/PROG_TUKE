#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the sum of digits of a number represented as a string
int mas_of_yura(char *olinnyk) {
    int mas = 0;
    for (int i = 0; olinnyk[i] != '\0'; i++) {
        mas += olinnyk[i] - '0';
    }
    return mas;
}

// Function to apply the MMM (Mighty Method of Mathematics)
int MMM(char *olinnyk) {
    int result = mas_of_yura(olinnyk);
    while (result >= 10) {
        char str_result[20]; // a sufficiently large buffer to represent the result
        snprintf(str_result, 20, "%d", result);
        result = mas_of_yura(str_result);
    }
    return result;
}

int main() {
    char olinnyk[100000]; // assuming the number can be up to 999 digits long
    scanf("%s", olinnyk); // Input the number

    int result = MMM(olinnyk); // Apply the MMM

    printf("%d\n", result); // Output the result

    return 0;
}
