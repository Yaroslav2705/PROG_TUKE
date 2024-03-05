#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "bmp.h"

/*char* reverse (const char* text){   
    if(text == NULL){
        return NULL;}
    return "";
    }*/

char* reverse(const char* text) {
    size_t length = strlen(text);
    char* reversed_text = (char*)calloc(length + 1, sizeof(char)); //    
    if (reversed_text == NULL) {
        return NULL; //    
    }

    for (size_t i = 0; i < length; ++i) {
        reversed_text[i] = toupper(text[length - i - 1]); //     
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
    int aboba = strlen(key); // Length of the key
    int obabo = strlen(text); // Length of the text

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
    int abobo = strlen(key); // Length of the key
    int obobo = strlen(text); // Length of the text

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
	
	to_uppercase(decrypted_text);

    return decrypted_text;
}

char* bmp_encrypt(const char* key, const char* text) {
    char* reversed_text = reverse(text);
    char* encrypted_text = vigenere_encrypt(key, reversed_text);
    free(reversed_text);
    return encrypted_text;
}

char* bmp_decrypt(const char* key, const unsigned char* text) {
    char* decrypted_reversed_text = vigenere_decrypt(key, (char*)text);
    char* decrypted_text = reverse(decrypted_reversed_text);
    free(decrypted_reversed_text);
    return decrypted_text;
}

/*
int main() {
    const char* key = "secret";
    const char* original_text = "Hello World!";
    
    // Encryption
    char* encrypted_text = bmp_encrypt(key, original_text);
    printf("Encrypted Text: %s\n", encrypted_text);
    
    // Decryption
    char* decrypted_text = bmp_decrypt(key, (unsigned char*)encrypted_text);
    printf("Decrypted Text: %s\n", decrypted_text);

    free(encrypted_text);
    free(decrypted_text);

    return 0;
}*/
