#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "playfair.h"

// Function to remove spaces from a string, convert it to uppercase,
// and replace 'W' with 'V'
void super_varik(char* str) {
    int svo = 0;
    for (int kak = 0; str[kak]; kak++) {
        if (!isspace(str[kak])) {  // If the character is not a space
            char wq = toupper(str[kak]);  // Convert it to uppercase
            if (wq == 'W') {
                wq = 'V';  // Replace 'W' with 'V'
            }
            str[svo++] = wq;  // Store the modified character
        }
    }
    str[svo] = '\0';  // Terminate the string
}

// Function to split the text into pairs of two letters
void split_into_pairs(char* str, char* pairs) {
    int pair_index = 0;
    for (int i = 0; str[i] != '\0'; i += 2) {
        pairs[pair_index++] = str[i];
        pairs[pair_index++] = str[i + 1];
        if (str[i + 2] != '\0') { // Add space only if the next character exists
            pairs[pair_index++] = ' ';
        }
    }
    pairs[pair_index] = '\0'; // Add null-terminating character
}

// Function for Playfair encryption
char* playfair_encrypt(const char* key, const char* text) {
    if (key == NULL || text == NULL)
        return NULL;

    // Remove spaces, convert to uppercase, and replace 'W' with 'V' for both key and text
    char nacalo[26], konec[1000]; // Increased buffer size for text
    strcpy(nacalo, key);
    strcpy(konec, text);
    super_varik(nacalo);
    super_varik(konec);

    // Allocate memory buffer for encrypted text with dynamic size
    int encrypted_buffer_size = strlen(konec) * 2; // Increased size for letter pairs
    char* encrypted_text = (char*)calloc((encrypted_buffer_size + 1), sizeof(char)); // Using calloc instead of malloc
    if (encrypted_text == NULL) {
        return NULL; // Check for successful memory allocation
    }

    // Create a 5x5 matrix for the key
    char matrix[5][5] = {0};  // Initialize all elements to 0
    int key_length = strlen(nacalo);
    int row = 0, col = 0;

    // Fill the matrix with unique characters from the key
    for (int i = 0; i < key_length; i++) {
        int exist = 0;
        for (int ii = 0; ii < 5; ii++) {
            for (int ij = 0; ij < 5; ij++) {
                if(matrix[ii][ij] == nacalo[i]) {
                    exist = 1;
                }
            }
        }

        if (!exist) {
            matrix[row][col++] = nacalo[i];
            if (col == 5) {
                row++;
                col = 0;
            }
        }
    }

    // Fill the matrix with remaining alphabet characters
    char ch = 'A';
    for (int i = row; i < 5; i++) {
        for (int j = col; j < 5; j++) {
            while (strchr(nacalo, ch) || ch == 'W') {
                ch++;
            }
            matrix[i][j] = ch++;
        }
        col = 0;
    }

    // Encrypt the text
    int text_length = strlen(konec);
    int encrypted_index = 0;

    for (int i = 0; i < text_length; i += 2) {
        char first = konec[i];
        char second = (i + 1 < text_length) ? konec[i + 1] : 'X'; // Add 'X' if text length is odd

        // If both letters are the same, add 'X' in between
        if (first == second && first != 'X') {
            second = 'X';
            i--;  // Go back to process the 'X'
        }

        int row1, col1, row2, col2;

        // Find positions of letters in the matrix
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                if (matrix[row][col] == first) {
                    row1 = row;
                    col1 = col;
                }
                if (matrix[row][col] == second) {
                    row2 = row;
                    col2 = col;
                }
            }
        }

        // Encrypt the letters
        char encrypted_first, encrypted_second;
        if (col1 == col2) {  // If both letters are in the same column
            encrypted_first = matrix[(row1 + 1) % 5][col1];
            encrypted_second = matrix[(row2 + 1) % 5][col2];
        }
        else if (row1 == row2) {  // If both letters are in the same row
            encrypted_first = matrix[row1][(col1 + 1) % 5];
            encrypted_second = matrix[row2][(col2 + 1) % 5];         
        } else {  // If letters are in different rows and columns
            encrypted_first = matrix[row1][col2];
            encrypted_second = matrix[row2][col1];
        }

        // Add encrypted letters to the result
        encrypted_text[encrypted_index++] = encrypted_first;
        encrypted_text[encrypted_index++] = encrypted_second;
    }

    // Add the null-terminating character
    encrypted_text[encrypted_index] = '\0';

    // Split the encrypted text into pairs of two letters
    char* encrypted_pairs = (char*)calloc((2 * text_length + 1), sizeof(char));
    split_into_pairs(encrypted_text, encrypted_pairs);

    free(encrypted_text);

    return encrypted_pairs;
}

