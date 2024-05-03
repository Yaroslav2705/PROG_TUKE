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
    // Create a world with rooms
    struct container* world = create_world();

    // Create rooms
    struct room* room1 = create_room("Room 1", "Description of Room 1");
    struct room* room2 = create_room("Room 2", "Description of Room 2");

    // Add rooms to the world
    add_room_to_world(world, room1);
    add_room_to_world(world, room2);

    // Set exits between rooms
    set_exits_from_room(room1, NULL, room2, NULL, NULL);
    set_exits_from_room(room2, room1, NULL, NULL, NULL);

    // Create items
    struct item* item1 = create_item("Item 1", "Description of Item 1", MOVABLE | USABLE);
    struct item* item2 = create_item("Item 2", "Description of Item 2", MOVABLE);

    // Create a backpack
    struct backpack* backpack = create_backpack(5);

    // Add items to the backpack
    add_item_to_backpack(backpack, item1);
    add_item_to_backpack(backpack, item2);

    // Get item from the backpack
    struct item* retrieved_item = get_item_from_backpack(backpack, "Item 1");
    if (retrieved_item != NULL) {
        printf("Retrieved item from backpack: %s\n", retrieved_item->name);
    } else {
        printf("Item not found in backpack!\n");
    }

    // Parse input
    struct parser* parser = create_parser();
    char* input = "TAKE Item 1";
    struct command* cmd = parse_input(parser, input);

    // Execute command
    execute_command(cmd, backpack, world);

    // Destroy resources
    destroy_backpack(backpack);
    destroy_item(item1);
    destroy_item(item2);
    destroy_parser(parser);
    world = destroy_world(world);

    return 0;
}
