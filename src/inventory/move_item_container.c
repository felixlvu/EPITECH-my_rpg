/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** move_item_container
*/

#include <SFML/Graphics.h>
#include "../include/inventory.h"

void if_intersect(item_t *item, inventory_t *inventory, sfVector2f coo)
{
    item->sword->pos =
    (sfVector2f){inventory->case_container->bounds.left + 7.5 -
    coo.x, inventory->case_container->bounds.top - coo.y + 7.5};
    item->sword->in_inventory = sfTrue;
}

void place_item_container(inventory_t *inventory,
item_t *item, sfFloatRect bounds, sfVector2f coo)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_intersects
        (&bounds, &inventory->case_container->bounds, NULL)) {
            if_intersect(item, inventory, coo);
        }
    }
}

void check_collision_container_slot(inventory_t *inventory,
item_t *item, sfVector2f coo)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(item->sword->sprt);

    inventory->case_container = inventory->case_container->head;
    while (inventory->case_container->next != NULL) {
        place_item_container(inventory, item, bounds, coo);
        inventory->case_container = inventory->case_container->next;
    }
}

void move_item_container(inventory_t *inventory,
item_t *item, sfRenderWindow *window, sfView *view)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f coo = sfView_getCenter(view);
    coo = (sfVector2f){coo.x - 960, coo.y - 540};

    change_isselected_value_item(item, window, view);
    check_collision_container_slot(inventory, item, coo);
}
