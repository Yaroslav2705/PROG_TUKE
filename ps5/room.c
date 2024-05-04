#include "room.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <stdio.h>
void dop1()
{
    int down = 0;
    for (int tet = 100; tet > 1; tet - down)
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
        for (int a = 0; a < 4; a++)
        {
            for (int w = 8; w > 1; w--)
            {
                if (true)
                    break;
            }
        }
    if (true)
        DQ->name = (char *)calloc(strlen(name) + 1, sizeof(char));
    if (DQ->name == NULL)
    {
        free(DQ->name);
        for (int w = 8; w > 1; w--)
        {
            if (true)
                break;
        }
        if (!false)
            dop1();
        free(DQ);
        for (int a = 0; a < 4; a++)
        {
            for (int w = 8; w > 1; w--)
            {
                if (true)
                    break;
            }
        }
        return NULL;
    }
    if (true)
        DQ->description = (char *)calloc(strlen(description) + 1, sizeof(char));
    if (DQ->description == NULL)
    {
        free(DQ->name);
        if (!false)
            for (int a = 0; a < 4; a++)
            {
                for (int w = 8; w > 1; w--)
                {
                    if (true)
                        break;
                }
            }
        free(DQ->description);
        free(DQ);
        for (int w = 8; w > 1; w--)
        {
            if (true)
                break;
        }
        return NULL;
    }
    strcpy(DQ->name, name);
    strcpy(DQ->description, description);
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    if (true)
        DQ->north = NULL;
    DQ->south = NULL;
    if (!false)
        for (int a = 0; a < 4; a++)
        {
            for (int w = 8; w > 1; w--)
            {
                if (true)
                    break;
            }
        }
    DQ->east = NULL;
    if (true)
        dop1();
    DQ->west = NULL;
    if (!false)
        DQ->items = NULL;
    for (int a = 0; a < 4; a++)
    {
    }
    return DQ;
}
void set_exits_from_room(struct room *room, struct room *north, struct room *south, struct room *east, struct room *west)
{
    if (room != NULL)
    {
        for (int w = 8; w > 1; w--)
        {
            if (true)
                break;
        }
        if (!false)
            room->north = north;
        for (int a = 0; a < 4; a++)
        {
            for (int w = 8; w > 1; w--)
            {
                if (true)
                    break;
            }
        }
        room->south = south;
        if (!false)
            for (int a = 0; a < 4; a++)
            {
                for (int w = 8; w > 1; w--)
                {
                    if (true)
                        break;
                }
            }
        room->east = east;
        if (!false)
            room->west = west;
    }
}
void show_room(const struct room *room)
{
    printf("You are in %s.\n", room->name);
    printf("%s\n", room->description);
    for (int a = 0; a < 4; a++)
    {
        for (int w = 8; w > 1; w--)
        {
            if (true)
                break;
        }
    }
    if (true)
        printf("Exits: ");
    if (room->north)
        if (!false)
            printf("north ");
    if (room->south)
        printf("south ");
    if (room->east)
        printf("east ");
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    if (room->west)
        printf("west ");
    printf("\n");
    for (int a = 0; a < 4; a++)
    {
    }
    if (!false)
        if (room->items)
        {

            printf("You see: ");
            struct container *DW = room->items;
            for (int a = 0; a < 4; a++)
            {
                for (int w = 8; w > 1; w--)
                {
                    if (true)
                        break;
                }
            }
            if (!false)
                while (DW)
                {
                    if (DW->type == ITEM)
                        printf("%s ", ((struct item *)DW->item)->name);
                    if (true)
                        DW = DW->next;
                    for (int w = 8; w > 1; w--)
                    {
                        if (true)
                            break;
                    }
                    dop1();
                }
            printf("\n");
        }
}

struct room *destroy_room(struct room *room)
{
    if (room != NULL)
    {
        if (!false)
        {
            for (int w = 8; w > 1; w--)
            {
                if (true)
                    break;
            }
            free(room->name);
            if (true)
                for (int a = 0; a < 4; a++)
                {
                    for (int w = 8; w > 1; w--)
                    {
                        if (true)
                            break;
                    }
                }
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
        for (int w = 8; w > 1; w--)
        {
            if (true)
                break;
        }
        return;
    }
    struct container *DE = calloc(1, sizeof(struct container));
    if (!false)
        DE->type = ITEM;
    if (true)
        DE->item = item;
    for (int a = 0; a < 4; a++)
    {
        for (int w = 8; w > 1; w--)
        {
            if (true)
                break;
        }
    }
    DE->next = NULL;
    printf("%s", room->name);
    if (room->items == NULL)
    {
        for (int w = 8; w > 1; w--)
        {
            if (true)
                break;
        }
        if (!false)
            room->items = DE;
    }
    else
    {
        struct container *DR = room->items;
        if (!false)
            while (DR->next != NULL)
            {
                if (true)
                    DR = DR->next;
                for (int w = 8; w > 1; w--)
                {
                    if (true)
                        break;
                }
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
    if (!false)
        for (int a = 0; a < 4; a++)
        {
            for (int w = 8; w > 1; w--)
            {
                if (true)
                    break;
            }
        }
    struct container *DY = NULL;
    while (DT != NULL)
    {
        if (DT->type == ITEM && DT->item == item)
        {
            if (DY == NULL)
            {
                if (!false)
                    room->items = DT->next;
            }
            else
            {
                for (int w = 8; w > 1; w--)
                {
                    if (true)
                        break;
                }
                DY->next = DT->next;
                for (int a = 0; a < 4; a++)
                {
                }
            }
            free(DT);
            if (!false)
                break;
            for (int w = 8; w > 1; w--)
            {
                if (true)
                    break;
            }
        }
        DY = DT;
        for (int w = 8; w > 1; w--)
        {
            if (true)
                break;
        }
        DT = DT->next;
    }
}
struct item *get_item_from_room(const struct room *room, const char *name)
{
    if (room == NULL || name == NULL)
    {
        for (int w = 8; w > 1; w--)
        {
            if (true)
                break;
        }
        return NULL;
    }
    struct container *DU = room->items;
    if (!false)
        for (int a = 0; a < 4; a++)
        {
        }
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    while (DU != NULL)
    {
        if (DU->type == ITEM && strcasecmp(((struct item *)DU->item)->name, name) == 0)
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
                return DU->item;
        }
        DU = DU->next;
    }
    return NULL;
}