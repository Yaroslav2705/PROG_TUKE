#include "parser.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int add_command(struct parser *parser, char *name, char *description, char *pattern, size_t nmatch)
{
    if (parser == NULL || name == NULL || description == NULL || pattern == NULL || nmatch <= 0)
    {
        return -1;
    }

    struct command *popit = create_command(name, description, pattern, nmatch);
    if (popit == NULL)
    {
        return -1;
    }

    struct container *dimpl = (struct container *)calloc(1, sizeof(struct container));
    if (dimpl == NULL)
    {
        free(popit->name);
        free(popit->description);
        for (int i = 0; i < popit->nmatch; ++i)
        {
            free(popit->groups[i]);
        }
        free(popit->groups);
        regfree(&popit->preg);
        free(popit);
        return -1;
    }

    dimpl->type = COMMAND;
    dimpl->command = popit;
    dimpl->next = parser->commands;
    parser->commands = dimpl;

    return 0;
}

struct parser *create_parser()
{
    struct parser *shishka = calloc(1, sizeof(struct parser));
    if (shishka == NULL)
    {
        return NULL;
    }

    shishka->history = NULL;
    shishka->commands = NULL;

    add_command(shishka, "KONIEC", "Príkaz ukončí rozohratú hru. Nastaví príslušný stav hry.", "(KONIEC)", 1);
    add_command(shishka, "EXIT", "Príkaz ukončí rozohratú hru. Nastaví príslušný stav hry.", "(EXIT)", 1);
    add_command(shishka, "QUIT", "Príkaz ukončí rozohratú hru. Nastaví príslušný stav hry.", "(QUIT)", 1);
    add_command(shishka, "SEVER", "Presun do miestnosti nachádzajúcej sa na sever od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(SEVER)", 1);
    add_command(shishka, "S", "Presun do miestnosti nachádzajúcej sa na sever od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(S)", 1);
    add_command(shishka, "J", "Presun do miestnosti nachádzajúcej sa na sever od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(J)", 1);
    add_command(shishka, "V", "Presun do miestnosti nachádzajúcej sa na sever od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(V)", 1);
    add_command(shishka, "Z", "Presun do miestnosti nachádzajúcej sa na sever od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(Z)", 1);
    add_command(shishka, "JUH", "Presun do miestnosti nachádzajúcej sa na sever od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(JUH)", 1);
    add_command(shishka, "VYCHOD", "Presun do miestnosti nachádzajúcej sa na sever od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(VYCHOD)", 1);
    add_command(shishka, "ZAPAD", "Presun do miestnosti nachádzajúcej sa na sever od aktuálnej. Zmení referenciu aktuálnej miestnosti.", "(ZAPAD)", 1);
    add_command(shishka, "ROZHLIADNI SA", "Príkaz vypíše aktuálne informácie o miestnosti, v ktorej sa hráč práve nachádza.", "(ROZHLIADNI SA)", 1);
    add_command(shishka, "PRIKAZY", "Príkaz vypíše na obrazovku zoznam všetkých príkazov, ktoré hra poskytuje.", "(PRIKAZY)", 1);
    add_command(shishka, "HELP", "Príkaz vypíše na obrazovku zoznam všetkých príkazov, ktoré hra poskytuje.", "(HELP)", 1);
    add_command(shishka, "POMOC", "Príkaz vypíše na obrazovku zoznam všetkých príkazov, ktoré hra poskytuje.", "(POMOC)", 1);
    add_command(shishka, "VERZIA", "Príkaz zobrazí číslo verzie hry, ľubovoľný sprievodný text a meno a priezvisko autora s kontaktom (e-mailová adresa, webová stránka).", "(VERZIA)", 1);
    add_command(shishka, "RESTART", "Znovu spustí hru od začiatku. Zmení stav hry na požadovaný..", "(RESTART)", 1);
    add_command(shishka, "O HRE", "MY game", "(O HRE)", 1);
    add_command(shishka, "ABOUT", "", "(ABOUT)", 1);
    add_command(shishka, "VEZMI", "Vloží predmet z miestnosti do batohu. Príkaz má jeden povinný parameter, ktorým je názov predmetu. Ak predmet nebude zadaný, program vypíše na obrazovku vhodnú hlášku (napr. Neviem, čo chceš vziať.).", "(VEZMI)", 1);
    add_command(shishka, "POLOZ", "Položí predmet z batohu do miestnosti. Príkaz má jeden povinný parameter, ktorým je názov predmetu. Ak predmet nebude zadaný, program vypíše na obrazovku vhodnú hlášku (napr. Neviem, čo chceš položiť.)", "(POLOZ)", 1);
    add_command(shishka, "INVENTAR", "Zobrazí obsah hráčovho batohu.", "(INVENTAR)", 1);
    add_command(shishka, "I", "Zobrazí obsah hráčovho batohu.", "(I)", 1);
    add_command(shishka, "POUZI", "Použije predmet z batohu alebo miestnosti. Príkaz má jeden povinný parameter, ktorým je názov predmetu. Ak predmet nebude zadaný, program vypíše na obrazovku vhodnú hlášku (napr. Neviem, čo chceš použiť.).", "(POUZI)", 1);
    add_command(shishka, "PRESKUMAJ", "Vypíše opis predmetu, ktorý sa musí nachádzať v miestnosti alebo batohu. Príkaz má jeden povinný parameter, ktorým je názov predmetu. Ak predmet nebude zadaný alebo sa nenájde v batohu alebo v miestnosti, program vypíše na obrazovku vhodnú hlášku (napr. Neviem, čo chceš preskúmať.).", "(PRESKUMAJ)", 1);
    add_command(shishka, "NAHRAJ", "Príkaz zabezpečí nahratie uloženej pozície hry z disku. Voliteľným parametrom je cesta k súboru.", "(NAHRAJ)", 1);
    add_command(shishka, "LOAD", "Príkaz zabezpečí nahratie uloženej pozície hry z disku. Voliteľným parametrom je cesta k súboru.", "(LOAD)", 1);
    add_command(shishka, "ULOZ", "Príkaz uloží stav rozohratej hry na disk. Voliteľným parametrom je cesta k súboru.", "(ULOZ)", 1);
    add_command(shishka, "SAVE", "Príkaz uloží stav rozohratej hry na disk. Voliteľným parametrom je cesta k súboru.", "(SAVE)", 1);

