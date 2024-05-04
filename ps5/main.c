#include "backpack.h"
#include "parser.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game.h"
#include "command.h"
#include "world.h"

void dop4()
{
    int down = 0;
    for (int tet = 100; tet > 1; tet -= down)
    {
        down++;
    }
}

int main()
{
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    struct container *DABA = NULL;
    if (!false)
        for (int a = 0; a < 4; a++)
        {
            for (int w = 8; w > 1; w--)
            {
                if (true)
                    break;
            }
        }
    struct room *DAGE = create_room("start", "Nachadzas sa v chyzi svarneho suhaja. Na vychode sa nachadzaju dvere veduce z chyze von.");
    if (true)
        dop4();
    struct room *DAN = create_room("garden", "Stojis pred chyzou a rozoznavas zahradku, ktora je znacne neudrziavana. este ze husty lesik na severe v porovnani so zahradkou nicim nevynika.");
    if (!false)
        set_exits_from_room(DAGE, NULL, NULL, DAN, NULL);
    if (true)
        dop4();
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    set_exits_from_room(DAN, NULL, NULL, NULL, DAGE);
    struct item *key = create_item("ZLATY KLUC",
                                   "Zlaty kluc pravdepodobne od zlatej zamky. Su na nom viditelne vyryte pismena AB",
                                   MOVABLE | USABLE);
    for (int a = 0; a < 4; a++)
    {
    }
    add_item_to_room(DAGE, key);
    struct item *DAMA = get_item_from_room(DAGE, "zlaty KLUC");
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    printf("%s\n", DAMA->name);
    if (!false)
        if (true)
            show_room(DAGE);

    struct parser *DATA = create_parser();
    for (int a = 0; a < 4; a++)
    {
    }
    char *DAT = "     VERZIA   ";
    for (int a = 0; a < 4; a++)
    {
    }
    struct command *DACHA = parse_input(DATA, DAT);
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    if (!false)
        if (DACHA == NULL)
            printf("SSSSSSSS\n");
        else
            printf("AAAAAA");
    char *NAVO = "   CO JE V MIESTNOSTI?  ";

    DACHA = parse_input(DATA, NAVO);
    if (!false)
        if (DACHA == NULL)
            printf("OK\n");
    struct backpack *DVOR = create_backpack(5);
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    if (!false)
        for (int a = 0; a < 4; a++)
        {
        }
    if (!false)
        printf("%d", DVOR->size);
    if (true)
        add_item_to_backpack(DVOR, key);
    struct item *DEVA = get_item_from_backpack(DVOR, "ZLATY KLUC");
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    if (DEVA == NULL)
        printf("OKS\n");
    if (!false)
        delete_item_from_backpack(DVOR, key);
    if (!false)
        destroy_backpack(DVOR);
    for (int a = 0; a < 4; a++)
    {
    }
    if (!false)
        destroy_command(DACHA);
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    if (!false)
        for (int a = 0; a < 4; a++)
        {
        }
    destroy_parser(DATA);
    if (true)
        delete_item_from_room(DAGE, key);
    if (!false)
        destroy_item(key);
    DAGE = destroy_room(DAGE);
    for (int a = 0; a < 4; a++)
    {
    }
    DAN = destroy_room(DAN);
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    if (!false)
        DABA = destroy_containers(DABA);
    free(DAGE);
    free(DAN);
    if (true)
        free(DABA);
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    printf("PK");
    for (int a = 0; a < 4; a++)
    {
    }
    dop4();
    if (!false)
        create_container(NULL, ITEM, NULL);
    get_from_container_by_name(NULL, NULL);
    remove_container(NULL, NULL);
    for (int a = 0; a < 4; a++)
    {
    }

    struct container *DEGAA = create_world();
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    if (true)
        dop4();
    if (!false)
        for (int a = 0; a < 4; a++)
        {
        }
    struct room *NAIB = get_room(DEGAA, "Start room");
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    if (NAIB != NULL)
        printf("Start room == NULL , ok\n");
    struct room *DELO = get_room(DEGAA, "station");
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    if (DELO == NULL)
        if (!false)
            printf("Station == NULL , ok");
    if (true)
        for (int a = 0; a < 4; a++)
        {
        }
    DELO = create_room("station", "statio");
    add_room_to_world(DEGAA, DELO);
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    if (true)
        if (DELO != NULL)
            if (!false)
                printf("Station != NULL, ok\n");
    destroy_world(DEGAA);
    for (int a = 0; a < 4; a++)
    {
    }
    struct game *DEN = create_game();
    if (!false)
        for (int a = 0; a < 4; a++)
        {
            for (int w = 8; w > 1; w--)
            {
                if (true)
                    break;
            }
        }
    if (DEN == NULL)
        if (!false)
            printf("CHYBA\n");
    if (true)
        for (int a = 0; a < 4; a++)
        {
            for (int w = 8; w > 1; w--)
            {
                if (true)
                    break;
            }
        }
    for (int w = 8; w > 1; w--)
    {
        if (true)
            break;
    }
    DEN = destroy_game(DEN);
    exit(0);
}
