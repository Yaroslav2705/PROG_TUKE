#include <stdio.h>
#include <string.h>
#include "hof.h"

int load(struct player list[]) {
    FILE *file = fopen("score.txt", "r");
    if (file == NULL) {
        //printf("Error opening file.\n");
        return -1; // Return -1 to indicate error
    }

    int count = 0;
    while (fscanf(file, "%s %d", list[count].name, &list[count].score) == 2) {
        count++;
        if (count >= 10) // Check if we've reached the maximum number of players
            break;
    }

    fclose(file);

    // Sorting the list of players
    struct player temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (list[j].score < list[j + 1].score) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    return count; // Return the number of loaded players
}