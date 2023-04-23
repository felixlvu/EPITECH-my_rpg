/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** move_item_sidebar
*/

#include <SFML/Graphics.h>
#include "../include/inventory.h"

void change_isselected_value_item(item_t *item, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(item->sword->sprt);

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            item->is_selected = sfTrue;
        } else
            item->is_selected = sfFalse;
    }
}

void if_intersect_sidebar(item_t *item, inventory_t *inventory)
{
    sfSprite_setPosition(item->sword->sprt, (sfVector2f)
    {inventory->case_sb->bounds.left + 5,
    inventory->case_sb->bounds.top + 5});
    item->sword->in_inventory = sfFalse;
    item->sword->pos = (sfVector2f){sfSprite_getPosition
    (item->sword->sprt).x,
    sfSprite_getPosition(item->sword->sprt).y};
}

void place_item_sidebar
(inventory_t *inventory, item_t *item, sfFloatRect bounds)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_intersects
        (&bounds, &inventory->case_sb->bounds, NULL)) {
            if_intersect_sidebar(item, inventory);
        }
    }
}

void check_collision_sidebar_slot(inventory_t *inventory, item_t *item)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(item->sword->sprt);

    inventory->case_sb = inventory->case_sb->head;
    while (inventory->case_sb->next != NULL) {
        place_item_sidebar(inventory, item, bounds);
        inventory->case_sb = inventory->case_sb->next;
    }
}

void move_item_sidebar(inventory_t *inventory,
item_t *item, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    change_isselected_value_item(item, window);
    if (item->is_selected) {
        sfSprite_setPosition(item->sword->sprt,
        (sfVector2f){mouse_pos.x - 25, mouse_pos.y - 25});
    }
    check_collision_sidebar_slot(inventory, item);
}
