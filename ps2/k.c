#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "k.h"



bool is_game_won(const struct game game) {
    for (int kak = 0; kak < SIZE; kak++) {
        for (int kok = 0; kok < SIZE; kok++) {
            if (game.board[kak][kok] == 'K')
                return true;
        }
    }
    return false;
}

bool is_move_possible(const struct game game) {
    for (int kak = 0; kak < SIZE - 1; kak++) {
        for (int kok = 0; kok < SIZE - 1; kok++) {
            if (game.board[kak][kok] == ' ')
                return true;

            if (game.board[kak][kok] == game.board[kak + 1][kok] || game.board[kak][kok] == game.board[kak][kok + 1])
                return true;
        }
    }

    for (int kik = 0; kik < SIZE - 1; kik++) {
        if (game.board[SIZE - 1][kik] == ' ' || game.board[kik][SIZE - 1] == ' ')
            return true;

        if (game.board[SIZE - 1][kik] == game.board[SIZE - 1][kik + 1] || game.board[kik][SIZE - 1] == game.board[kik + 1][SIZE - 1])
            return true;
    }
    return false;
}

// Generates a new tile on a random empty cell on the board
void generate_new_tile(struct game *game) {
    int empty_count = 0;
    int empty_indices[SIZE * SIZE][2]; // Array to store indices of empty cells

    // Find all empty cells on the board and store their indices in the array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (game->board[i][j] == ' ') {
                empty_indices[empty_count][0] = i;
                empty_indices[empty_count][1] = j;
                empty_count++;
            }
        }
    }

    // If there are empty cells, choose a random one and generate a new tile
    if (empty_count > 0) {
        int random_index = rand() % empty_count;
        int row = empty_indices[random_index][0];
        int col = empty_indices[random_index][1];
        // Generate a new 'A' or 'B' tile with a 90% chance of 'A' and 10% chance of 'B'
        game->board[row][col] = (rand() % 10 == 0) ? 'B' : 'A';
    }
}

// Moves and merges tiles in a row (or column)
void move_and_merge_tiles(char line[SIZE]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (line[j] != ' ') {
                if (line[i] == ' ') {
                    line[i] = line[j];
                    line[j] = ' ';
                } else if ((line[i] == line[j]) || ((line[i] == 'A' && line[j] == 'B') || (line[i] == 'B' && line[j] == 'A'))) {
                    line[i]++;
                    line[j] = ' ';
                }
                break;
            }
        }
    }
}

bool update(struct game *game, int dy, int dx) {
    // Check the correctness of the movement direction
    if ((dy != -1 && dy != 0 && dy != 1) || (dx != -1 && dx != 0 && dx != 1)) {
        return false; // Incorrect direction
    }

    // Check if we can move in the specified direction
    bool can_move = false;
    char temp_board[SIZE][SIZE];

    // Create a temporary copy of the board to check movement possibility
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temp_board[i][j] = game->board[i][j];
        }
    }

    // Move and merge tiles in each row or column depending on the direction
    if (dy == -1 || dy == 1) { // Up or down
        for (int x = 0; x < SIZE; x++) {
            char line[SIZE];
            for (int y = 0; y < SIZE; y++) {
                line[y] = (dy == -1) ? temp_board[y][x] : temp_board[SIZE - 1 - y][x];
            }
            move_and_merge_tiles(line);
            for (int y = 0; y < SIZE; y++) {
                temp_board[y][x] = (dy == -1) ? line[y] : line[SIZE - 1 - y];
            }
        }
    } else if (dx == -1 || dx == 1) { // Left or right
        for (int y = 0; y < SIZE; y++) {
            char line[SIZE];
            for (int x = 0; x < SIZE; x++) {
                line[x] = (dx == -1) ? temp_board[y][x] : temp_board[y][SIZE - 1 - x];
            }
            move_and_merge_tiles(line);
            for (int x = 0; x < SIZE; x++) {
                temp_board[y][x] = (dx == -1) ? line[x] : line[SIZE - 1 - x];
            }
        }
    }

    // Check if the board state has changed
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (game->board[i][j] != temp_board[i][j]) {
                can_move = true;
                break;
            }
        }
    }

    // If we cannot move, return false
    if (!can_move) {
        return false;
    }

    // Update the board state
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->board[i][j] = temp_board[i][j];
        }
    }

    // Generate a new tile on a random empty cell
    generate_new_tile(game);

    return true;
}

/*
void add_random_tile(struct game *game){
    int row, col;
    // find random, but empty tile
    do{
        row = rand() % SIZE;
        col = rand() % SIZE;
    }while(game->board[row][col] != ' ');

    // place to the random position 'A' or 'B' tile
    if(rand() % 2 == 0){
        game->board[row][col] = 'A';
    }else{
        game->board[row][col] = 'B';
    }
}
*/