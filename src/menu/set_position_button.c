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

menu_info_t *set_position_new_button(project_info_t *info, menu_info_t *menu)
{
    sfVector2u window_size = sfRenderWindow_getSize(info->window);
    sfVector2f scale = (sfVector2f){((1 * window_size.x) / 1920.0),
    ((1 * window_size.y) / 1080.0)};
    sfVector2f pos = {(580 * window_size.x) / 1920,
    (window_size.y * 800) / 1080};
    sfSprite_setScale(menu->play_sprite, scale);
    sfSprite_setPosition(menu->play_sprite, pos);
    return (menu);
}

menu_info_t *set_position_load_button(project_info_t *info, menu_info_t *menu)
{
    sfVector2u window_size = sfRenderWindow_getSize(info->window);
    sfVector2f scale = (sfVector2f){((1 * window_size.x) / 1920.0),
    ((1 * window_size.y) / 1080.0)};
    sfVector2f pos = {(870 * window_size.x) / 1920,
    (window_size.y * 800) / 1080};
    sfSprite_setScale(menu->load_sprite, scale);
    sfSprite_setPosition(menu->load_sprite, pos);
    return (menu);
}

menu_info_t *set_position_exit_button(project_info_t *info, menu_info_t *menu)
{
    sfVector2u window_size = sfRenderWindow_getSize(info->window);
    sfVector2f scale = (sfVector2f){((1 * window_size.x) / 1920.0),
    ((1 * window_size.y) / 1080.0)};
    sfVector2f pos = {(1170 * window_size.x) / 1920,
    (window_size.y * 800) / 1080};
    sfSprite_setScale(menu->exit_sprite, scale);
    sfSprite_setPosition(menu->exit_sprite, pos);
    return (menu);
}

void set_scale_button(menu_info_t *menu, sfVector2f scale)
{
    sfSprite_setScale(menu->help_sprite, scale);
    sfSprite_setScale(menu->info_sprite, scale);
    sfSprite_setScale(menu->menu_sprite, scale);
    sfSprite_setScale(menu->close_info_sprite, scale);
    sfSprite_setScale(menu->yes_sprite, scale);
    sfSprite_setScale(menu->no_sprite, scale);
    sfSprite_setScale(menu->music_select_sprite, scale);
    sfSprite_setScale(menu->resolution_select_sprite, scale);
}

void set_position_button(menu_info_t *menu, sfVector2f pos_background,
sfVector2f pos_fullscreen, sfVector2f pos_close_info)
{
    sfSprite_setPosition(menu->yes_sprite, pos_fullscreen);
    sfSprite_setPosition(menu->no_sprite, pos_fullscreen);
    sfSprite_setPosition(menu->close_info_sprite, pos_close_info);
    sfSprite_setPosition(menu->info_sprite, pos_background);
    sfSprite_setPosition(menu->menu_sprite, pos_background);
}
