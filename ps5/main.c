#include <stdio.h>
#include "world.h"
#include "backpack.h"
#include "room.h"
#include "container.h"
#include "game.h"
#include "item.h"
#include "command.h"

int main() {
    
    create_container(NULL, ROOM, NULL); // Assuming create_container requires three arguments
   
    destroy_containers(NULL); // Assuming destroy_containers requires one argument
   
    get_from_container_by_name(NULL, NULL); // Assuming get_from_container_by_name requires two arguments
   
    remove_container(NULL, NULL); // Assuming remove_container requires two arguments
   
    
    return 0;
}

