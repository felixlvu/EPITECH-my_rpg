/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** set_possition_button.c
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../include/main_menu_struct.h"
#include "../include/main_menu.h"

menu_info_t *set_position_help_music(menu_info_t *menu, sfVector2u window_size,
sfVector2f pos_music_select)
{
    if (menu->pos_music == 1)
        pos_music_select = (sfVector2f){((782 * window_size.x) / 1920.0),
        ((488 * window_size.y) / 1080.0)};
    if (menu->pos_music == 2)
        pos_music_select = (sfVector2f){((662 * window_size.x) / 1920.0),
        ((488 * window_size.y) / 1080.0)};
    sfVector2f pos_resolution_select = {((942 * window_size.x) / 1920.0),
    ((619 * window_size.y) / 1080.0)};
    if (window_size.x == 800 && window_size.y == 600)
        pos_resolution_select = (sfVector2f){((737 * window_size.x) / 1920.0),
        ((619 * window_size.y) / 1080.0)};
    sfSprite_setPosition(menu->music_select_sprite, pos_music_select);
    sfSprite_setPosition(menu->resolution_select_sprite, pos_resolution_select);
    return (menu);
}

menu_info_t *set_position_help_button(project_info_t *info,
menu_info_t *menu, sfVector2u window_size)
{
    sfVector2f scale = (sfVector2f){((1 * window_size.x) / 1920.0),
    ((1 * window_size.y) / 1080.0)};
    sfVector2f pos_background = {0, 0};
    sfVector2f pos_button_setting = {((1800 * window_size.x) / 1920.0),
    ((950 * window_size.y) / 1080.0)};
    sfVector2f pos_close_info = {((1260 * window_size.x) / 1920.0),
    ((280 * window_size.y) / 1080.0)};
    sfVector2f pos_fullscreen = {((608 * window_size.x) / 1920.0),
    ((346 * window_size.y) / 1080.0)};
    sfVector2f pos_music_select = {((916 * window_size.x) / 1920.0),
    ((488 * window_size.y) / 1080.0)};
    set_position_help_music(menu, window_size, pos_music_select);
    set_scale_button(menu, scale);
    set_position_button(menu, pos_background, pos_fullscreen, pos_close_info);
    sfSprite_setPosition(menu->help_sprite, pos_button_setting);
    return (menu);
}

menu_info_t *set_position_sound_button(project_info_t *info, menu_info_t *menu)
{
    sfVector2u window_size = sfRenderWindow_getSize(info->window);
    sfVector2f scale = (sfVector2f){((1 * window_size.x) / 1920.0),
    ((1 * window_size.y) / 1080.0)};
    sfVector2f pos = {20, 20};
    sfSprite_setScale(menu->music_sprite, scale);
    sfSprite_setPosition(menu->music_sprite, pos);
    sfSprite_setScale(menu->no_music_sprite, scale);
    sfSprite_setPosition(menu->no_music_sprite, pos);
    return (menu);
}

menu_info_t *set_position_menu(project_info_t *info, menu_info_t *menu)
{
    sfVector2u window_size = sfRenderWindow_getSize(info->window);
    sfVector2f scale = (sfVector2f){((1 * window_size.x) / 1920.0),
    ((1 * window_size.y) / 1080.0)};
    sfVector2f pos = {0, 0};
    sfSprite_setScale(menu->menu_sprite, scale);
    sfSprite_setPosition(menu->menu_sprite, pos);
    return (menu);
}
