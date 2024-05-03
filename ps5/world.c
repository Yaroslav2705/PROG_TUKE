#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "world.h"

struct container* create_world() {
    return create_container();
}

struct container* add_room_to_world(struct container* world, struct room* room) {
    if (room == NULL) {
        return NULL; // Room is NULL
    }

    if (world == NULL) {
        world = create_container();
        if (world == NULL) {
            return NULL; // Failed to create world
        }
    }

    // Check if room name is unique
    if (get_room(world, room->name) != NULL) {
        return NULL; // Room with the same name already exists in the world
    }

    // Add room to the world
    return add_to_container(world, room);
}

struct container* destroy_world(struct container* world) {
    if (world != NULL) {
        destroy_containers(world);
    }
    return NULL;
}

struct room* get_room(struct container* world, char* name) {
    if (world == NULL || name == NULL) {
        return NULL;
    }

    struct node* current = world->head;
    while (current != NULL) {
        struct room* room = (struct room*)current->data;
        if (strcmp(room->name, name) == 0) {
            return room;
        }
        current = current->next;
    }

    return NULL; // Room not found
}
