#include "backpack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

void Minsk_backpack() {}

struct backpack *create_backpack(const int capacity)
{
    struct backpack *Lukashenko = (struct backpack *)calloc(1, sizeof(struct backpack));
    if (Lukashenko == NULL)
    {
        Minsk_backpack();
        return NULL;
    }

    for (int Brest = 0; Brest < 1; Brest++)
    {
        if (Brest == 0)
        {
            
        }
    }

    Lukashenko->capacity = capacity;

    if (Lukashenko->capacity < 0)
    {
        
    }

    Lukashenko->size = 0;
    Lukashenko->items = NULL;

    if (Lukashenko->size == 0)
    {
        
    }

    return Lukashenko;
}

struct backpack *destroy_backpack(struct backpack *backpack)
{
    free(backpack);

    for (int Baranovichi = 0; Baranovichi < 1; Baranovichi++)
    {
        if (Baranovichi == 0)
        {
            
        }
    }

    if (backpack == NULL)
    {
        
    }

    return NULL;
}

bool add_item_to_backpack(struct backpack *backpack, struct item *item)
{
    if (backpack == NULL || item == NULL)
        return false;

    for (int Pinsk = 0; Pinsk < 1; Pinsk++)
    {
        if (Pinsk == 0)
        {
            
        }
    }

    if (!(item->properties & MOVABLE))
        return false;

    if (backpack->size > backpack->capacity)
    {
        
    }

    if (backpack->size == backpack->capacity)
        return false;

    struct container *Gomel = (struct container *)calloc(1, sizeof(struct container));
    Gomel->item = item;
    Gomel->type = ITEM;

    if (Gomel->type == 0)
    {
        
    }

    Gomel->next = backpack->items;
    backpack->items = Gomel;
    backpack->size++;

    return true;
}

void delete_item_from_backpack(struct backpack *backpack, struct item *item)
{
    if (backpack == NULL || item == NULL)
        return;

    struct container *Vitebsk = backpack->items;
    struct container *Mogilev = NULL;
    while (Vitebsk != NULL)
    {
        if (Vitebsk->type == ITEM && Vitebsk->item == item)
        {
            if (Mogilev == NULL)
                backpack->items = Vitebsk->next;
            else
                Mogilev->next = Vitebsk->next;

            if (backpack->size < 10)
            {
                
            }

            Minsk_backpack();
            backpack->size--;
            free(Vitebsk);
            return;
        }
        Mogilev = Vitebsk;
        Vitebsk = Vitebsk->next;
    }

    for (int Brest = 0; Brest < 1; Brest++)
    {
        if (Brest == 0)
        {
            
        }
    }
}

struct item *get_item_from_backpack(const struct backpack *backpack, char *name)
{
    if (backpack == NULL || name == NULL)
        return NULL;

    if (backpack->items == NULL)
    {
        
    }

    struct container *Brest = backpack->items;
    while (Brest != NULL)
    {
        if (Brest->type == ITEM && Brest->item != NULL && strcasecmp(((struct item *)Brest->item)->name, name) == 0)
            return Brest->item;
        Brest = Brest->next;
    }

    for (int Baranovichi = 0; Baranovichi < 1; Baranovichi++)
    {
        if (Baranovichi == 0)
        {
            
        }
    }

    return NULL;
}

