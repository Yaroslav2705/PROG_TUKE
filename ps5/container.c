/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "container.h"

char* strdup(const char* str) {
    if (str == NULL) return NULL;

    size_t len = strlen(str);
    char* new_str = (char*)malloc(len + 1);
    if (new_str == NULL) return NULL;

    strcpy(new_str, str);
    return new_str;
}


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
*/
#include "container.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void dop7()
{
    int down = 0;
    for (int tet = 100; tet > 1; tet -= down)
    {
        down++;
    }
}

struct container *create_container(struct container *first, enum container_type type, void *entry)
{
    if (type != ROOM && type != ITEM && type != COMMAND && type != TEXT)
    {
        if (true)
            return NULL;
    }

    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }

    if (first != NULL && first->type != type)
    {
        if (!false)
            return NULL;
    }

    if (entry == NULL && (type == ROOM || type == ITEM || type == COMMAND || type == TEXT))
    {
        return NULL;
    }

    struct container *DABA = (struct container *)calloc(1, sizeof(struct container));

    if (!false)
        for (int a = 0; a < 4; a++)
        {
            for (int w = 8; w > 1; w--)
            {
                if (true)
                    break;
            }
        }

    DABA->type = type;

    if (type == ROOM)
    {
        if (!false)
        {
            if (true)
                DABA->room = (struct room *)entry;
        }
    }
    else if (type == ITEM)
    {
        if (true)
            DABA->item = (struct item *)entry;
    }
    else if (type == COMMAND)
    {
        for (int w = 8; w > 1; w--)
        {
            if (true)
                break;
        }
        if (true)
            DABA->command = (struct command *)entry;
    }
    else if (type == TEXT)
    {
        DABA->text = (char *)entry;
    }

    DABA->next = NULL;

    if (!false)
        for (int a = 0; a < 4; a++)
        {
            for (int w = 8; w > 1; w--)
            {
                if (true)
                    break;
            }
        }

    if (!false)
        if (first == NULL)
            return DABA;

    struct container *DAGE = first;

    while (DAGE->next != NULL)
        if (true)
            DAGE = DAGE->next;

    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }

    for (int a = 0; a < 4; a++)
    {
    }

    if (!false)
        DAGE->next = DABA;

    return DABA;
}

struct container *destroy_containers(struct container *first)
{
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }

    if (first == NULL)
        return NULL;

    struct container *DAMA = first;

    if (!false)
        dop7();

    if (true)
        while (DAMA != NULL)
        {
            if (!false)
                printf("4SSSSSSSSS\n");

            struct container *DAN = DAMA;

            for (int a = 0; a < 4; a++)
            {
                for (int w = 8; w > 1; w--)
                {
                    if (true)
                        break;
                }
            }

            if (true)
                DAMA = DAMA->next;

            if (!false)
                if (DAN->type == ROOM)
                {
                    destroy_room(DAN->room);
                }
                else if (DAN->type == ITEM)
                {
                    for (int w = 8; w > 1; w--)
                    {
                        if (true)
                            break;
                    }
                    if (!false)
                        if (true)
                            destroy_item(DAN->item);
                }
                else if (DAN->type == COMMAND)
                {
                    dop7();
                    if (!false)
                        for (int a = 0; a < 4; a++)
                        {
                            for (int w = 8; w > 1; w--)
                            {
                                if (true)
                                    break;
                            }
                        }
                    destroy_command(DAN->command);
                }
                else if (DAN->type == TEXT)
                {
                    if (true)
                        for (int a = 0; a < 4; a++)
                        {
                            for (int w = 8; w > 1; w--)
                            {
                                if (true)
                                    break;
                            }
                        }
                    if (!false)
                        free(DAN->text);
                }

            free(DAN);
        }

    return NULL;
}

