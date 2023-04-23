/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** start_menu.c
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../include/main_menu_struct.h"
#include "../include/main_menu.h"

void check_button_resolution_1920(project_info_t *info, menu_info_t *menu,
sfVector2i mouse_pos, sfVector2u window_size)
{
    sfVector2f resoltion_1920 = {((942 * window_size.x) / 1920.0),
    ((619 * window_size.y) / 1080.0)};

    if (mouse_pos.x >= resoltion_1920.x && mouse_pos.x <= resoltion_1920.x + 100
    && mouse_pos.y >= resoltion_1920.y
    && mouse_pos.y <= resoltion_1920.y + 100) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRenderWindow_close(info->window);
            sfRenderWindow_destroy(info->window);
            info->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
            "My_RPG", sfResize | sfClose, NULL);
            set_all_postion_button(info, menu);
        }
    }
}

void check_button_resolution_800(project_info_t *info, menu_info_t *menu,
sfVector2i mouse_pos, sfVector2u window_size)
{
    sfVector2f resoltion_800 = {((737 * window_size.x) / 1920.0),
    ((619 * window_size.y) / 1080.0)};

    if (mouse_pos.x >= resoltion_800.x && mouse_pos.x <= resoltion_800.x + 100
    && mouse_pos.y >= resoltion_800.y && mouse_pos.y <= resoltion_800.y + 100) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRenderWindow_close(info->window);
            sfRenderWindow_destroy(info->window);
            info->window = sfRenderWindow_create
            ((sfVideoMode){800, 600, 16}, "My_RPG", sfResize | sfClose, NULL);
            set_all_postion_button(info, menu);
        }
    }
}

void check_button_music_100(menu_info_t *menu,
sfVector2i mouse_pos, sfVector2u window_size)
{
    sfVector2f music_100 = {((915 * window_size.x) / 1920.0),
    ((488 * window_size.y) / 1080.0)};

    if (mouse_pos.x >= music_100.x && mouse_pos.x <= music_100.x + 100 &&
    mouse_pos.y >= music_100.y && mouse_pos.y <= music_100.y + 100) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_setVolume(menu->music_menu, 100);
            sfSprite_setPosition(menu->music_select_sprite, music_100);
            menu->pos_music = 0;
        }
    }
}

void check_button_music_50(menu_info_t *menu,
sfVector2i mouse_pos, sfVector2u window_size)
{
    sfVector2f music_50 = {((782 * window_size.x) / 1920.0),
    ((488 * window_size.y) / 1080.0)};

    if (mouse_pos.x >= music_50.x && mouse_pos.x <= music_50.x + 100 &&
    mouse_pos.y >= music_50.y && mouse_pos.y <= music_50.y + 100) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_setVolume(menu->music_menu, 50);
            sfSprite_setPosition(menu->music_select_sprite, music_50);
            menu->pos_music = 1;
        }
    }
}

void check_button_music_25(menu_info_t *menu,
sfVector2i mouse_pos, sfVector2u window_size)
{
    sfVector2f music_25 = {((662 * window_size.x) / 1920.0),
    ((488 * window_size.y) / 1080.0)};

    if (mouse_pos.x >= music_25.x && mouse_pos.x <= music_25.x + 100 &&
    mouse_pos.y >= music_25.y && mouse_pos.y <= music_25.y + 100) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_setVolume(menu->music_menu, 25);
            sfSprite_setPosition(menu->music_select_sprite, music_25);
            menu->pos_music = 2;
        }
    }
}
