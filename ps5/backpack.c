#include <stdlib.h>
#include "backpack.h"

struct backpack* create_backpack(const int capacity) {
    struct backpack* new_backpack = (struct backpack*)malloc(sizeof(struct backpack));
    if (new_backpack != NULL) {
        new_backpack->capacity = capacity;
        new_backpack->size = 0;
        // Create a container for the backpack
        new_backpack->items = create_container(NULL, CONTAINER_TYPE_BACKPACK, new_backpack); // Используем CONTAINER_TYPE_BACKPACK вместо BACKPACK
        if (new_backpack->items == NULL) {
            // Failed to create container, free the allocated memory
            free(new_backpack);
            new_backpack = NULL;
        }
    }
    return new_backpack;
}

struct backpack* destroy_backpack(struct backpack* backpack) {
    if (backpack != NULL) {
        // Destroy the container
        destroy_container(backpack->items);
        // Free the backpack itself
        free(backpack);
    }
    return NULL;
}

bool add_item_to_backpack(struct backpack* backpack, struct item* item) {
    if (backpack != NULL && backpack->size < backpack->capacity) {
        // Create a container for the item
        struct container* container = create_container(backpack->items, CONTAINER_TYPE_ITEM, item); // Используем CONTAINER_TYPE_ITEM вместо ITEM
        if (container != NULL) {
            backpack->items = container;
            backpack->size++;
            return true;
        }
    }
    return false;
}

void delete_item_from_backpack(struct backpack* backpack, struct item* item) {
    if (backpack != NULL && backpack->items != NULL) {
        struct container* current = backpack->items;
        struct container* prev = NULL;
        while (current != NULL) {
            if (current->type == CONTAINER_TYPE_ITEM && current->data == item) { // Заменяем data на entry
                if (prev == NULL) {
                    backpack->items = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                backpack->size--;
                break;
            }
            prev = current;
            current = current->next;
        }
    }
}

struct item* get_item_from_backpack(const struct backpack* backpack, char* name) {
    if (backpack != NULL && backpack->items != NULL) {
        struct container* current = backpack->items;
        while (current != NULL) {
            if (current->type == CONTAINER_TYPE_ITEM && strcmp(((struct item*)current->data)->name, name) == 0) {
                return current->data;
            }
            current = current->next;
        }
    }
    return NULL;
}
