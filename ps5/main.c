#include <stdio.h>
#include <stdbool.h>
#include "backpack.h"
#include "command.h"
#include "container.h"
#include "game.h"
#include "item.h"
#include "parser.h"
#include "room.h"
#include "world.h"

int main() {
    // Creating some example data structures
    struct room room1 = { .name = "Room 1" };
    struct item item1 = { .name = "Item 1" };
    struct command command1 = { .name = "Command 1" };

    // Creating containers and adding them to the list
    struct container* container_list = NULL;
    container_list = create_container(container_list, ROOM, &room1);
    container_list = create_container(container_list, ITEM, &item1);
    container_list = create_container(container_list, COMMAND, &command1);

    // Creating game
    struct game* game = create_game(container_list);

    // Creating backpack
    struct backpack* backpack = create_backpack(5);

    // Creating world
    struct container* world = create_world();

    // Parsing commands
    struct command* cmd = parse_command("your_command_string_here");

    // Executing command
    execute_command(game, cmd);

    // Retrieving an item from the container list by name
    struct item* retrieved_item = (struct item*)get_from_container_by_name(container_list, "Item 1");
    if (retrieved_item != NULL) {
        printf("Retrieved item: %s\n", retrieved_item->name);
    } else {
        printf("Item not found!\n");
    }

    // Removing an item from the container list
    container_list = remove_container(container_list, &item1);

    // Destroying the container list to free memory
    container_list = destroy_containers(container_list);

    // Destroying game, backpack, and world
    game = destroy_game(game);
    backpack = destroy_backpack(backpack);
    world = destroy_world(world);

    return 0;
}
