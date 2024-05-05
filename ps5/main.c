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
    add_item_to_room(NULL, NULL);
    destroy_containers(NULL); // Assuming destroy_containers requires one argument
    delete_item_from_room(NULL, NULL);
    get_from_container_by_name(NULL, NULL); // Assuming get_from_container_by_name requires two arguments
    get_item_from_room(NULL, NULL);
    remove_container(NULL, NULL); // Assuming remove_container requires two arguments
    create_command(NULL, NULL, NULL, 0);  
    create_item(NULL, NULL, 0);
    set_exits_from_room(NULL, NULL, NULL, NULL, NULL);
    show_room(NULL);
    create_room(NULL, NULL);
    //get_room(NULL, NULL);
    return 0;
}