// Function for Playfair decryption
char* playfair_decrypt(const char* key, const char* text) {
    if (key == NULL || text == NULL)
        return NULL;

    // Remove spaces, convert to uppercase, and replace 'W' with 'V' for both key and text
    char nacalo[26], konec[1000];
    strcpy(nacalo, key);
    strcpy(konec, text);
    super_varik(nacalo);
    super_varik(konec);

    // Create a 5x5 matrix for the key
    char matrix[5][5] = {0};  // Initialize all elements to 0
    int key_length = strlen(nacalo);
    int row = 0, col = 0;

    // Fill the matrix with unique characters from the key
    for (int i = 0; i < key_length; i++) {
        int exist=0;
        for (int ii = 0; ii < 5; ii++) {
            for (int ij = 0; ij < 5; ij++) {
                if(matrix[ii][ij]==nacalo[i]) {
                    exist=1;
                }
            }
        }

        if(!exist) {
            matrix[row][col++] = nacalo[i];
            if (col == 5) {
                row++;
                col = 0;
            }
        }
    }

    // Fill the matrix with remaining alphabet characters
    char ch = 'A';
    for (int i = row; i < 5; i++) {
        for (int j = col; j < 5; j++) {
            while (strchr(nacalo, ch) || ch == 'W') {
                ch++;
            }
            matrix[i][j] = ch++;
        }
        col = 0;
    }

    // Decrypt the text
    int text_length = strlen(konec);
    char* decrypted_text = (char*)malloc((2 * text_length + 1) * sizeof(char));
    int decrypted_index = 0;

    for (int i = 0; i < text_length; i += 2) {
        char first = konec[i];
        char second = konec[i + 1];

        int row1, col1, row2, col2;

        // Find positions of letters in the matrix
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                if (matrix[row][col] == first) {
                    row1 = row;
                    col1 = col;
                }
                if (matrix[row][col] == second) {
                    row2 = row;
                    col2 = col;
                }
            }
        }

        // Decrypt the letters
        char decrypted_first, decrypted_second;
        if (col1 == col2) {  // If both letters are in the same column
            decrypted_first = matrix[(row1 - 1 + 5) % 5][col1];
            decrypted_second = matrix[(row2 - 1 + 5) % 5][col2];
        }
        else if (row1 == row2) {  // If both letters are in the same row
            decrypted_first = matrix[row1][(col1 - 1 + 5) % 5];
            decrypted_second = matrix[row2][(col2 - 1 + 5) % 5];         
        } else {  // If letters are in different rows and columns
            decrypted_first = matrix[row1][col2];
            decrypted_second = matrix[row2][col1];
        }

        // Add decrypted letters to the result
        decrypted_text[decrypted_index++] = decrypted_first;
        decrypted_text[decrypted_index++] = decrypted_second;
    }

    // Add the null-terminating character
    decrypted_text[decrypted_index] = '\0';
    /*
    // Split the decrypted text into pairs of two letters
    printf("Decrypted text pairs: ");
    split_into_pairs(decrypted_text);
    */
    return decrypted_text;
}

/*
int main() {
    const char* key = "secret";
    const char* text = "Hello World!";
    
    // Encryption
    char* encrypted_text = playfair_encrypt(key, text);
    printf("%s\n", encrypted_text); //   
	
		// Decryption
    //const char* encrypted_text_to_decrypt = "IS JZ JQ XN TK JC";  // Example encrypted text
    char* encrypted_text_to_decrypt = encrypted_text;
    char* decrypted_text = playfair_decrypt(key, encrypted_text_to_decrypt);
    
    printf("%s\n", decrypted_text);
    free(decrypted_text);
	free(encrypted_text);


    //  ,    
    //free(encrypted_text);
    
    return 0;
}*/

