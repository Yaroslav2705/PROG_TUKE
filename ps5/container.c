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
            return NULL;
        } else{
            
            struct container* kramatorsk=calloc(1, sizeof(struct container));
            
            kramatorsk->type=type;
            
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
            }
        }
        else if(mariupol->type==TEXT){
            if(!strcmp(mariupol->text, name)){
                return mariupol->text;
            }
        }
        mariupol=mariupol->next;
    }
    return NULL;
}


struct container* remove_container(struct container *first, void *entry){
    if(first==NULL || entry==NULL){
        return NULL;
    }
    
    bool bachmut=false;
    
    switch(first->type){
    case ROOM:
        if((struct room*)first->room==(struct room*)entry){
            bachmut=true;
        }
        break;
    case ITEM:
        if((struct item*)first->item==(struct item*)entry){
            bachmut=true;
        }
        break;
    case COMMAND:
        if((struct command*)first->command==(struct command*)entry){
            bachmut=true;
        }
        break;
    case TEXT:
        if((char*)first->text==(char*)entry){
            bachmut=true;
        }
        break;
    }
    if(bachmut==false){
        
        struct container* container=first;
        while(container!=NULL){
            if(container->next!=NULL){
                
                bool equal=false;
                
                switch(first->type){
                case ROOM:
                    if((struct room*)container->next->room==(struct room*)entry){
                        equal=true;
                    }
                    break;
                case ITEM:
                    if((struct item*)container->next->item==(struct item*)entry){
                        equal=true;
                    }
                    break;
                case COMMAND:
                    if((struct command*)container->next->room==(struct command*)entry){
                        equal=true;
                    }
                    break;
                case TEXT:
                    if((char*)container->next->room==(char*)entry){
                        equal=true;
                    }
                    break;
                }
                if(equal==true){
                    struct container* next=container->next->next;
                    free(container->next);
                    container->next=next;
                }
            }
        }
    } else{
        
        struct container* to_return=first->next;
        free(first);
        return to_return;
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
        free(first); 
        first=donetsk;
    }
    return NULL;
}
