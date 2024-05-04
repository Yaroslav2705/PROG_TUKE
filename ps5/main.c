#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "container.h"
#include "room.h"


int main()
{
    // Test the functions from container.c
    struct container *first_container = NULL;
    struct item *item = malloc(sizeof(struct item));
    // Populate item with data
    first_container = create_container(first_container, ITEM, item);
    void *found_item = get_from_container_by_name(first_container, "Example Item");
    printf("Found item: %p\n", found_item);
    first_container = remove_container(first_container, item);
    destroy_containers(first_container);

    // Test the functions from room.c
    struct room *example_room = create_room("Example Room", "This is an example room.");
    struct room *north_room = create_room("North Room", "This room is to the north.");
    set_exits_from_room(example_room, north_room, NULL, NULL, NULL);
    show_room(example_room);
    add_item_to_room(example_room, item);
    get_item_from_room(example_room, "Example Item");
    delete_item_from_room(example_room, item);
    destroy_room(example_room);

    return 0;
}
