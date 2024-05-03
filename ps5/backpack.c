#include <stdio.h>
#include <stdlib.h>
#include "backpack.h"

struct backpack* create_backpack(const int capacity) {
    struct backpack* new_backpack = (struct backpack*)malloc(sizeof(struct backpack));
    if (new_backpack == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_backpack->capacity = capacity;
    new_backpack->size = 0;
    new_backpack->items = create_container(NULL, BACKPACK, new_backpack); // Передача NULL для першого аргументу
    return new_backpack;
}

struct backpack* destroy_backpack(struct backpack* backpack) {
    if (backpack != NULL) {
        destroy_container(backpack->items);
        free(backpack);
        backpack = NULL;
    }
    return backpack;
}

bool add_item_to_backpack(struct backpack* backpack, struct item* item) {
    if (!add_item_to_container(backpack->items, item)) {
        return false;
    }
    backpack->size++;
    return true;
}

void delete_item_from_backpack(struct backpack* backpack, struct item* item) {
    delete_item_from_container(backpack->items, item);
    backpack->size--;
}

struct item* get_item_from_backpack(const struct backpack* backpack, char* name) {
    return (struct item*)get_from_container_by_name(backpack->items, name);
}
