#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "k.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "k.h"

// Реализации ваших функций add_random_tile, update и т. д.

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