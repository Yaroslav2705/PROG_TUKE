#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "container.h"

struct container* create_container(struct container* first, enum container_type type, void* entry) {
    // If entry is NULL or the container type is different from the type of the first container,
    // return NULL
    if (entry == NULL || (first != NULL && first->type != type)) {
        return NULL;
    }

    // Create a new container
    struct container* new_container = (struct container*)malloc(sizeof(struct container));
    if (new_container == NULL) {
        // If memory allocation fails, return NULL
        return NULL;
    }

    // Fill in the data for the new container
    new_container->type = type;
    switch (type) {
        case ROOM:
            new_container->room = (struct room*)entry;
            break;
        case ITEM:
            new_container->item = (struct item*)entry;
            break;
        case COMMAND:
            new_container->command = (struct command*)entry;
            break;
        case TEXT:
            // For TEXT, we need to allocate memory for the string and copy it
            new_container->text = strdup((char*)entry);
            break;
        default:
            // If the type is invalid, free the allocated memory and return NULL
            free(new_container);
            return NULL;
    }

    // Set the next container to NULL (the new container will be the last one)
    new_container->next = NULL;

    if (first == NULL) {
        // If the first container is NULL, the new container becomes the first one
        return new_container;
    } else {
        // Otherwise, find the end of the list and append the new container
        struct container* current = first;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_container;
        return first; // Return a reference to the first container
    }
}

struct container* destroy_containers(struct container* first) {
    while (first != NULL) {
        struct container* temp = first;
        first = first->next;

        // Free memory based on the container type
        switch (temp->type) {
            case TEXT:
                free(temp->text);
                break;
            default:
                // For other types, no special deallocation is needed
                break;
        }

        free(temp); // Free the container itself
    }
    return NULL; // Return NULL since the list is now empty
}

void* get_from_container_by_name(struct container *first, const char *name) {
    struct container* current = first;
    // Iterate through the container list
    while (current != NULL) {
        // Compare the name based on the container type
        switch (current->type) {
            case ROOM:
                if (strcmp(current->room->name, name) == 0) {
                    return current->room;
                }
                break;
            case ITEM:
                if (strcmp(current->item->name, name) == 0) {
                    return current->item;
                }
                break;
            case COMMAND:
                if (strcmp(current->command->name, name) == 0) {
                    return current->command;
                }
                break;
            case TEXT:
                if (strcmp(current->text, name) == 0) {
                    return current->text;
                }
                break;
            default:
                // No action is taken for an invalid container type
                break;
        }
        current = current->next;
    }
    return NULL; // Return NULL if the item with the given name is not found
}

struct container* remove_container(struct container *first, void *entry) {
    if (first == NULL) {
        // If the list is empty, return NULL
        return NULL;
    }

    struct container* current = first;
    struct container* previous = NULL;

    // Iterate through the list until finding the container with the given entry
    while (current != NULL) {
        // Compare the entry based on the container type
        switch (current->type) {
            case ROOM:
                if (current->room == entry) {
                    // If the container is found, remove it from the list
                    if (previous == NULL) {
                        // If the container is the first one in the list
                        first = current->next;
                    } else {
                        // Otherwise, rewire the previous container to the next one
                        previous->next = current->next;
                    }
                    // Free memory and return the updated list
                    free(current);
                    return first;
                }
                break;
            case ITEM:
                if (current->item == entry) {
                    // Similar to ROOM
                    if (previous == NULL) {
                        first = current->next;
                    } else {
                        previous->next = current->next;
                    }
                    free(current);
                    return first;
                }
                break;
            case COMMAND:
                if (current->command == entry) {
                    // Similar to ROOM
                    if (previous == NULL) {
                        first = current->next;
                    } else {
                        previous->next = current->next;
                    }
                    free(current);
                    return first;
                }
                break;
            case TEXT:
                if (current->text == entry) {
                    // Similar to ROOM, but also free the memory allocated for the text
                    if (previous == NULL) {
                        first = current->next;
                    } else {
                        previous->next = current->next;
                    }
                    free(current->text);
                    free(current);
                    return first;
                }
                break;
            default:
                // No action is taken for an invalid container type
                break;
        }
        previous = current;
        current = current->next;
    }
    return first; // Return the list unchanged if the item is not found
}

