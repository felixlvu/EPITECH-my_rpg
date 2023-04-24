/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_struct_item
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/inventory.h"

void item_struct_alloc(item_t *item)
{
    item->sword = malloc(sizeof(sword_t));
}

void setup_item(item_t *item)
{
    item->sword->sprt = sfSprite_create();
    item->sword->text = sfTexture_createFromFile
    ("./src/inventory/assets/sword.png", NULL);
    sfSprite_setTexture(item->sword->sprt, item->sword->text, sfTrue);
    sfSprite_setScale(item->sword->sprt, (sfVector2f){2, 2});
    sfSprite_setPosition(item->sword->sprt, (sfVector2f){22.5, 372.5});
    item->sword->in_inventory = sfFalse;
    item->sword->pos = (sfVector2f){22.5, 372.5};
    item->is_selected = sfFalse;
}

void setup_chained_list_case_sidebar(inventory_t *inventory)
{
    inventory->case_sb->bounds = (sfFloatRect){20, 370, 80, 80};
    inventory->case_sb->head = inventory->case_sb;
    inventory->case_sb->prev = NULL;
    inventory->case_sb->next = NULL;
    for (int i = 0; i < 4; i++) {
        inventory->case_sb->next = malloc(sizeof(case_sb_chained_t));
        inventory->case_sb->next->prev = inventory->case_sb;
        inventory->case_sb->next->head = inventory->case_sb->head;
        inventory->case_sb->next->bounds =
        (sfFloatRect){20, 460 + (i * 90), 80, 80};
        inventory->case_sb = inventory->case_sb->next;
        inventory->case_sb->next = NULL;
    }
}

void add_node_container(inventory_t *inventory, int a, int b)
{
    inventory->case_container->next = malloc(sizeof(case_container_t));
    inventory->case_container->next->prev = inventory->case_container;
    inventory->case_container->next->head =
    inventory->case_container->head;
    inventory->case_container->next->bounds =
    (sfFloatRect){a, b, 80, 80};
    inventory->case_container = inventory->case_container->next;
    inventory->case_container->next = NULL;
}

void setup_chained_list_case_container(inventory_t *inventory)
{
    inventory->case_container->bounds = (sfFloatRect){700, 820, 80, 80};
    inventory->case_container->next = NULL;
    inventory->case_container->prev = NULL;
    inventory->case_container->head = inventory->case_container;
    for (int i = 0; i < 12; i++) {
        if (i < 5)
            add_node_container(inventory, 790 + (90 * i), 820);
        else
            add_node_container(inventory, 700 + (90 * (i - 5)), 910);
    }
}
