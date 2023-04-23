/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** move_item_container
*/

#include <SFML/Graphics.h>
#include "../include/inventory.h"

void if_intersect(item_t *item, inventory_t *inventory)
{
    sfSprite_setPosition(item->sword->sprt, (sfVector2f)
    {inventory->case_container->bounds.left + 5,
    inventory->case_container->bounds.top + 5});
    item->sword->in_inventory = sfTrue;
    item->sword->pos = (sfVector2f){sfSprite_getPosition
    (item->sword->sprt).x,
    sfSprite_getPosition(item->sword->sprt).y};
}

void place_item_container(inventory_t *inventory,
item_t *item, sfFloatRect bounds)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_intersects
        (&bounds, &inventory->case_container->bounds, NULL)) {
            if_intersect(item, inventory);
        }
    }
}

void check_collision_container_slot(inventory_t *inventory, item_t *item)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(item->sword->sprt);

    inventory->case_container = inventory->case_container->head;
    while (inventory->case_container->next != NULL) {
        place_item_container(inventory, item, bounds);
        inventory->case_container = inventory->case_container->next;
    }
}

void move_item_container(inventory_t *inventory,
item_t *item, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    change_isselected_value_item(item, window);
    if (item->is_selected) {
        sfSprite_setPosition(item->sword->sprt,
        (sfVector2f){mouse_pos.x - 25, mouse_pos.y - 25});
    }
    check_collision_container_slot(inventory, item);
}