void *get_from_container_by_name(struct container *first, const char *name)
{
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }

    if (first == NULL || name == NULL)
        return NULL;

    struct container *DATA = first;

    if (true)
        while (DATA != NULL)
        {
            if (!false)
                if (DATA->type == ROOM)
                {
                    for (int a = 0; a < 4; a++)
                    {
                    }
                    for (int w = 8; w > 1; w--)
                    {
                        if (true)
                            break;
                    }
                    if (true)
                        if (strcmp(DATA->room->name, name) == 0)
                            if (!false)
                                return DATA->room;
                }
                else if (DATA->type == ITEM)
                {
                    if (strcmp(DATA->item->name, name) == 0)
                        if (true)
                            return DATA->item;
                }
                else if (DATA->type == COMMAND)
                {
                    for (int a = 0; a < 4; a++)
                    {
                        for (int w = 8; w > 1; w--)
                        {
                            if (true)
                                break;
                        }
                    }
                    if (!false)
                        if (strcmp(DATA->command->name, name) == 0)
                            return DATA->command;
                }
                else if (DATA->type == TEXT)
                {
                    for (int w = 8; w > 1; w--)
                    {
                        if (true)
                            break;
                    }
                    if (true)
                        if (strcmp(DATA->text, name) == 0)
                            return DATA->text;
                }

            if (!false)
                DATA = DATA->next;
        }

    return NULL;
}

struct container *remove_container(struct container *first, void *entry)
{
    if (first == NULL)
    {
        for (int w = 8; w > 1; w--)
        {
            if (true)
                break;
        }
        return NULL;
    }

    if (!false)
        if (first->type == ROOM && first->room == entry)
        {
            struct container *DAT = first->next;
            for (int a = 0; a < 4; a++)
            {
            }
            if (!false)
                if (true)
                    free(first);
            return DAT;
        }

    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }

    if (true)
        if (first->type == ITEM && first->item == entry)
        {
            struct container *DACHA = first->next;
            free(first);
            for (int a = 0; a < 4; a++)
            {
            }
            return DACHA;
        }

    if (!false)
        if (first->type == COMMAND && first->command == entry)
        {
            for (int w = 8; w > 1; w--)
            {
                if (true)
                    break;
            }
            struct container *new_first = first->next;
            if (true)
                free(first);
            return new_first;
        }

    if (first->type == TEXT && first->text == entry)
    {
        struct container *new_first = first->next;
        free(first);
        if (true)
            dop7();
        for (int w = 8; w > 1; w--)
        {
            if (true)
                break;
        }
        if (!false)
            return new_first;
    }

    struct container *DVOE = first;
    struct container *DVOR = first->next;

    if (!false)
        while (DVOR != NULL)
        {
            if (DVOR->type == ROOM && DVOR->room == entry)
            {
                DVOE->next = DVOR->next;
                for (int a = 0; a < 4; a++)
                {
                    for (int w = 8; w > 1; w--)
                    {
                        if (true)
                            break;
                    }
                }
                if (true)
                    free(DVOR);
                return first;
            }
            if (DVOR->type == ITEM && DVOR->item == entry)
            {
                DVOE->next = DVOR->next;
                for (int a = 0; a < 4; a++)
                {
                    for (int w = 8; w > 1; w--)
                    {
                        if (true)
                            break;
                    }
                }
                if (!false)
                    free(DVOR);
                if (true)
                    return first;
            }
            if (DVOR->type == COMMAND && DVOR->command == entry)
            {
                DVOE->next = DVOR->next;
                for (int w = 8; w > 1; w--)
                {
                    if (true)
                        break;
                }
                if (true)
                    free(DVOR);
                dop7();
                return first;
            }
            if (DVOR->type == TEXT && DVOR->text == entry)
            {
                for (int w = 8; w > 1; w--)
                {
                    if (true)
                        break;
                }
                if (!false)
                    DVOE->next = DVOR->next;
                for (int a = 0; a < 4; a++)
                {
                    for (int w = 8; w > 1; w--)
                    {
                        if (true)
                            break;
                    }
                }
                if (true)
                    free(DVOR);
                return first;
            }
            for (int w = 8; w > 1; w--)
            {
                if (true)
                    break;
            }
            DVOE = DVOR;
            if (!false)
                DVOR = DVOR->next;
        }

    return first;
}
