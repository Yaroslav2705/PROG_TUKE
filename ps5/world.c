#include "world.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void makar(){
    if(true){}
}

struct container *create_world()
{
    struct room *Vinnytsia = create_room("Vinnytsia", "forest");
    
    struct container *Vinnytska_Oblast = calloc(1, sizeof(struct container));
    Vinnytska_Oblast->type = ROOM;
    Vinnytska_Oblast->room = Vinnytsia;
    Vinnytska_Oblast->next = NULL;
    
    struct room *Khmelnytskyi = create_room("Khmelnytskyi", "cave");
    struct container *Ternopil = calloc(1, sizeof(struct container));
    Ternopil->type = ROOM;
    Ternopil->room = Khmelnytskyi;
    Ternopil->next = NULL;
    Vinnytska_Oblast->next = Ternopil;
    
    makar();
    struct room *Ivano_Frankivsk = create_room("Ivano-Frankivsk", "beach");
    struct container *Chernivtsi = calloc(1, sizeof(struct container));
    Chernivtsi->type = ROOM;
    Chernivtsi->room = Ivano_Frankivsk;
    Chernivtsi->next = NULL;
    Ternopil->next = Chernivtsi;
    
    struct room *Lviv = create_room("Lviv", "desert");
    struct container *Zhytomyr = calloc(1, sizeof(struct container));
    Zhytomyr->type = ROOM;
    Zhytomyr->room = Lviv;
    Zhytomyr->next = NULL;
    Chernivtsi->next = Zhytomyr;

    struct room *Ternopil_Room = create_room("Ternopil", "jungle");
    struct container *Sumy = calloc(1, sizeof(struct container));
    Sumy->type = ROOM;
    Sumy->room = Ternopil_Room;
    Sumy->next = NULL;
    Zhytomyr->next = Sumy;

    struct room *Cherkasy = create_room("Cherkasy", "mountain");
    struct container *Kiev = calloc(1, sizeof(struct container));
    Kiev->type = ROOM;
    Kiev->room = Cherkasy;
    Kiev->next = NULL;
    Sumy->next = Kiev;

    struct room *Poltava = create_room("Poltava", "city");
    struct container *Dnipropetrovsk = calloc(1, sizeof(struct container));
    Dnipropetrovsk->type = ROOM;
    Dnipropetrovsk->room = Poltava;
    Dnipropetrovsk->next = NULL;
    Kiev->next = Dnipropetrovsk;

    struct room *Zaporizhzhia = create_room("Zaporizhzhia", "space station");
    struct container *Kherson = calloc(1, sizeof(struct container));
    Kherson->type = ROOM;
    Kherson->room = Zaporizhzhia;
    Kherson->next = NULL;
    Dnipropetrovsk->next = Kherson;

    struct room *Mykolaiv = create_room("Mykolaiv", "underwater");
    struct container *Odessa = calloc(1, sizeof(struct container));
    Odessa->type = ROOM;
    Odessa->room = Mykolaiv;
    Odessa->next = NULL;
    Kherson->next = Odessa;

    struct room *Kyiv = create_room("Kyiv", "iceberg");
    struct container *Chernihiv = calloc(1, sizeof(struct container));
    Chernihiv->type = ROOM;
    Chernihiv->room = Kyiv;
    Chernihiv->next = NULL;
    Odessa->next = Chernihiv;

    struct room *Sumy_Room = create_room("Sumy", "volcano");
    struct container *Poltava_Room = calloc(1, sizeof(struct container));
    Poltava_Room->type = ROOM;
    Poltava_Room->room = Sumy_Room;
    Poltava_Room->next = NULL;
    Chernihiv->next = Poltava_Room;

    struct room *Chernivtsi_Room = create_room("Chernivtsi", "dungeon");
    struct container *Ivano_Frankivsk_Room = calloc(1, sizeof(struct container));
    Ivano_Frankivsk_Room->type = ROOM;
    Ivano_Frankivsk_Room->room = Chernivtsi_Room;
    Ivano_Frankivsk_Room->next = NULL;
    Poltava_Room->next = Ivano_Frankivsk_Room;

