#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct item* create_item(char* name, char* description, unsigned int properties) {
    if (name == NULL || description == NULL) {
        return NULL; // Name or description is NULL
    }

    struct item* new_item = (struct item*)malloc(sizeof(struct item));
    if (new_item == NULL) {
        return NULL; // Failed to allocate memory for item
    }

    // Allocate memory and copy name and description
    new_item->name = (char*)malloc(strlen(name) + 1);
    new_item->description = (char*)malloc(strlen(description) + 1);
    if (new_item->name == NULL || new_item->description == NULL) {
        free(new_item->name);
        free(new_item->description);
        free(new_item);
        return NULL; // Failed to allocate memory for name or description
    }
    strcpy(new_item->name, name);
    strcpy(new_item->description, description);

    new_item->properties = properties;

    return new_item;
}

struct item* destroy_item(struct item* item) {
    if (item != NULL) {
        free(item->name);
        free(item->description);
        free(item);
    }
    return NULL;
}
