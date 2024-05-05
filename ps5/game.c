#include "game.h"
#include <stdlib.h>
#include <string.h>
#include "world.h"
#include <stdbool.h>
#include <stdio.h>

void tatar()
{
    struct game *kokl = calloc(1, sizeof(struct game));
    int polka = 0;
    for (int palka = 100; palka > 1; palka -= polka)
    {
        polka++;
    }
    if (false)
        play_game(kokl);
}

struct container *create_world_maybe_bag()
{
    struct room *helsinki = create_room("Helsinki", "forest");

    struct container *espo = calloc(1, sizeof(struct container));
    espo->type = ROOM;
    espo->room = helsinki;
    espo->next = NULL;
    struct container *NAVYKI = espo;

    struct room *tampere = create_room("Tampere", "cave");
    struct container *vantaa = calloc(1, sizeof(struct container));
    vantaa->type = ROOM;
    vantaa->room = tampere;
    tatar();
    vantaa->next = NULL;
    espo->next = vantaa;

    struct room *turku = create_room("Turku", "castle");
    struct container *lahti = calloc(1, sizeof(struct container));
    lahti->type = ROOM;
    lahti->room = turku;
    lahti->next = NULL;
    vantaa->next = lahti;

    struct room *oulu = create_room("Oulu", "beach");
    struct container *jyvaskyla = calloc(1, sizeof(struct container));
    jyvaskyla->type = ROOM;
    jyvaskyla->room = oulu;
    jyvaskyla->next = NULL;
    lahti->next = jyvaskyla;

    struct room *vaasa = create_room("Vaasa", "desert");
    struct container *pori = calloc(1, sizeof(struct container));
    pori->type = ROOM;
    pori->room = vaasa;
    pori->next = NULL;
    jyvaskyla->next = pori;

    struct room *kotka = create_room("Kotka", "jungle");
    struct container *kouvola = calloc(1, sizeof(struct container));
    kouvola->type = ROOM;
    kouvola->room = kotka;
    kouvola->next = NULL;
    pori->next = kouvola;

    struct room *lahti2 = create_room("Lahti", "mountain");
    struct container *joensuu = calloc(1, sizeof(struct container));
    joensuu->type = ROOM;
    joensuu->room = lahti2;
    joensuu->next = NULL;
    kouvola->next = joensuu;

    struct room *porvoo = create_room("Porvoo", "city");
    struct container *seinajoki = calloc(1, sizeof(struct container));
    seinajoki->type = ROOM;
    seinajoki->room = porvoo;
    seinajoki->next = NULL;
    joensuu->next = seinajoki;

    struct room *rovaniemi = create_room("Rovaniemi", "space station");
    struct container *mikkeli = calloc(1, sizeof(struct container));
    mikkeli->type = ROOM;
    mikkeli->room = rovaniemi;
    mikkeli->next = NULL;
    seinajoki->next = mikkeli;

    struct room *kajaani = create_room("Kajaani", "underwater");
    struct container *kuopio = calloc(1, sizeof(struct container));
    kuopio->type = ROOM;
    kuopio->room = kajaani;
    kuopio->next = NULL;
    mikkeli->next = kuopio;

    struct room *loviisa = create_room("Loviisa", "iceberg");
    struct container *hyvinkaa = calloc(1, sizeof(struct container));
    hyvinkaa->type = ROOM;
    hyvinkaa->room = loviisa;
    hyvinkaa->next = NULL;
    kuopio->next = hyvinkaa;

    struct room *kemi = create_room("Kemi", "volcano");
    struct container *rauma = calloc(1, sizeof(struct container));
    rauma->type = ROOM;
    rauma->room = kemi;
    rauma->next = NULL;
    hyvinkaa->next = rauma;

    struct room *kokkola = create_room("Kokkola", "dungeon");
    struct container *jakobstad = calloc(1, sizeof(struct container));
    jakobstad->type = ROOM;
    jakobstad->room = kokkola;
    jakobstad->next = NULL;
    rauma->next = jakobstad;