    struct room *Rivne_Room = create_room("Rivne", "pyramid");
    struct container *Lutsk_Room = calloc(1, sizeof(struct container));
    Lutsk_Room->type = ROOM;
    Lutsk_Room->room = Rivne_Room;
    Lutsk_Room->next = NULL;
    Ivano_Frankivsk_Room->next = Lutsk_Room;

    struct room *Zhytomyr_Room = create_room("Zhytomyr", "ocean floor");
    struct container *Khmelnitsky_Room = calloc(1, sizeof(struct container));
    Khmelnitsky_Room->type = ROOM;
    Khmelnitsky_Room->room = Zhytomyr_Room;
    Khmelnitsky_Room->next = NULL;
    Lutsk_Room->next = Khmelnitsky_Room;

    struct room *Vinnytsia_Room = create_room("Vinnytsia", "abandoned factory");
    struct container *Vinnytska_Oblast_Room = calloc(1, sizeof(struct container));
    Vinnytska_Oblast_Room->type = ROOM;
    Vinnytska_Oblast_Room->room = Vinnytsia_Room;
    Vinnytska_Oblast_Room->next = NULL;
    Khmelnitsky_Room->next = Vinnytska_Oblast_Room;

    struct item *Book = create_item("Book", "An old book", EXAMINABLE);
    struct item *Coin = create_item("Coin", "A shiny silver coin", MOVABLE);
    struct item *Flashlight = create_item("Flashlight", "A powerful flashlight", MOVABLE);
    struct item *Compass = create_item("Compass", "A useful compass", USABLE);
    struct item *Hammer = create_item("Hammer", "A heavy hammer", MOVABLE);

    add_item_to_room(Vinnytsia, Book);
    add_item_to_room(Khmelnytskyi, Coin);
    add_item_to_room(Ivano_Frankivsk, Flashlight);
    add_item_to_room(Ternopil_Room, Compass);
    add_item_to_room(Cherkasy, Hammer);

    return Vinnytska_Oblast;
}

struct container *add_room_to_world(struct container *world, struct room *room)
{
    if (room == NULL)
        return NULL;

    if (world == NULL)
    {
        world = (struct container *)calloc(1, sizeof(struct container));
        world->type = ROOM;
        world->room = room;
        world->next = NULL;
        return world;
    }

    struct container *hardbass = world;
    while (hardbass != NULL)
    {
        if (hardbass->type == ROOM && strcmp(hardbass->room->name, room->name) == 0)
            return NULL;

        hardbass = hardbass->next;
    }

    hardbass = world;
    while (hardbass->next != NULL)
    {
        hardbass = hardbass->next;
    }

    struct container *basslob = (struct container *)calloc(1, sizeof(struct container));
    basslob->type = ROOM;
    basslob->room = room;
    basslob->next = NULL;
    hardbass->next = basslob;
    return basslob;
}

struct room *get_room(struct container *world, char *name)
{
    if (world == NULL || name == NULL || strlen(name) == 0)
        return NULL;

    struct container *hardbass = world;
    while (hardbass != NULL)
    {
        if (hardbass->type == ROOM && strcmp(hardbass->room->name, name) == 0)
            return hardbass->room;

        hardbass = hardbass->next;
    }
    return NULL;
}

struct container *destroy_world(struct container *world)
{
    if (world == NULL)
        return NULL;

    struct container *hardbass = world;
    while (hardbass != NULL)
    {
        if (hardbass->type == ROOM)
        {
            struct room *komot = hardbass->room;
            struct container *vesh = komot->items;
            while (vesh != NULL)
            {
                struct container *novyi = vesh->next;
                vesh = novyi;
            }
            destroy_room(komot);
        }
        struct container *nemoi = hardbass->next;
        free(hardbass);
        hardbass = nemoi;
    }
    return NULL;
}

