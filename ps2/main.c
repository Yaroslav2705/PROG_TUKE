#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "k.h"
#include "ui.h"
#include "hof.h"

int main(){
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
bool result = update(&game, 0, -1);
printf("Result: %s\n", result ? "true" : "false");

int num_loaded = load(list);

    if (num_loaded == -1) {
        printf("Ошибка при загрузке файла.\n");
        return 1;
    }

    printf("Загружено %d игроков из файла:\n", num_loaded);
    for (int i = 0; i < num_loaded; i++) {
        printf("%s - %d\n", list[i].name, list[i].score);
    }

int size = sizeof(list) / sizeof(list[0]);

    if (save(list, size)) {
        printf("Players saved successfully.\n");}}