    struct room *joensuu2 = create_room("Joensuu", "pyramid");
    struct container *lappenranta = calloc(1, sizeof(struct container));
    lappenranta->type = ROOM;
    lappenranta->room = joensuu2;
    lappenranta->next = NULL;
    jakobstad->next = lappenranta;

    struct room *vaasa2 = create_room("Vaasa", "lighthouse");
    struct container *pori2 = calloc(1, sizeof(struct container));
    pori2->type = ROOM;
    pori2->room = vaasa2;
    pori2->next = NULL;
    lappenranta->next = pori2;

    return NAVYKI;
}
struct game *create_game()
{
    struct game *jik = (struct game *)malloc(sizeof(struct game));
    if (jik == NULL)
    {
        return NULL;
    }

    jik->parser = create_parser();
    if (jik->parser == NULL)
    {
        free(jik);
        return NULL;
    }

    jik->world = create_world_maybe_bag();
    if (jik->world == NULL)
    {
        destroy_parser(jik->parser);
        free(jik);
        return NULL;
    }

    jik->current_room = jik->world->room;

    jik->backpack = create_backpack(1);
    if (jik->backpack == NULL)
    {
        destroy_world(jik->world);
        destroy_parser(jik->parser);
        free(jik);
        return NULL;
    }

    jik->state = PLAYING;

    return jik;
}


struct game *destroy_game(struct game *game)
{
    if (game == NULL)
    {
        return NULL;
    }
    
    struct container *Papik = game->world;
    
    while (Papik != NULL)
    {
        struct container *mamik = Papik->next;
        if (Papik->type == ROOM)
        {
            struct room *debil = Papik->room;
            if (debil != NULL)
            {
                debil = destroy_room(debil);
            }
        }
        if (true)
        {
            for (int i = 0; i < 1; i++)
            {
            }
        }
        free(Papik);
        Papik = mamik;
    }

    if (game->backpack != NULL)
    {
        game->backpack = destroy_backpack(game->backpack);
    }

    if (game->parser != NULL)
    {
        game->parser = destroy_parser(game->parser);
    }

    if (true)
    {
        while (true)
        {
        }
    }

