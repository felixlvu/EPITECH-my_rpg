/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_struct
*/

#include <SFML/Graphics.h>
#include "../include/inventory.h"

void inventory_struct_alloc(inventory_t *inventory)
{
    inventory->sidebar = malloc(sizeof(inventory_sidebar_t));
    inventory->menu = malloc(sizeof(inventory_menu_t));
    inventory->selected = malloc(sizeof(inventory_selected_t));
    inventory->case_sb = malloc(sizeof(case_sb_chained_t));
    inventory->case_container = malloc(sizeof(case_container_t));
}

void setup_sprite_menu_inventory(inventory_t *inventory)
{
    inventory->menu->text = sfTexture_createFromFile
    ("./src/inventory/assets/menu.png", NULL);
    inventory->menu->sprt = sfSprite_create();
    sfSprite_setTexture(inventory->menu->sprt, inventory->menu->text, sfTrue);
    sfSprite_setScale(inventory->menu->sprt, (sfVector2f){5, 5});
    sfSprite_setPosition(inventory->menu->sprt, (sfVector2f){680, 800});
}

void setup_sprite_sidebar_inventory(inventory_t *inventory)
{
    inventory->sidebar->text = sfTexture_createFromFile
    ("./src/inventory/assets/sidebar.png", NULL);
    inventory->sidebar->sprt = sfSprite_create();
    sfSprite_setTexture
    (inventory->sidebar->sprt, inventory->sidebar->text, sfTrue);
    sfSprite_setScale(inventory->sidebar->sprt, (sfVector2f){5, 5});
    sfSprite_setPosition(inventory->sidebar->sprt, (sfVector2f){0, 350});
}

void setup_sprite_selected_inventory(inventory_t *inventory)
{
    inventory->selected->text = sfTexture_createFromFile
    ("./src/inventory/assets/static.png", NULL);
    inventory->selected->sprt = sfSprite_create();
    sfSprite_setTexture
    (inventory->selected->sprt, inventory->selected->text, sfTrue);
    sfSprite_setScale(inventory->selected->sprt, (sfVector2f){5, 5});
    sfSprite_setPosition(inventory->selected->sprt, (sfVector2f){15, 365});
}

void setup_inventory(inventory_t *inventory)
{
    setup_sprite_menu_inventory(inventory);
    setup_sprite_sidebar_inventory(inventory);
    setup_sprite_selected_inventory(inventory);
    inventory->is_open = sfFalse;
}
