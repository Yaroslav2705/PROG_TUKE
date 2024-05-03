#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "room.h"

struct room* create_room(char *name, char *description) {
    if (name == NULL || description == NULL) {
        return NULL; // Room cannot be created without name or description
    }

    struct room* new_room = (struct room*)malloc(sizeof(struct room));
    if (new_room == NULL) {
        return NULL; // Memory allocation failed
    }

    new_room->name = strdup(name);
    new_room->description = strdup(description);
    new_room->north = NULL;
    new_room->south = NULL;
    new_room->east = NULL;
    new_room->west = NULL;
    new_room->items = NULL;

    return new_room;
}

struct room* destroy_room(struct room* room) {
    if (room != NULL) {
        free(room->name);
        free(room->description);
        // Free items in the room
        destroy_containers(room->items);
        free(room);
    }
    return NULL;
}

void set_exits_from_room(struct room *room, struct room *north, struct room *south, struct room *east, struct room *west) {
    if (room != NULL) {
        room->north = north;
        room->south = south;
        room->east = east;
        room->west = west;
    }
}

void show_room(const struct room* room) {
    if (room != NULL) {
        printf("%s\n", room->description);
        printf("Mozne vychody z miesnosti:\n");
        if (room->north != NULL) printf("    sever\n");
        if (room->south != NULL) printf("    juh\n");
        if (room->east != NULL) printf("    vychod\n");
        if (room->west != NULL) printf("    zapad\n");

        printf("Vidíš:\n");
        struct container* current_item = room->items;
        while (current_item != NULL) {
            printf("    %s\n", ((struct item*)(current_item->item))->name);
            current_item = current_item->next;
        }
    }
}

void delete_item_from_room(struct room* room, struct item* item) {
    if (room != NULL && item != NULL) {
        room->items = remove_container(room->items, item);
    }
}

void add_item_to_room(struct room* room, struct item* item) {
    if (room != NULL && item != NULL) {
        room->items = create_container(room->items, ITEM, item);
    }
}

struct item* get_item_from_room(const struct room* room, const char* name) {
    if (room != NULL && name != NULL) {
        struct container* current_item = room->items;
        while (current_item != NULL) {
            struct item* item = (struct item*)(current_item->item);
            if (strcasecmp(item->name, name) == 0) {
                return item;
            }
            current_item = current_item->next;
        }
    }
    return NULL;
}
