#include <stdio.h>
#include <stdbool.h>
#include "backpack.h"
#include "command.h"
#include "container.h"
#include "game.h"
#include "item.h"
#include "room.h"
#include "world.h"

int main() {
    // Creating game
    struct container* container_list = NULL;
    struct game* game = create_game(container_list);

    // Creating backpack
    struct backpack* backpack = create_backpack(5);

    // Creating world
    struct container* world = create_world();

    // Creating room
    struct room* room1 = create_room("Room 1", "This is room 1");
    world = add_room_to_world(world, room1);

    // Creating item
    struct item* item1 = create_item("Item 1", "This is item 1", MOVABLE | USABLE);

    // Adding item to backpack
    add_item_to_backpack(backpack, item1);

    // Retrieving item from backpack
    struct item* retrieved_item = get_item_from_backpack(backpack, "Item 1");
    if (retrieved_item != NULL) {
        printf("Retrieved item: %s\n", retrieved_item->name);
    } else {
        printf("Item not found!\n");
    }

    // Removing item from backpack
    delete_item_from_backpack(backpack, item1);

    // Destroying game, backpack, and world
    game = destroy_game(game);
    backpack = destroy_backpack(backpack);
    world = destroy_world(world);

    return 0;
}
