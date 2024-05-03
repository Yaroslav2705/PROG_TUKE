
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

void play_game(struct game* game) {
    // Game loop
    while (game->state == PLAYING) {
        char input[INPUT_BUFFER_SIZE];
        printf("Enter a command: ");
        fgets(input, sizeof(input), stdin);
        // Remove trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Parse and execute command
        struct command* cmd = parse_command(game->parser, input);
        if (cmd != NULL) {
            execute_command(game, cmd);
            destroy_command(cmd);
        } else {
            printf("Invalid command\n");
        }
    }
}

struct game* create_game() {
    struct game* new_game = (struct game*)malloc(sizeof(struct game));
    if (new_game == NULL) {
        return NULL; // Memory allocation failed
    }

    new_game->state = PLAYING;

    // Initialize parser
    new_game->parser = create_parser();

    // Initialize world (list of rooms)
    new_game->world = NULL; // Assuming the list is empty initially

    // Initialize current room
    new_game->current_room = NULL; // No room selected initially

    // Initialize backpack
    new_game->backpack = create_backpack();

    return new_game;
}

struct game* destroy_game(struct game* game) {
    if (game != NULL) {
        // Destroy parser
        destroy_parser(game->parser);

        // Destroy world (list of rooms)
        destroy_containers(game->world);

        // Destroy backpack
        destroy_backpack(game->backpack);

        free(game);
    }
    return NULL;
}

void execute_command(struct game* game, struct command* command) {
    // Implementation of command execution logic
    // This is just a placeholder
    printf("Executing command: %s\n", command->name);
}
*/