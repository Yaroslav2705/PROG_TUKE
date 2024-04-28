#include <stdio.h>
#include "hof.h"

int load(struct player list[]) {
    FILE *file = fopen("leaderboard.txt", "r");
    if (file == NULL) {
        return -1; // Файл не удалось открыть
    }

    int count = 0;
    while (count < 10 && fscanf(file, "%s %d", list[count].name, &list[count].score) == 2) {
        count++;
    }

    fclose(file);
    return count;
}
