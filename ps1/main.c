#include "bmp.h"
#include "playfair.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(){

	char *encrypted, *decrypted;

// even length of string
encrypted = playfair_encrypt("SeCReT", "Hello world");
printf("%s", encrypted);
// "Hello world" --> "HELXLOVORLDX"
// IS JZ JQ XN TK JC
decrypted = playfair_decrypt("SeCReT", encrypted);
printf("%s", decrypted);
// HELXLOVORLDX
free(encrypted);
free(decrypted);
	
	char *encrypted_2, *decrypted_2;

// odd length of string
encrypted_2 = playfair_encrypt("world", "Hello");
printf("%s", encrypted_2);
// "Hello" --> "HELXLO"
// JB RY DR
decrypted_2 = playfair_decrypt("world", encrypted_2);
printf("%s", decrypted_2);
// HELXLO
free(encrypted_2);
free(decrypted_2);

	char *encrypted_3, *decrypted_3;

// letter 'X' in message
encrypted_3 = playfair_encrypt("Password", "Taxi please");
printf("%s", encrypted_3);
// "Taxi please" --> "TAXIPLEASE"
// UP YH AK DO OB
decrypted_3 = playfair_decrypt("Password", encrypted_3);
printf("%s", decrypted_3);
// TAXIPLEASE
free(encrypted_3);
free(decrypted_3);

	char *encrypted_4, *decrypted_4;

// multi 'X's in message
encrypted_4 = playfair_encrypt("please", "Taxxxiii");
printf("%s", encrypted_4);
// "Taxxxiii" --> "TAXXXIIXIX"
// RS EE VJ JV JV
decrypted_4 = playfair_decrypt("please", encrypted_4);
printf("%s", decrypted_4);
// TAXXXIIXIX
free(encrypted_4);
free(decrypted_4);

char* reversed = reverse("Hello world!");
printf("%s\n", reversed);
// "!DLROW OLLEH"

char* encrypted_1;

// basic test with long text
encrypted_1 = vigenere_encrypt("CoMPuTeR", "Hello world!");
printf("%s\n", encrypted);
// "JSXAI PSINR!"



}
