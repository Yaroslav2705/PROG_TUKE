#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "hof.h"

int load(struct player list[]) {
    FILE *file = fopen("score", "r");
    if (file == NULL) {
        //printf("Error opening file.\n");
        return -1; // Return -1 to indicate error
    }

    int count = 0;
    while (count < 10 && fscanf(file, "%s %d", list[count].name, &list[count].score) == 2) {
        count++;
    }

    fclose(file);

    // sort
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (list[i].score < list[j].score) {
                // Обмен местами
                struct player temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    return count; // Return the number of loaded players
}

bool save(const struct player list[], const int size) {
    FILE *file = fopen("score.txt", "w");
    if (file == NULL) {
        //printf("Error opening file.\n");
        return false; // Return false to indicate failure
    }

    // Write players to file
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %d\n", list[i].name, list[i].score);
    }

    fclose(file);
    return true; // Return true to indicate success
}

/*

bool add_player(struct player list[], int *size, const struct player new_player) {
    // Find the insertion index
    int insert_index = *size;
    for (int i = 0; i < *size; i++) {
        if (new_player.score >= list[i].score) {
            insert_index = i;
            break;
        }
    }

    // Shift players to the right to make room for the new player
    for (int i = *size; i > insert_index; i--) {
        list[i] = list[i - 1];
    }

    // Copy the data of the new player to the correct position in the list
    list[insert_index] = new_player;

    // Increase the size of the list
    (*size)++;

    // If the size exceeds 10, remove the last player
    if (*size > 10) {
        (*size)--;
    }

    // Save the changes to the file
    bool saved = save(list, *size);

    if (!saved && *size == 10 && new_player.score > list[9].score) {
    return false;
}


    return true;
}*/

bool add_player(struct player list[], int *size, const struct player new_player) {
    // Find the insertion index
    int insert_index = *size;
    for (int i = 0; i < *size; i++) {
        if (new_player.score >= list[i].score) {
            insert_index = i;
            break;
        }
    }

    // If the list is full and the new player has a score lower than
    // the last player in the list, return false without modifying the list
    if (*size == 10 && new_player.score <= list[9].score) {
        return false;
    }

    // Shift players to the right to make room for the new player
    for (int i = *size - 1; i >= insert_index; i--) {
        list[i + 1] = list[i];
    }

    // Copy the data of the new player to the correct position in the list
    list[insert_index] = new_player;

    // Increase the size of the list
    (*size)++;

    // If the size exceeds 10, remove the last player
    if (*size > 10) {
        (*size)--;
    }

    // Save the changes to the file
    bool saved = save(list, *size);

    return saved;
}

