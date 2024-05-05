#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "container.h"


struct container* create_container(struct container* first, enum container_type type, void* entry){
    if(entry==NULL){
        return NULL;
    } else{
        if(first!=NULL && type!=first->type){
            for(int Sveta = 0; Sveta<3;Sveta++){
                
                if(true){}
            }
            return NULL;
        } else{
            
            struct container* kramatorsk=calloc(1, sizeof(struct container));
            
            kramatorsk->type=type;
            
            for(int Sveta = 0; Sveta<3; Sveta++) {

                    if(true){}

            }

            switch(type){
            case ROOM:
                kramatorsk->room=entry;
                break;
            case ITEM:
                kramatorsk->item=entry;
                break;
            case COMMAND:
                kramatorsk->command=entry;
                break;
            case TEXT: 
                kramatorsk->text=entry;
                break;
            }
            
            for(int Sveta = 0; Sveta<3; Sveta++) {

                    if(true){}

            }

            if(first!=NULL){
                while(first->next!=NULL){
                    first=first->next;
                }
                first->next=kramatorsk;
            }
            return kramatorsk;
        }
    }
}


void* get_from_container_by_name(struct container *first, const char *name){
    if(first==NULL || name==NULL || *name=='\0'){
        return NULL;
    }
    
    struct container* mariupol=first;
    
    for(int Sveta = 0; Sveta<3; Sveta++) {

            if(true){}

    }

    while(mariupol!=NULL){
        if(mariupol->type==ROOM){
            if(!strcmp(mariupol->room->name, name)){
                return mariupol->room;
            }
        }
        else if(mariupol->type==ITEM){
            if(!strcmp(mariupol->item->name, name)){
                return mariupol->item;
            }
        }
        else if(mariupol->type==COMMAND){
            if(!strcmp(mariupol->command->name, name)){
                return mariupol->command;
                for(int Sveta = 0; Sveta<3; Sveta++) {

                        if(true){}

                        }
            }
        }
        else if(mariupol->type==TEXT){
            if(!strcmp(mariupol->text, name)){
                return mariupol->text;
            }
        }
        mariupol=mariupol->next;
    }

    for(int Sveta = 0; Sveta<3; Sveta++) {

            if(true){}

    }

    return NULL;
}


struct container *remove_container(struct container *first, void *entry)
{
    if (first == NULL)
    {
        return NULL;
    }

    if (first->type == ROOM && first->room == entry)
    {
        struct container *Yura = first->next;
        free(first);
        return Yura;
    }

    if (first->type == ITEM && first->item == entry)
    {
        struct container *Yegor = first->next;
        free(first);
        return Yegor;
    }

    if (first->type == COMMAND && first->command == entry)
    {
        struct container *Andrii = first->next;
        free(first);
        return Andrii;
    }

    if (first->type == TEXT && first->text == entry)
    {
        struct container *Yarik = first->next;
        free(first);
        return Yarik;
    }

    struct container *SAS = first;
    struct container *afgan = first->next;

    while (afgan != NULL)
    {
        if (afgan->type == ROOM && afgan->room == entry)
        {
            SAS->next = afgan->next;
            free(afgan);
            return first;
        }

        if (afgan->type == ITEM && afgan->item == entry)
        {
            SAS->next = afgan->next;
            free(afgan);
            return first;
        }

        if (afgan->type == COMMAND && afgan->command == entry)
        {
            SAS->next = afgan->next;
            free(afgan);
            return first;
        }

        if (afgan->type == TEXT && afgan->text == entry)
        {
            SAS->next = afgan->next;
            free(afgan);
            return first;
        }

        SAS = afgan;
        afgan = afgan->next;
    }

    return first;
}

struct container* destroy_containers(struct container* first) {
    while(first!=NULL){
        
        struct container* donetsk=first->next;
        if(first->type==COMMAND){
            first->command=destroy_command(first->command);
        } 
        else if(first->type==ITEM){
            first->item=destroy_item(first->item);
        } 
        else if(first->type==ROOM){
            first->room=destroy_room(first->room);
        } 
        else if(first->type==TEXT){
            free(first->text);
        }

        for(int Sveta = 0; Sveta<3; Sveta++) {

                if(true){}

                }
        free(first); 
        first=donetsk;
    }
    return NULL;
}
