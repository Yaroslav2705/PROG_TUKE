#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"

struct parser* create_parser() {
    struct parser* new_parser = (struct parser*)malloc(sizeof(struct parser));
    if (new_parser == NULL) {
        return NULL; // Memory allocation failed
    }

    // Initialize history list
    new_parser->history = create_container();
    if (new_parser->history == NULL) {
        free(new_parser);
        return NULL; // Memory allocation failed
    }

    // Initialize commands list
    new_parser->commands = create_container();
    if (new_parser->commands == NULL) {
        destroy_container(new_parser->history);
        free(new_parser);
        return NULL; // Memory allocation failed
    }

    // Add commands to the list (example)
    struct command* cmd1 = create_command("KONEC", "Komanda ukončí aktuálnu hru.", "(KONEC|VYCHOD|VYJDI)", 1);
    struct command* cmd2 = create_command("SEVER", "Pohyb na sever od aktuálnej miestnosti.", "(SEVER|S)", 1);
    // Add more commands as needed...

    // Add commands to the commands list
    add_to_container(new_parser->commands, cmd1);
    add_to_container(new_parser->commands, cmd2);
    // Add more commands to the commands list as needed...

    return new_parser;
}

struct parser* destroy_parser(struct parser* parser) {
    if (parser != NULL) {
        // Destroy history list
        destroy_container(parser->history);

        // Destroy commands list
        destroy_containers(parser->commands);

        free(parser);
    }
    return NULL;
}

struct command* parse_input(struct parser* parser, char* input) {
    // Trim leading and trailing whitespaces
    char* trimmed_input = input;
    while (isspace(*trimmed_input)) {
        trimmed_input++;
    }
    size_t len = strlen(trimmed_input);
    while (len > 0 && isspace(trimmed_input[len - 1])) {
        trimmed_input[--len] = '\0';
    }

    // Tokenize input
    char* token = strtok(trimmed_input, " ");
    if (token == NULL) {
        return NULL; // No input
    }

    // Convert token to uppercase
    for (char* ptr = token; *ptr != '\0'; ++ptr) {
        *ptr = toupper(*ptr);
    }

    // Find command in the commands list
    struct command* cmd = NULL;
    struct node* current = parser->commands->head;
    while (current != NULL) {
        struct command* c = (struct command*)current->data;
        if (strcmp(token, c->name) == 0) {
            cmd = c;
            break;
        }
        current = current->next;
    }

    // Add input to history list
    if (cmd != NULL) {
        add_to_container(parser->history, strdup(trimmed_input));
    }

    return cmd;
}
