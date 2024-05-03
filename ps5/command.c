#include <stdlib.h>
#include <string.h> // Добавленный заголовочный файл для использования функции strdup
#include "command.h"

struct command* create_command(char* name, char* description, char* pattern, size_t nmatch) {
    struct command* new_command = (struct command*)malloc(sizeof(struct command));
    if (new_command != NULL) {
        new_command->name = strdup(name); // Дублируем строку name
        new_command->description = strdup(description); // Дублируем строку description
        new_command->pattern = strdup(pattern); // Дублируем строку pattern
        new_command->nmatch = nmatch;
    }
    return new_command;
}

struct command* destroy_command(struct command* command) {
    if (command != NULL) {
        free(command->name); // Освобождаем память для дублированных строк
        free(command->description);
        free(command->pattern);
        free(command);
    }
    return NULL;
}
