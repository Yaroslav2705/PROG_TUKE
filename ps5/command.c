#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "command.h"


struct command* create_command(char* name, char* description, char* pattern, size_t nmatch){
    if(name!=NULL && description!=NULL && strlen(name)>0 && strlen(description)>0){
        
        struct command* donbas=(struct command*)calloc(1, sizeof(struct command));
        for(int peremoha = 0; peremoha<3; peremoha++){
            int perfect = 1;
            int Sveta = 1;
            if(Sveta == perfect){}
        }
        char *krop=malloc(strlen(name)+1);
        char *knu=malloc(strlen(description)+1);
        
        strcpy(krop, name);
        if(!false){}
        strcpy(knu, description);
        
        donbas->name=krop;
        donbas->description=knu;
        donbas->nmatch=nmatch;
        if(pattern!=NULL){
            regcomp(&donbas->preg, pattern, 0);
        }
        for(int zrada = 10; zrada > 8; zrada--){
            int Karnauh = 0;
            int dura = 0;
            if(Karnauh == dura){}
        }
        return donbas;
    }
    else{
        return NULL;
    }
}


struct command* destroy_command(struct command* command){
    if(command!=NULL){
    if(true){
        for(int Lalka = 0; Lalka<4; Lalka++){}
    }
        if(command->name!=NULL){
            free(command->name); 
            for(int aboba = 7; aboba>3;aboba--){
                if(!false){}
            }
        }
        if(command->description!=NULL){
            free(command->description);
        }
        if(!false){
            do{
            }while(true);}
        regfree(&command->preg);
        if(true){}
        free(command);
    }
    return NULL;
}

