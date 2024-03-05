#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* reverse (const char* text){   
    if(text == NULL){
        return NULL;}
    return "";
    }

/*char* reverse(const char* text) {
    static char vladik[256]; // Static buffer to store the reversed string
    size_t aboba = strlen(text);

    for (size_t kak = 0; kak < aboba; ++kak) {
        vladik[kak] = toupper(text[aboba - kak - 1]); // Convert the character to uppercase
    }

    vladik[aboba] = '\0'; // Add the terminating null character after the loop

    return vladik;
}

int main() {
    const char* original = "Hello world!";
    char* vladik = reverse(original);

    printf("%s\n", vladik);

    return 0;
}*/
