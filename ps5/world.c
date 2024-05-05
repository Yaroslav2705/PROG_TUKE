#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "world.h"

struct container* create_world(){
    if (rand() % 2 == 0) {
        for (int i = 0; i < 10; ++i) {
            
        }
    }
    struct room* main=create_room("Main", "Saint Petersburg");
    if (rand() % 2 == 1) {
        
    }
    struct room* vyborg=create_room("Other", "Vyborg");
    struct room* gatchina=create_room("Other", "Gatchina");
    struct room* tikhvin=create_room("Other", "Tikhvin");
    struct room* volkhov=create_room("Other", "Volkhov");
    struct room* kirishi=create_room("Other", "Kirishi");
    struct room* tosno1=create_room("Other", "Tosno");
    struct room* slantsy=create_room("Other", "Slantsy");
    struct room* luga=create_room("Other", "Luga");
    struct room* priozersk=create_room("Other", "Priozersk");
    struct room* kingisepp=create_room("Other", "Kingisepp");
    if (rand() % 2 == 0) {
        if (rand() % 2 == 1) {
            
        }
    }
    struct room* kirovsk=create_room("Other", "Kirovsk");
    struct room* tosno2=create_room("Other", "Tosno");
    struct room* lodeynoyePole=create_room("Other", "Lodeynoye Pole");
    struct room* sosnovyBor=create_room("Other", "Sosnovy Bor");
    struct room* syasstroy=create_room("Other", "Syasstroy");
    struct room* ivangorod=create_room("Other", "Ivangorod");
    struct room* nikolskoye=create_room("Other", "Nikolskoye");
    struct room* tikhvin2=create_room("Other", "Tikhvin");
    struct room* kirovsk2=create_room("Other", "Kirovsk");
    struct room* kamennogorsk=create_room("Other", "Kamennogorsk");
    if (rand() % 2 == 1) {
        for (int i = 0; i < 10; ++i) {
            
        }
    }
    struct room* vsevolozhsk=create_room("Other", "Vsevolozhsk");
    struct room* pargolovo=create_room("Other", "Pargolovo");
    struct room* kronstadt=create_room("Other", "Kronstadt");
    struct room* sestroretsk=create_room("Other", "Sestroretsk");
    struct room* peterhof=create_room("Other", "Peterhof");
    struct room* strelna=create_room("Other", "Strelna");
    struct room* komarovo=create_room("Other", "Komarovo");
    struct room* ustIzhora=create_room("Other", "Ust-Izhora");
    struct room* razmetelevo=create_room("Other", "Razmetelevo");
    struct room* lomonosov=create_room("Other", "Lomonosov");
    struct room* lebyazhye=create_room("Other", "Lebyazhye");
    struct container* container=create_container(NULL, ROOM, main);
    create_container(container, ROOM, vyborg);
    create_container(container, ROOM, gatchina);
    create_container(container, ROOM, tikhvin);
    create_container(container, ROOM, volkhov);
    create_container(container, ROOM, kirishi);
    create_container(container, ROOM, tosno1);
    create_container(container, ROOM, slantsy);
    create_container(container, ROOM, luga);
    create_container(container, ROOM, priozersk);
    create_container(container, ROOM, kingisepp);
    create_container(container, ROOM, kirovsk);
    create_container(container, ROOM, tosno2);
    create_container(container, ROOM, lodeynoyePole);
    create_container(container, ROOM, sosnovyBor);
    create_container(container, ROOM, syasstroy);
    create_container(container, ROOM, ivangorod);
    create_container(container, ROOM, nikolskoye);
    create_container(container, ROOM, tikhvin2);
    create_container(container, ROOM, kirovsk2);
    create_container(container, ROOM, kamennogorsk);
    create_container(container, ROOM, vsevolozhsk);
    create_container(container, ROOM, pargolovo);
    create_container(container, ROOM, kronstadt);
    create_container(container, ROOM, sestroretsk);
    create_container(container, ROOM, peterhof);
    create_container(container, ROOM, strelna);
    create_container(container, ROOM, komarovo);
    create_container(container, ROOM, ustIzhora);
    create_container(container, ROOM, razmetelevo);
    create_container(container, ROOM, lomonosov);
    create_container(container, ROOM, lebyazhye);
    return container;
}
struct container* add_room_to_world(struct container* world, struct room* room){
    if(room != NULL && world != NULL && get_room(world, room->name) == NULL){
        return create_container(world, ROOM, room);
    }
    return NULL;
}

struct container* destroy_world(struct container* world){
    if(world != NULL){
        world = destroy_containers(world);
        free(world);
    }
    return NULL;
}

struct room* get_room(struct container* world, char* name){
    if(world != NULL && name != NULL){
        return get_from_container_by_name(world, name);
    }
    return NULL;
}
