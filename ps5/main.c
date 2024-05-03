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
    // Створення деяких прикладових структур даних
    struct room room1 = { .name = "Room 1" };
    struct item item1 = { .name = "Item 1" };
    struct command command1 = { .name = "Command 1" };

    // Створення контейнерів та додавання їх до списку
    struct container* container_list = NULL;
    container_list = create_container(container_list, ROOM, &room1);
    container_list = create_container(container_list, ITEM, &item1);
    container_list = create_container(container_list, COMMAND, &command1);

    // Створення гри
    struct game* game = create_game(container_list);

    // Створення рюкзака
    struct backpack* backpack = create_my_backpack(5);

    // Створення світу
    struct container* world = create_world();

    // Створення парсера
    struct parser* parser = create_parser();

    // Розбір команд
    struct command* cmd = parse_input(parser, "your_command_string_here");

    // Виконання команди
    execute_command(game, cmd);

    // Отримання предмета зі списку контейнера за іменем
    struct item* retrieved_item = (struct item*)get_from_container_by_name(container_list, "Item 1");
    if (retrieved_item != NULL) {
        printf("Retrieved item: %s\n", retrieved_item->name);
    } else {
        printf("Item not found!\n");
    }

    // Видалення предмета зі списку контейнера
    container_list = remove_container(container_list, &item1);

    // Видалення списку контейнера для звільнення пам'яті
    container_list = destroy_containers(container_list);

    // Звільнення пам'яті, що використовується грою, рюкзаком і світом
    game = destroy_game(game);
    backpack = destroy_my_backpack(backpack);
    world = destroy_world(world);
    parser = destroy_parser(parser);

    return 0;
}
