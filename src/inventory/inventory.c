/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory
*/

#include <SFML/Graphics.h>
#include "../include/inventory.h"

void change_isopen_value(inventory_t *inventory)
{
    if (inventory->is_open)
        inventory->is_open = sfFalse;
    else
        inventory->is_open = sfTrue;
}

void check_inventory_isopen(inventory_t *inventory)
{
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        if (!inventory->e_key_down)
            change_isopen_value(inventory);
        inventory->e_key_down = sfTrue;
    } else  {
        inventory->e_key_down = sfFalse;
    }
}

void draw_sprite_inventory(inventory_t *inventory,
item_t *item, sfRenderWindow *window)
{
    if (inventory->is_open)
        sfRenderWindow_drawSprite(window, inventory->menu->sprt, NULL);

    sfRenderWindow_drawSprite(window, inventory->sidebar->sprt, NULL);
    sfRenderWindow_drawSprite(window, inventory->selected->sprt, NULL);
    if (item->sword->in_inventory && inventory->is_open)
        sfRenderWindow_drawSprite(window, item->sword->sprt, NULL);
    else if (!item->sword->in_inventory)
        sfRenderWindow_drawSprite(window, item->sword->sprt, NULL);
}

void check_pos_out_window(item_t *item, sfVector2f coo)
{
    if (item->sword->pos.x + coo.x != sfSprite_getPosition(item->sword->sprt).x
    && item->sword->pos.y + coo.y !=
    sfSprite_getPosition(item->sword->sprt).y + coo.y)
        sfSprite_setPosition(item->sword->sprt, item->sword->pos);
}

void inventory_f(sfRenderWindow *window, inventory_t *inventory,
item_t *item, sfView *view)
{
    sfVector2f viewCenter = sfView_getCenter(view);
    sfVector2f viewSize = sfView_getSize(view);
    sfVector2f coo = {viewCenter.x - viewSize.x / 2.0f,
    viewCenter.y - viewSize.y / 2.0f};

    check_inventory_isopen(inventory);
    select_slot_sidebar(inventory);
    move_item_sidebar(inventory, item, window, view);
    move_item_container(inventory, item, window, view);
    check_pos_out_window(item, coo);
    move_with_view(inventory, item, view);
    draw_sprite_inventory(inventory, item, window);
}
