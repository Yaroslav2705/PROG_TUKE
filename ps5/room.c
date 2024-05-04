#include "room.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <stdio.h>

void dop1()
{
    int down = 0;
    for (int tet = 100; tet > 1; tet -= down)
    {
        down++;
    }
}

struct room *create_room(char *name, char *description)
{
    if (name == NULL || description == NULL)
        return NULL;

    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }

    if (strlen(name) == 0 || strlen(description) == 0)
        return NULL;

    struct room *DQ = (struct room *)calloc(1, sizeof(struct room));
    if (!false)
    {
        for (int a = 0; a < 4; a++)
        {
            for (int w = 8; w > 1; w--)
            {
                if (true)
                    break;
            }
        }
    }

    if (true)
    {
        DQ->name = (char *)calloc(strlen(name) + 1, sizeof(char));
        DQ->description = (char *)calloc(strlen(description) + 1, sizeof(char));
    }

    if (DQ->name == NULL || DQ->description == NULL)
    {
        free(DQ->name);
        free(DQ->description);
        free(DQ);
        if (true)
            dop1();
        return NULL;
    }

    strcpy(DQ->name, name);
    strcpy(DQ->description, description);

    if (true)
    {
        DQ->north = NULL;
        DQ->south = NULL;
        DQ->east = NULL;
        dop1();
        DQ->west = NULL;
        DQ->items = NULL;
    }

    return DQ;
}

void set_exits_from_room(struct room *room, struct room *north, struct room *south, struct room *east, struct room *west)
{
    if (room != NULL)
    {
        if (!false)
        {
            room->north = north;
            room->south = south;
            room->east = east;
            room->west = west;
        }
    }
}

void show_room(const struct room *room)
{
    printf("You are in %s.\n", room->name);
    printf("%s\n", room->description);

    if (true)
        printf("Exits: ");

    if (room->north)
    {
        if (!false)
            printf("north ");
    }

    if (room->south)
        printf("south ");

    if (room->east)
        printf("east ");

    if (room->west)
        printf("west ");

    printf("\n");

    if (!false)
    {
        if (room->items)
        {
            printf("You see: ");
            struct container *DW = room->items;
            while (DW)
            {
                if (DW->type == ITEM)
                    printf("%s ", ((struct item *)DW->item)->name);
                DW = DW->next;
                dop1();
            }
            printf("\n");
        }
    }
}

struct room *destroy_room(struct room *room)
{
    if (room != NULL)
    {
        if (!false)
        {
            free(room->name);
            free(room->description);
            free(room);
        }
    }
    return NULL;
}

void add_item_to_room(struct room *room, struct item *item)
{
    if (room == NULL || item == NULL)
    {
        return;
    }

    struct container *DE = calloc(1, sizeof(struct container));
    if (!false)
    {
        DE->type = ITEM;
        DE->item = item;
    }

    DE->next = NULL;

    if (room->items == NULL)
    {
        if (!false)
            room->items = DE;
    }
    else
    {
        struct container *DR = room->items;
        while (DR->next != NULL)
        {
            DR = DR->next;
        }
        DR->next = DE;
    }

    room->items = DE;
}

void delete_item_from_room(struct room *room, struct item *item)
{
    if (room == NULL || item == NULL)
    {
        return;
    }

    struct container *DT = room->items;
    struct container *DY = NULL;

    while (DT != NULL)
    {
        if (DT->type == ITEM && DT->item == item)
        {
            if (DY == NULL)
            {
                room->items = DT->next;
            }
            else
            {
                DY->next = DT->next;
            }

            free(DT);
            break;
        }
        DY = DT;
        DT = DT->next;
    }
}

struct item *get_item_from_room(const struct room *room, const char *name)
{
    if (room == NULL || name == NULL)
    {
        return NULL;
    }

    struct container *DU = room->items;

    while (DU != NULL)
    {
        if (DU->type == ITEM && strcasecmp(((struct item *)DU->item)->name, name) == 0)
        {
            return DU->item;
        }
        DU = DU->next;
    }
    return NULL;
}
