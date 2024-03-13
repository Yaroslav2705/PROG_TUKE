#include <stdio.h>
#include <stdbool.h>
#include "k.h"
#include "ui.h"

int main{
struct game game = {
    .board = {
        {'A', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'A'},
        {'B', ' ', ' ', ' '}
    },
    .score = 0
};

printf("is won: %d\n", is_game_won(game));
printf("is move possible: %d\n", is_move_possible(game));
}