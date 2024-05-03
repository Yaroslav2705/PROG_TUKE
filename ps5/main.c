#include <stdio.h>
#include "backpack.h"
#include "command.h"
#include "container.h"
#include "game.h"
#include "item.h"
#include "parser.h"
#include "room.h"
#include "world.h"

int main() {
    // Creating game world
    struct container* world = create_world();

    // Creating rooms
    struct room* room1 = create_room("Room 1", "Description 1");
    struct room* room2 = create_room("Room 2", "Description 2");

    // Adding rooms to the world
    add_room_to_world(world, room1);
    add_room_to_world(world, room2);

    // Setting exits between rooms
    set_exits_from_room(room1, NULL, NULL, room2, NULL);
    set_exits_from_room(room2, NULL, room1, NULL, NULL);

    // Creating an item
    struct item* item1 = create_item("Item 1", "Description 1", MOVABLE | USABLE);

    // Creating a backpack
    struct backpack* backpack = create_backpack(5);

    // Adding item to the backpack
    add_item_to_backpack(backpack, item1);

    // Retrieving item from the backpack
    struct item* retrieved_item = get_item_from_backpack(backpack, "Item 1");
    if (retrieved_item != NULL) {
        printf("Retrieved item: %s\n", retrieved_item->name);
    } else {
        printf("Item not found!\n");
    }

    // Destroying the backpack
    backpack = destroy_backpack(backpack);

    // Destroying the world
    world = destroy_world(world);

    return 0;
}
