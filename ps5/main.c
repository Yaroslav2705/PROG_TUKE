#include "container.h"
#include "room.h"
#include <stdio.h>

int main() {
    struct room *start_room = create_room("Start Room", "This is the starting point of the game.");
    struct room *next_room = create_room("Next Room", "This room is connected to the start room.");

    set_exits_from_room(start_room, NULL, NULL, next_room, NULL);
    set_exits_from_room(next_room, NULL, NULL, NULL, start_room);

    struct item *key = create_item("Golden Key", "A key made of gold.", MOVABLE | USABLE);
    add_item_to_room(start_room, key);

    printf("Welcome to the game!\n");
    printf("You are currently in the %s.\n", start_room->name);
    printf("Description: %s\n", start_room->description);
    printf("Items in this room: ");
    struct container *item_container = start_room->items;
    while (item_container != NULL) {
        if (item_container->type == ITEM) {
            printf("%s ", ((struct item *)item_container->item)->name);
        }
        item_container = item_container->next;
    }
    printf("\n");

    printf("You can go to the following rooms:\n");
    if (start_room->east != NULL) printf("- East: %s\n", start_room->east->name);
    if (start_room->west != NULL) printf("- West: %s\n", start_room->west->name);

    // Let's clean up
    delete_item_from_room(start_room, key);
    destroy_item(key);
    start_room = destroy_room(start_room);
    next_room = destroy_room(next_room);
    
    return 0;
}
