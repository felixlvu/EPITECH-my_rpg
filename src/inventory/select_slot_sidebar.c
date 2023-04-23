/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** select_slot_sidebar
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "../include/inventory.h"

void select_slot_with_numx(inventory_t *inventory)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum1))
        sfSprite_setPosition(inventory->selected->sprt, (sfVector2f){15, 365});
    if (sfKeyboard_isKeyPressed(sfKeyNum2))
        sfSprite_setPosition(inventory->selected->sprt, (sfVector2f){15, 455});
    if (sfKeyboard_isKeyPressed(sfKeyNum3))
        sfSprite_setPosition(inventory->selected->sprt, (sfVector2f){15, 545});
    if (sfKeyboard_isKeyPressed(sfKeyNum4))
        sfSprite_setPosition(inventory->selected->sprt, (sfVector2f){15, 635});
}

void select_slot_with_up(inventory_t *inventory)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) && !inventory->isUpKeyPressed) {
        if (sfSprite_getPosition(inventory->selected->sprt).y == 365)
            sfSprite_setPosition(inventory->selected->sprt,
            (sfVector2f){15, 635});
        else {
            sfSprite_setPosition(inventory->selected->sprt, (sfVector2f){15, sfSprite_getPosition(inventory->selected->sprt).y - 90});
        }
        inventory->isUpKeyPressed = sfTrue;
    } else if (!sfKeyboard_isKeyPressed(sfKeyUp))
        inventory->isUpKeyPressed = sfFalse;
}

void select_slot_with_down(inventory_t *inventory)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) && !inventory->isDownKeyPressed) {
        if (sfSprite_getPosition(inventory->selected->sprt).y == 635)
            sfSprite_setPosition(inventory->selected->sprt,
            (sfVector2f){15, 365});
        else {
            sfSprite_setPosition(inventory->selected->sprt, (sfVector2f){15, sfSprite_getPosition(inventory->selected->sprt).y + 90});
        }
        inventory->isDownKeyPressed = sfTrue;
    } else if (!sfKeyboard_isKeyPressed(sfKeyDown))
        inventory->isDownKeyPressed = sfFalse;
}

void select_slot_with_arraow(inventory_t *inventory)
{
    select_slot_with_up(inventory);
    select_slot_with_down(inventory);
}

void select_slot_sidebar(inventory_t *inventory)
{
    if (!inventory->is_open) {
        select_slot_with_numx(inventory);
        select_slot_with_arraow(inventory);
    }
}
