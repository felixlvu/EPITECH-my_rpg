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

int check_button_help(menu_info_t *menu, sfVector2i mouse_pos)
{
    sfVector2f help_pos = sfSprite_getPosition(menu->help_sprite);

    if (mouse_pos.x >= help_pos.x && mouse_pos.x <= help_pos.x + 300 &&
    mouse_pos.y >= help_pos.y && mouse_pos.y <= help_pos.y + 100) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            menu->info_menu = 1;
    }
    return (0);
}

int check_button_main_menu(project_info_t *info, menu_info_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(info->window);
    sfVector2f play_pos = sfSprite_getPosition(menu->play_sprite);
    sfVector2f exit_pos = sfSprite_getPosition(menu->exit_sprite);
    if (mouse_pos.x >= play_pos.x && mouse_pos.x <= play_pos.x + 222 &&
    mouse_pos.y >= play_pos.y && mouse_pos.y <= play_pos.y + 174) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            info->state_menu = 1;
        return (0);
    }
    if (mouse_pos.x >= exit_pos.x && mouse_pos.x <= exit_pos.x + 222 &&
        mouse_pos.y >= exit_pos.y && mouse_pos.y <= exit_pos.y + 174) {
            if (sfMouse_isButtonPressed(sfMouseLeft))
                sfRenderWindow_close(info->window);
        return (0);
    }
    check_button_help(menu, mouse_pos);
    return (0);
}

int check_button(project_info_t *info, menu_info_t *menu)
{
    check_button_main_menu(info, menu);
    check_button_music(info, menu);
    check_button_music_100(menu,
    sfMouse_getPositionRenderWindow(info->window),
    sfRenderWindow_getSize(info->window));
    check_button_music_50(menu,
    sfMouse_getPositionRenderWindow(info->window),
    sfRenderWindow_getSize(info->window));
    check_button_music_25(menu,
    sfMouse_getPositionRenderWindow(info->window),
    sfRenderWindow_getSize(info->window));
    check_button_resolution_800(info, menu,
    sfMouse_getPositionRenderWindow(info->window),
    sfRenderWindow_getSize(info->window));
    check_button_resolution_1920(info, menu,
    sfMouse_getPositionRenderWindow(info->window),
    sfRenderWindow_getSize(info->window));
    return (0);
}
