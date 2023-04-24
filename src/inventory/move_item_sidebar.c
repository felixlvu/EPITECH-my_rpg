/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** move_item_sidebar
*/

#include <SFML/Graphics.h>
#include "../include/inventory.h"

void change_isselected_value_item(item_t *item,
sfRenderWindow *window, sfView *view)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(item->sword->sprt);
    mouse_pos =
    (sfVector2i) {mouse_pos.x + sfView_getCenter(view).x - 960,
    mouse_pos.y + sfView_getCenter(view).y - 540};

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            item->is_selected = sfTrue;
        } else
            item->is_selected = sfFalse;
    }
}

void if_intersect_sidebar(item_t *item, inventory_t *inventory, sfVector2f coo)
{
    item->sword->pos =
    (sfVector2f){inventory->case_sb->bounds.left + 7.5 -
    coo.x, inventory->case_sb->bounds.top - coo.y + 7.5};
    item->sword->in_inventory = sfFalse;
}

void place_item_sidebar
(inventory_t *inventory, item_t *item, sfFloatRect bounds, sfVector2f coo)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_intersects
        (&bounds, &inventory->case_sb->bounds, NULL)) {
            if_intersect_sidebar(item, inventory, coo);
        }
    }
}

void check_collision_sidebar_slot(inventory_t *inventory,
item_t *item, sfVector2f coo)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(item->sword->sprt);

    inventory->case_sb = inventory->case_sb->head;
    while (inventory->case_sb->next != NULL) {
        place_item_sidebar(inventory, item, bounds, coo);
        inventory->case_sb = inventory->case_sb->next;
    }
}

void move_item_sidebar(inventory_t *inventory,
item_t *item, sfRenderWindow *window, sfView *view)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f coo = sfView_getCenter(view);
    coo = (sfVector2f){coo.x - 960, coo.y - 540};

    change_isselected_value_item(item, window, view);
    if (item->is_selected)
        item->sword->pos = (sfVector2f){mouse_pos.x - 25, mouse_pos.y - 5};
    check_collision_sidebar_slot(inventory, item, coo);
}
