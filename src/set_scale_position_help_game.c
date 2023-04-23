/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** menu.c
*/

#include <stdlib.h>
#include "include/42.h"
#include "include/functions_play_map.h"
#include "include/window_func.h"
#include "include/main_menu_struct.h"
#include "include/main_menu.h"

void set_scale_help_button_game(menu_info_t *menu)
{
    sfVector2f scale_global = {1, 1};

    sfSprite_setScale(menu->music_select_sprite, scale_global);
    sfSprite_setScale(menu->yes_sprite, scale_global);
    sfSprite_setScale(menu->resolution_select_sprite, scale_global);
    sfSprite_setScale(menu->close_info_sprite, scale_global);
}

menu_info_t *set_position_scale_help_game
(project_info_t *info, menu_info_t *menu, sfVector2f pixPos)
{
    sfVector2u window_size = sfRenderWindow_getSize(info->window);
    sfVector2f pos_close_info = {710 + pixPos.x, 760 + pixPos.y};
    sfVector2f pos_fullscreen = {608 + pixPos.x, 346 + pixPos.y};
    sfVector2f pos_music_select = {916 + pixPos.x, 488 + pixPos.y};

    if (menu->pos_music == 1)
        pos_music_select = (sfVector2f){782 + pixPos.x, 488 + pixPos.y};
    if (menu->pos_music == 2)
        pos_music_select = (sfVector2f){662 + pixPos.x, 488 + pixPos.y};
    sfVector2f pos_resolution_select = {942 + pixPos.x, 619 + pixPos.y};
    if (window_size.x == 800 && window_size.y == 600)
        pos_resolution_select = (sfVector2f){737 + pixPos.x, 619 + pixPos.y};
    set_scale_help_button_game(menu);
    sfSprite_setPosition(menu->yes_sprite, pos_fullscreen);
    sfSprite_setPosition(menu->close_info_sprite, pos_close_info);
    sfSprite_setPosition(menu->music_select_sprite, pos_music_select);
    sfSprite_setPosition(menu->resolution_select_sprite, pos_resolution_select);
    return (menu);
}