#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bmp.h"

/*char* reverse (const char* text){   
    if(text == NULL){
        return NULL;}
    return "";
    }*/

bool is_all_alpha(const char* str) {
    while (*str) {
        if (!isalpha(*str)) {
            return false; // If the character is not a letter, return false
        }
        ++str;
    }
    return true; // If all characters are letters, return true
}

char* reverse(const char* text) {
    if (text == NULL)
        return NULL;

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
    if (key == NULL || text == NULL)
        return NULL;

    // Check if the key contains only letters
    if (!is_all_alpha(key))
        return NULL;


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
    if (key == NULL || text == NULL)
        return NULL;

    // Check if the key contains only letters
    if (!is_all_alpha(key))
        return NULL;

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

unsigned char* bit_encrypt(const char* text) {
    // Выделяем память для зашифрованного текста
    unsigned char* encrypted = (unsigned char*)calloc(strlen(text) * sizeof(unsigned char));
    if (encrypted == NULL) {
        return NULL; // Возвращаем NULL в случае ошибки выделения памяти
    }

    int i = 0;
    while (text[i] != '\0') {
        // Преобразуем символ в его ASCII-код
        unsigned char ch = text[i];

        // Разделяем символ на две половины по 4 бита каждая
        unsigned char half1 = ch >> 4;
        unsigned char half2 = ch & 0x0F;

        // Меняем местами биты в первой половине
        half1 = ((half1 & 0x0A) >> 1) | ((half1 & 0x05) << 1);

        // XOR для первой и второй половин
        encrypted[i] = (half1 << 4) | (half1 ^ half2);

        // Увеличиваем счетчик
        i++;
    }

    return encrypted;
}

char* bit_decrypt(const unsigned char* text) {
    // Получаем размер зашифрованного текста
    int size = strlen((char*)text); // Преобразуем указатель на unsigned char в строку
    if (encrypted == NULL) {
        return NULL; // Возвращаем NULL в случае ошибки выделения памяти
    }
    // Выделяем память для расшифрованного текста
    char* decrypted = (char*)calloc((size + 1) * sizeof(char));
    if (decrypted == NULL) {
        return NULL; // Возвращаем NULL в случае ошибки выделения памяти
    }

    for (int i = 0; i < size; i++) {
        // Разделяем зашифрованный символ на две половины
        unsigned char half1 = text[i] >> 4;
        unsigned char half2 = text[i] & 0x0F;
        
        // Меняем местами биты в первой половине обратно
        half1 = ((half1 & 0x0A) >> 1) | ((half1 & 0x05) << 1);
        
        // XOR для первой и второй половин
        char ch = (half1 << 4) | half2;
        
        // Преобразуем ASCII-код в символ
        decrypted[i] = ch;
    }
    
    // Добавляем завершающий нуль
    decrypted[size] = '\0';
    
    return decrypted;
}


unsigned char* bmp_encrypt(const char* key, const char* text) {
    if (key == NULL || text == NULL)
        return NULL;

    // Check if the key contains only letters
    if (!is_all_alpha(key))
        return NULL;

    char* reversed_text = reverse(text);
    char* encrypted_text = vigenere_encrypt(key, reversed_text);
    free(reversed_text);
    char* encrypted_text_1 = bit_encrypt(encrypted_text);
    free(encrypted_text);
    return (unsigned char*)encrypted_text_1;
}

char* bmp_decrypt(const char* key, const unsigned char* text) {
    if (key == NULL || text == NULL)
        return NULL;

    // Check if the key contains only letters
    if (!is_all_alpha(key))
        return NULL;

    char* decrypted_reversed_text = vigenere_decrypt(key, (char*)text);
    char* decrypted_text = reverse(decrypted_reversed_text);
    free(decrypted_reversed_text);
    char* decrypted_text_1 = bit_decrypt(decrypted_text);
    free(decrypted_text);
    return decrypted_text_1;
}

/*
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
}*/
