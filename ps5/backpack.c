#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "backpack.h"

struct backpack* create_backpack(const int capacity) {
    struct backpack* new_backpack = (struct backpack*)malloc(sizeof(struct backpack));
    if (new_backpack == NULL) {
        return NULL; // Failed to allocate memory for backpack
    }

    new_backpack->capacity = capacity;
    new_backpack->size = 0;

    // Create container for items in the backpack
    new_backpack->items = create_container();
    if (new_backpack->items == NULL) {
        free(new_backpack);
        return NULL; // Failed to create container for items
    }

    return new_backpack;
}

struct backpack* destroy_backpack(struct backpack* backpack) {
    if (backpack != NULL) {
        // Destroy container and items
        destroy_container(backpack->items);
        free(backpack);
    }
    return NULL;
}

bool add_item_to_backpack(struct backpack* backpack, struct item* item) {
    if (backpack == NULL || item == NULL) {
        return false; // Invalid backpack or item
    }

    if (backpack->size >= backpack->capacity) {
        return false; // Backpack is full
    }

    // Add item to the container
    if (!add_item_to_container(backpack->items, item)) {
        return false; // Failed to add item to the container
    }

    backpack->size++; // Increase the size of the backpack
    return true;
}

void delete_item_from_backpack(struct backpack* backpack, struct item* item) {
    if (backpack == NULL || item == NULL) {
        return; // Invalid backpack or item
    }

    // Remove item from the container
    delete_item_from_container(backpack->items, item);
    backpack->size--; // Decrease the size of the backpack
}

struct item* get_item_from_backpack(const struct backpack* backpack, char* name) {
    if (backpack == NULL || name == NULL) {
        return NULL; // Invalid backpack or name
    }

    // Search for item in the container
    return get_item_from_container(backpack->items, name);
}
