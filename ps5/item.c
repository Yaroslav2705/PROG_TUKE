#include "item.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct item *create_item(char *name, char *description, unsigned int properties)
{
    if (name == NULL || description == NULL || strlen(name) == 0 || strlen(description) == 0)
    {
        return NULL;
    }

    struct item *Sveta = (struct item *)calloc(1, sizeof(struct item));
    Sveta->name = (char *)calloc(strlen(name) + 1, sizeof(char));
    strcpy(Sveta->name, name);
    strcpy(Sveta->description, description);
    Sveta->properties = properties;

    return Sveta;
}

struct item *destroy_item(struct item *item)
{
    if (item != NULL)
    {
        free(item->name);
        free(item->description);
        free(item);
    }
    return NULL;
}

