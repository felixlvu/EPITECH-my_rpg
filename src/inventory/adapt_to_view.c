/*
** EPITECH PROJECT, 2023
** merge
** File description:
** adapt_to_view
*/

#include <SFML/Graphics.h>
#include "../include/inventory.h"

void update_list_sb(inventory_t *inventory, sfVector2f coo)
{
    inventory->case_sb = inventory->case_sb->head;
    inventory->case_sb->bounds.left = coo.x + 15;
    inventory->case_sb->bounds.top = coo.y + 365;
    for (int i = 0; inventory->case_sb->next != NULL; i++) {
        inventory->case_sb->next->bounds.left = coo.x + 15;
        inventory->case_sb->next->bounds.top = coo.y + 455 + (90 * i);
        inventory->case_sb = inventory->case_sb->next;
    }
}

void update_list_container(inventory_t *inventory, sfVector2f coo)
{
    inventory->case_container = inventory->case_container->head;
    for (int i = 0; i < 12; i++) {
        if (i <= 5) {
            inventory->case_container->bounds.left = coo.x + 695 + (90 * i);
            inventory->case_container->bounds.top = coo.y + 815;
            inventory->case_container = inventory->case_container->next;
        } else {
            inventory->case_container->bounds.left =
            coo.x + 695 + (90 * (i - 6));
            inventory->case_container->bounds.top = coo.y + 905;
            inventory->case_container = inventory->case_container->next;
        }
    }
}

void update_list_coo(inventory_t *inventory, sfVector2f coo)
{
    update_list_sb(inventory, coo);
    update_list_container(inventory, coo);
}

void move_with_view(inventory_t *inventory, item_t *item, sfView *view)
{
    sfVector2f viewCenter = sfView_getCenter(view);
    sfVector2f viewSize = sfView_getSize(view);

    sfVector2f coo = {viewCenter.x - viewSize.x / 2.0f,
    viewCenter.y - viewSize.y / 2.0f};
    sfSprite_setPosition(inventory->sidebar->sprt,
    (sfVector2f) {coo.x, coo.y + 350});
    sfSprite_setPosition(inventory->menu->sprt,
    (sfVector2f) {coo.x + 680, coo.y + 800});
    sfSprite_setPosition(inventory->selected->sprt,
    (sfVector2f) {coo.x + inventory->selected->pos.x,
    coo.y + inventory->selected->pos.y});
    sfSprite_setPosition(item->sword->sprt,
    (sfVector2f) {coo.x + item->sword->pos.x, coo.y + item->sword->pos.y});
    update_list_coo(inventory, coo);
}