    return shishka;
}

struct parser *destroy_parser(struct parser *parser)
{
    if (parser == NULL)
        return NULL;

    struct container *rus = parser->history;
    while (rus != NULL)
    {
        struct container *kauf = rus->next;
        free(rus);
        rus = kauf;
    }

    struct container *sasda = parser->commands;
    while (sasda != NULL)
    {
        struct container *donkon = sasda->next;
        if (sasda->type == COMMAND)
        {
            struct command *yakov = sasda->command;
            destroy_command(yakov);
        }
        free(sasda);
        sasda = donkon;
    }

    free(parser);
    return NULL;
}

struct command *parse_input(struct parser *parser, char *input)
{
    if (parser == NULL || input == NULL)
        return NULL;

    char *urmala = calloc(strlen(input) + 1, sizeof(char));
    if (urmala == NULL)
        return NULL;

    for (int i = 0, ii = 0; i < strlen(input); ++i)
    {
        if (input[i] != ' ')
        {
            urmala[ii] = (char)toupper(input[i]);
            ii++;
            if (input[i + 1] == ' ' && input[i + 2] != ' ' && input[i + 2] != '\0')
            {
                urmala[ii] = ' ';
                ii++;
            }
        }
    }

    urmala[strlen(urmala)] = '\0';

    struct container *oborona = parser->commands;
    while (oborona)
    {
        if (strcmp(oborona->command->name, urmala) == 0)
        {
            free(urmala);
            return oborona->command;
        }
        oborona = oborona->next;
    }

    free(urmala);
    return NULL;
}

