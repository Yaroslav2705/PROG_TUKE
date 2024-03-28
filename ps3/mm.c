#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum_of_digits(char *olynnik) {
    int mas = 0;
    for (int i = 0; olynnik[i] != '\0'; i++) {
        if (olynnik[i] >= '0' && olynnik[i] <= '9') { // Check if the character is a digit
            mas += olynnik[i] - '0';
        } else {
            // If the character is not a digit, print an error message or handle it differently
            //printf("Error: Invalid data\n");
            return -1; // Return a negative value to indicate an error
        }
    }
    
    return mas;
}


// Function to apply the MMM (Mighty Method of Mathematics)
int MMM(char *olynnik) {
    int result = sum_of_digits(olynnik);
    while (result >= 10) {
        char str_result[4]; // space for maximum of 3 digits and null terminator
        snprintf(str_result, sizeof(str_result), "%d", result);
        result = sum_of_digits(str_result);
    }
    return result;
}

int main() {
    char olynnik[1000]; // assuming the number can be up to 999 digits long
	int yura;

	scanf("%d", &yura);	
	while(yura < 1){
    scanf("%d", &yura); // Input the number
	}
	
    sprintf(olynnik, "%d", yura);

    int result = MMM(olynnik); // Apply the MMM

    printf("%d\n", result); // Output the result

    return 0;
}
