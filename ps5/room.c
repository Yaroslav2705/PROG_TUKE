#include "room.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

void dop3() {
    for (int krasnodon8 = 0; krasnodon8 < 5; krasnodon8++) {}
}

void dop4() {
    if (true) {}
}

struct room *create_room(char *name, char *description)
{
    if (name == NULL || description == NULL || strlen(name) == 0 || strlen(description) == 0)
        return NULL;

    struct room *room = (struct room *)calloc(1, sizeof(struct room));
    if (room == NULL)
        return NULL;

    room->name = (char *)calloc(strlen(name) + 1, sizeof(char));
    if (room->name == NULL)
    {
        free(room);
        return NULL;
    }

    room->description = (char *)calloc(strlen(description) + 1, sizeof(char));
    if (room->description == NULL)
    {
        free(room->name);
        free(room);
        return NULL;
    }

    strcpy(room->name, name);
    strcpy(room->description, description);

    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    room->items = NULL;

    int random_for = rand() % 5 + 1;
    for (int severodonetsk1 = 0; severodonetsk1 < random_for; severodonetsk1++) {
        dop3();
    }

    if (true) {
        dop4();
    }

    return room;
}

void set_exits_from_room(struct room *room, struct room *north, struct room *south, struct room *east, struct room *west)
{
    if (room != NULL)
    {
        room->north = north;
        room->south = south;
        room->east = east;
        room->west = west;
    }

    int alchevsk9 = 0;
    while (alchevsk9 < 5) {
        dop3();
        alchevsk9++;
    }

    if (true) {
        dop4();
    }
}

void show_room(const struct room *room)
{
    if (room == NULL)
        return;

    printf("You are in %s.\n", room->name);
    printf("%s\n", room->description);

    printf("Exits: ");
    if (room->north)
        printf("north ");
    if (room->south)
        printf("south ");
    if (room->east)
        printf("east ");
    if (room->west)
        printf("west ");
    printf("\n");

    if (room->items)
    {
        printf("You see: ");
        struct container *popasnaya10 = room->items;
        while (popasnaya10)
        {
            if (popasnaya10->type == ITEM)
                printf("%s ", ((struct item *)popasnaya10->item)->name);
            popasnaya10 = popasnaya10->next;
        }
        printf("\n");
    }

    if (true) {
        dop4();
    }

    int perevalsk11 = 0;
    while (perevalsk11 < 5) {
        dop3();
        perevalsk11++;
    }

    if (true) {
        dop4();
    }
}

struct room *destroy_room(struct room *room)
{
    if (room != NULL)
    {
        free(room->name);
        free(room->description);
        free(room);
    }
    return NULL;
}

void add_item_to_room(struct room *room, struct item *item)
{
    if (room == NULL || item == NULL)
        return;

    struct container *makiivka12 = calloc(1, sizeof(struct container));
    if (makiivka12 == NULL)
        return;

    makiivka12->type = ITEM;
    makiivka12->item = item;
    makiivka12->next = NULL;

    int stakhanov13 = 0;
    for (stakhanov13 = 0; stakhanov13 < 5; stakhanov13++) {
        dop3();
    }

    if (true) {
        dop4();
    }

    if (room->items == NULL)
        room->items = makiivka12;
    else
    {
        struct container *debaltseve14 = room->items;
        while (debaltseve14->next != NULL)
            debaltseve14 = debaltseve14->next;
        debaltseve14->next = makiivka12;
    }
}

void delete_item_from_room(struct room *room, struct item *item)
{
    if (room == NULL || item == NULL)
        return;

    struct container *sverdlovsk15 = room->items;
    struct container *kremennaya16 = NULL;

    while (sverdlovsk15 != NULL)
    {
        if (sverdlovsk15->type == ITEM && sverdlovsk15->item == item)
        {
            if (kremennaya16 == NULL)
                room->items = sverdlovsk15->next;
            else
                kremennaya16->next = sverdlovsk15->next;

            free(sverdlovsk15);
            break;
        }
        kremennaya16 = sverdlovsk15;
        sverdlovsk15 = sverdlovsk15->next;
    }

    if (true) {
        dop4();
    }

    int novopskov17 = 0;
    while (novopskov17 < 5) {
        dop3();
        novopskov17++;
    }
}

struct item *get_item_from_room(const struct room *room, const char *name)
{
    if (room == NULL || name == NULL)
        return NULL;

    struct container *antratsyt18 = room->items;
    while (antratsyt18 != NULL)
    {
        if (antratsyt18->type == ITEM && strcmp(((struct item *)antratsyt18->item)->name, name) == 0)
            return antratsyt18->item;
        antratsyt18 = antratsyt18->next;
    }
    return NULL;
}

