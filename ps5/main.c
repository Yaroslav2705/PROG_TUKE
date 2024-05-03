#include <stdio.h>
#include <stdbool.h>
#include "room.h"
#include "item.h"
#include "command.h"
#include "game.h"
#include "parser.h"
#include "backpack.h"
#include "world.h"

int main() {
    // Створюємо кімнати
    struct room* room1 = create_room("Room 1", "This is room 1");
    struct room* room2 = create_room("Room 2", "This is room 2");
    struct room* room3 = create_room("Room 3", "This is room 3");

    // Встановлюємо виходи з кімнат
    set_exits_from_room(room1, NULL, room2, room3, NULL);
    set_exits_from_room(room2, room1, NULL, NULL, room3);
    set_exits_from_room(room3, NULL, room1, room2, NULL);

    // Створюємо предмети
    struct item* item1 = create_item("Item 1", "This is item 1", MOVABLE | USABLE);
    struct item* item2 = create_item("Item 2", "This is item 2", MOVABLE);
    struct item* item3 = create_item("Item 3", "This is item 3", USABLE);

    // Додаємо предмети до кімнат
    add_item_to_room(room1, item1);
    add_item_to_room(room2, item2);
    add_item_to_room(room3, item3);

    // Показуємо кімнату
    show_room(room1);
    show_room(room2);
    show_room(room3);

    // Створюємо команди
    struct command* command1 = create_command("Command 1", "This is command 1", "pattern", 1);
    struct command* command2 = create_command("Command 2", "This is command 2", "pattern", 1);

    // Створюємо гру
    struct game* game = create_game();

    // Виконуємо команди
    execute_command(game, command1);
    execute_command(game, command2);

    // Створюємо рюкзак
    struct backpack* backpack = create_backpack(10);

    // Додаємо предмети до рюкзака
    add_item_to_backpack(backpack, item1);
    add_item_to_backpack(backpack, item2);

    // Виводимо предмети з рюкзака
    struct item* retrieved_item = get_item_from_backpack(backpack, "Item 1");
    if (retrieved_item != NULL) {
        printf("Retrieved item from backpack: %s\n", retrieved_item->name);
    } else {
        printf("Item not found in backpack!\n");
    }

    // Вивільняємо пам'ять
    room1 = destroy_room(room1);
    room2 = destroy_room(room2);
    room3 = destroy_room(room3);
    item1 = destroy_item(item1);
    item2 = destroy_item(item2);
    item3 = destroy_item(item3);
    command1 = destroy_command(command1);
    command2 = destroy_command(command2);
    game = destroy_game(game);
    backpack = destroy_backpack(backpack);

    return 0;
}
