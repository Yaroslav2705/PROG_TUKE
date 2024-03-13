#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "k.h"

struct game {
        char board[4][4];
        char score;
};

bool is_game_won(const struct game game){
        for(int kak = 0; kak < 4; kak++){
                for(int kok = 0; kok < 4; kok++){
                        if(game.board[kak][kok] == 'K')
                                return true;
                }
        }
        return false;
}

bool is_move_possible(const struct game game){
        for(int kak = 0; kak < 3; kak++){
                for(int kok = 0; kok < 3; kok++){
                        if(game.board[kak][kok] == ' ')
                                return true;

                        if(game.board[kak][kok] == game.board[kak+1][kok] || game.board[kak][kok] == game.board[kak][kok+1])
                                return true;
                }
        }

        for(int kik = 0; kik < 3; kik++){
                if(game.board[3][kik] == ' ' || game.board[kik][3] == ' ')
                        return true;

                if(game.board[3][kik] == game.board[3][kik+1] || game.board[kik][3] == game.board[kik+1][3])
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