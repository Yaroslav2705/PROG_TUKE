#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"

char* strdup(const char* str) {
    if (str == NULL) return NULL;

    size_t len = strlen(str);
    char* new_str = (char*)malloc(len + 1);
    if (new_str == NULL) return NULL;

    strcpy(new_str, str);
    return new_str;
}


struct command* create_command(char* name, char* description, char* pattern, size_t nmatch) {
    if (name == NULL || description == NULL) {
        return NULL; // Command cannot be created without name or description
    }

    struct command* new_command = (struct command*)malloc(sizeof(struct command));
    if (new_command == NULL) {
        return NULL; // Memory allocation failed
    }

    new_command->name = strdup(name);
    new_command->description = strdup(description);
    new_command->nmatch = nmatch;

    // Compile pattern if provided
    if (pattern != NULL) {
        if (regcomp(&(new_command->preg), pattern, REG_EXTENDED | REG_ICASE) != 0) {
            // Pattern compilation failed
            free(new_command->name);
            free(new_command->description);
            free(new_command);
            return NULL;
        }
    } else {
        // No pattern provided
        new_command->preg = (regex_t){0};
    }

    return new_command;
}

struct command* destroy_command(struct command* command) {
    if (command != NULL) {
        free(command->name);
        free(command->description);
        regfree(&(command->preg));
        free(command);
    }
    return NULL;
}

}
