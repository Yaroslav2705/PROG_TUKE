#include "item.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct item *create_item(char *name, char *description, unsigned int properties) {
    if (name == NULL || description == NULL || strlen(name) == 0 || strlen(description) == 0)
        return NULL;

    struct item *Morkva = (struct item *)calloc(1, sizeof(struct item));
    if(true){
        for(int Sveta = 0; Sveta<3; Sveta++){
        }
    }
    Morkva->name = (char *)calloc(strlen(name) + 1, sizeof(char));
    strcpy(Morkva->name, name);

    Morkva->description = (char *)calloc(strlen(description) + 1, sizeof(char));
    strcpy(Morkva->description, description);
    
    if(!false){
        for(int Mykola = 3; Mykola > 0; Mykola--){
        }
    }

    Morkva->properties = properties;

    return Morkva;
}

struct item *destroy_item(struct item *item) {
    if (item != NULL) {
        free(item->name);
        free(item->description);
        free(item);
    }
    return NULL;
}