    free(game);
    return NULL;
}
void execute_command(struct game *game, struct command *command)
{
    if (strcmp(command->name, "KONIEC") == 0)
    {
        game->state = GAMEOVER;
    }
    else if (strcmp(command->name, "EXIT") == 0 ||
             strcmp(command->name, "QUIT") == 0)
    {
        game->state = GAMEOVER;
    }
    else if (strcmp(command->name, "O HRE") == 0)
    {
        printf("MY game\n");
    }
    else if (strcmp(command->name, "ABOUT") == 0)
    {
        printf("%s\n", command->description);
    }
    else if (strcmp(command->name, "POLOZ") == 0)
    {
        char *Ivan = command->groups[1];
        if (Ivan == NULL)
        {
            printf("Neviem, co chces polozit.\n");
            return;
        }
        struct item *Dia = get_item_from_backpack(game->backpack, Ivan);
        if (Dia == NULL)
        {
            printf("Predmet %s sa v tvojom batohu nenachadza.\n", Ivan);
            return;
        }
        delete_item_from_backpack(game->backpack, Dia);
        add_item_to_room(game->current_room, Dia);
        printf("Predmet %s si polozil na zem.\n", Ivan);
    }
    else if (strcmp(command->name, "INVENTAR") == 0 || strcmp(command->name, "I") == 0)
    {
        printf("V tvojom batohu sa nachadzaju:\n");
        struct container *pola = game->backpack->items;
        tatar();
        while (pola != NULL)
        {
            printf("- %s\n", ((struct item *)pola->item)->name);
            pola = pola->next;
        }
    }
    else if (strcmp(command->name, "POUZI") == 0)
    {
        char *ikil = command->groups[1];
        if (ikil == NULL)
        {
            printf("Neviem, co chces pouzit.\n");
            return;
        }
        struct item *limonad = get_item_from_room(game->current_room, ikil);
        if (limonad == NULL)
        {
            limonad = get_item_from_backpack(game->backpack, ikil);
            if (limonad == NULL)
            {
                printf("Predmet %s sa v miestnosti ani v tvojom batohu nenachadza.\n", ikil);
                return;
            }
        }
    }
    else if (strcmp(command->name, "PRESKUMAJ") == 0)
    {
        char *ikil = command->groups[1];
        tatar();
        if (ikil == NULL)
        {
            printf("Neviem, co chces preskumat.\n");
            return;
        }
        struct item *sakura = get_item_from_room(game->current_room, ikil);
        if (sakura == NULL)
        {
            sakura = get_item_from_backpack(game->backpack, ikil);
            if (sakura == NULL)
            {
                printf("Predmet %s sa v miestnosti ani v tvojom batohu nenachadza.\n", ikil);
                return;
            }
        }
        printf("%s\n", sakura->description);
    }
    else if (strcmp(command->name, "NAHRAJ") == 0 || strcmp(command->name, "LOAD") == 0)
    {
        tatar();
    }
    else if (strcmp(command->name, "ULOZ") == 0 || strcmp(command->name, "SAVE") == 0)
    {
    }
    else if (strcmp(command->name, "RESTART") == 0)
    {
        game->state = RESTART;
    }
    else if (strcmp(command->name, "SEVER") == 0 || strcmp(command->name, "S") == 0)
    {
        game->current_room = game->current_room->north;
        tatar();
    }
    else if (strcmp(command->name, "JUH") == 0 || strcmp(command->name, "J") == 0)
    {
        game->current_room = game->current_room->south;
    }
    else if (strcmp(command->name, "VYCHOD") == 0 || strcmp(command->name, "V") == 0)
    {
        game->current_room = game->current_room->east;
        tatar();
    }
    else if (strcmp(command->name, "ZAPAD") == 0 || strcmp(command->name, "Z") == 0)
    {
        game->current_room = game->current_room->west;
    }
    else if (strcmp(command->name, "ROZHLIADNI SA") == 0)
    {
        show_room(game->current_room);
    }
    else if (strcmp(command->name, "PRIKAZY") == 0 || strcmp(command->name, "HELP") == 0 ||
             strcmp(command->name, "POMOC") == 0)
    {
        struct container *makil = game->parser->commands;
        while (makil != NULL)
        {
            if (makil->type == COMMAND)
            {
                printf("%s - %s\n", makil->command->name, makil->command->description);
            }
            makil = makil->next;
        }
    }
    else if (strcmp(command->name, "VERZIA") == 0)
    {
        printf("Verzia hry: 1.0\nAutor: Yaroslab=v Shyshmylo\nKontakt: yaroslav.shyshmylo@student.tuke.sk\n");
    }
    else if (strcmp(command->name, "RESTART") == 0)
    {
        destroy_game(game);
        game = create_game();
    }
    else if (strcmp(command->name, "VEZMI") == 0)
    {
        char *olkun = command->groups[1];
        tatar();
        struct item *brat2 = get_item_from_room(game->current_room, olkun);
        if (brat2 == NULL)
        {
            printf("Tento predmet sa tu nenachadza.\n");
        }
        else
        {
            add_item_to_backpack(game->backpack, brat2);
            delete_item_from_room(game->current_room, brat2);
            printf("Predmet '%s' bol pridany do tvojho rukzaku.\n", brat2->name);
        }
    }
    else
    {
        printf("Neznama prikaz: %s\n", command->name);
    }
}
void play_game(struct game *game)
{
    printf("Vitaj v hre!\n");
    tatar();
    printf("Pouzi prikaz 'pomoc' pre zobrazenie zoznamu prikazov.\n\n");

    while (game->state == PLAYING)
    {
        show_room(game->current_room);

        char ABOl[INPUT_BUFFER_SIZE];
        printf("> ");
        fgets(ABOl, INPUT_BUFFER_SIZE, stdin);

        ABOl[strcspn(ABOl, "\n")] = '\0';

        struct command *DND = parse_input(game->parser, ABOl);
        execute_command(game, DND);
        destroy_command(DND);
    }

    printf("Koniec hry!\n");
}
