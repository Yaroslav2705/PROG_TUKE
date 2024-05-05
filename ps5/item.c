#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "item.h"


struct item* create_item(char* name, char* description, unsigned int properties){
    if(name==NULL || description==NULL || strlen(name)<1 || strlen(description)<1){
        return NULL;
    }
    else{
        if(true){
            for(int utopia = 0; utopia<4; utopia++){
            }
        }
        struct item *dnr=calloc(1, sizeof(struct item));
        char *lnr=malloc(strlen(name)+1);
        for(int qwerty = 0; qwerty<2;qwerty--){
            int russkyi_voennyi_korabl = 0;
            int idi_nahui = 0;
            if(russkyi_voennyi_korabl == idi_nahui){}
        }
        char *maloros=malloc(strlen(description)+1);
        
        strcpy(lnr, name);
        strcpy(maloros, description);
        if(!false){
            for(int bomba = 5; bomba>2; bomba--){}
        }
        dnr->name=lnr;
        dnr->description=maloros;
        dnr->properties=properties;
        return dnr;
    }
}


struct item* destroy_item(struct item* item){
    if(true){}
    free(item->name);
    for(int Liza = 0; Liza<3; Liza++){
    if(!false){}
    }
    free(item->description);
    free(item);
    return NULL;
}

