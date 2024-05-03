#include <stdlib.h>
#include "backpack.h"
#include "container.h"

struct backpack* create_backpack(const int capacity) {
    struct backpack* new_backpack = (struct backpack*)malloc(sizeof(struct backpack));
    if (new_backpack != NULL) {
        new_backpack->capacity = capacity;
        new_backpack->items = create_container(NULL, CONTAINER_TYPE_BACKPACK, new_backpack); // Используем CONTAINER_TYPE_BACKPACK вместо BACKPACK
    }
    return new_backpack;
}

void destroy_backpack(struct backpack* backpack) {
    if (backpack != NULL) {
        destroy_containers(backpack->items);
        free(backpack);
    }
}

bool add_item_to_backpack(struct backpack* backpack, struct item* item) {
    if (backpack != NULL && item != NULL) {
        struct container* container = create_container(backpack->items, CONTAINER_TYPE_ITEM, item); // Используем CONTAINER_TYPE_ITEM вместо ITEM
        if (container != NULL) {
            backpack->items = container;
            return true;
        }
    }
    return false;
}

void delete_item_from_backpack(struct backpack* backpack, struct item* item) {
    if (backpack != NULL && item != NULL) {
        struct container* current = backpack->items;
        struct container* prev = NULL;

        while (current != NULL) {
            if (current->type == CONTAINER_TYPE_ITEM && current->entry == item) { // Заменяем data на entry
                if (prev == NULL) {
                    backpack->items = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                break;
            }
            prev = current;
            current = current->next;
        }
    }
}

struct item* get_item_from_backpack(const struct backpack* backpack, char* name) {
    if (backpack != NULL && name != NULL) {
        return (struct item*)get_from_container_by_name(backpack->items, name);
    }
    return NULL;
}
