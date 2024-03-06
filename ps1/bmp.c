#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//#include "bmp.h"

/*char* reverse (const char* text){   
    if(text == NULL){
        return NULL;}
    return "";
    }*/

char* reverse(const char* text) {
    size_t length = strlen(text);
    char* reversed_text = (char*)calloc(length + 1, sizeof(char)); // Выделение памяти для результата
    if (reversed_text == NULL) {
        return NULL; // Обработка ошибки выделения памяти
    }

    for (size_t i = 0; i < length; ++i) {
        reversed_text[i] = toupper(text[length - i - 1]); // Копирование символов в обратном порядке
    }

    return reversed_text;
}


// Function to convert text to uppercase
void to_uppercase(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

char* vigenere_encrypt(const char* key, const char* text) {
    if (key == NULL || text == NULL || strlen(key) == 0 || strspn(key, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") == 0 /*|| strspn(text, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") == 0*/) {
        return NULL; // Check for the correctness of the key
    }

    int aboba = strlen(key); // Length of the key
    int obabo = strlen(text); // Length of the text

    if (aboba == 0 || obabo == 0) {
        return NULL; // Проверка на корректность входных данных
    }

    char* encrypted_text = (char*)calloc((obabo + 1), sizeof(char));
    if (encrypted_text == NULL) {
        return NULL; // Return NULL in case of memory allocation failure
    }

    for (int i = 0, j = 0; i < obabo; i++) {
        char current_char = text[i];
        if (isalpha(current_char)) {
            char offset = islower(current_char) ? 'a' : 'A';
            encrypted_text[i] = ((toupper(key[j % aboba]) - 'A' + current_char - offset) % 26) + offset;
            j++;
        } else {
            encrypted_text[i] = current_char; // Non-alphabetic characters remain unchanged
        }
    }
    encrypted_text[obabo] = '\0'; // Don't forget to add the null-terminating character

    // Convert the entire encrypted text to uppercase
    to_uppercase(encrypted_text);

    return encrypted_text;
}

char* vigenere_decrypt(const char* key, const char* text) {
    if (key == NULL || text == NULL || strlen(key) == 0 || strspn(key, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") == 0 /*|| strspn(text, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") == 0*/) {
        return NULL; // Check for the correctness of the key
    }

    int abobo = strlen(key); // Length of the key
    int obobo = strlen(text); // Length of the text

    if (abobo == 0 || obobo == 0) {
        return NULL; // Проверка на корректность входных данных
    }

    char* decrypted_text = (char*)calloc((obobo + 1), sizeof(char));
    if (decrypted_text == NULL) {
        return NULL; // Return NULL in case of memory allocation failure
    }

    for (int i = 0, j = 0; i < obobo; i++) {
        char current_char = text[i];
        if (isalpha(current_char)) {
            char offset = islower(current_char) ? 'a' : 'A';
            decrypted_text[i] = ((current_char - offset) - (toupper(key[j % abobo]) - 'A')) % 26;
            if (decrypted_text[i] < 0) {
                decrypted_text[i] += 26; // Handling negative values
            }
            decrypted_text[i] += offset;
            j++;
        } else {
            decrypted_text[i] = current_char; // Non-alphabetic characters remain unchanged
        }
    }
    decrypted_text[obobo] = '\0'; // Don't forget to add the null-terminating character
    
    // Convert the entire decrypted text to uppercase
    to_uppercase(decrypted_text);

    return decrypted_text;
}



unsigned char* bmp_encrypt(const char* key, const char* text) {
    if (key == NULL || text == NULL || strlen(key) == 0) {
        return NULL; // Necessary check for input data validity
    }

    char* reversed_text = reverse(text);
    if (reversed_text == NULL) {
        return NULL; // Check for successful memory allocation
    }

    char* encrypted_text = vigenere_encrypt(key, reversed_text);
    free(reversed_text); // Memory deallocation after usage

    return (unsigned char*)encrypted_text;
}

char* bmp_decrypt(const char* key, const unsigned char* text) {
    if (key == NULL || text == NULL) {
        return NULL; // Check for input data validity
    }

    char* decrypted_reversed_text = vigenere_decrypt(key, (char*)text);
    if (decrypted_reversed_text == NULL) {
        return NULL; // Check for successful decryption of the text
    }

    char* decrypted_text = reverse(decrypted_reversed_text);
    free(decrypted_reversed_text); // Memory deallocation after usage

    return decrypted_text;
}


int main() {
    const char* key = "secret";
    const char* original_text = "Hello World!";
    
    // Encryption
    unsigned char* encrypted_text = bmp_encrypt(key, original_text);
    printf("Encrypted Text: %s\n", encrypted_text);
    
    // Decryption
    char* decrypted_text = bmp_decrypt(key, (unsigned char*)encrypted_text);
    printf("Decrypted Text: %s\n", decrypted_text);

    free(encrypted_text);
    free(decrypted_text);

    return 0;
}
