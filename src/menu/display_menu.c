/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** display_menu.c
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../include/main_menu_struct.h"
#include "../include/main_menu.h"

void check_over_button(project_info_t *info, menu_info_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(info->window);
    sfVector2f play_pos = sfSprite_getPosition(menu->play_sprite);
    sfVector2f exit_pos = sfSprite_getPosition(menu->exit_sprite);
    sfVector2f help_pos = sfSprite_getPosition(menu->help_sprite);
    if (mouse_pos.x >= play_pos.x && mouse_pos.x <= play_pos.x + 222 &&
        mouse_pos.y >= play_pos.y && mouse_pos.y <= play_pos.y + 174)
        sfSprite_setTexture(menu->play_sprite, menu->play_over_texture, sfTrue);
    else
        sfSprite_setTexture(menu->play_sprite, menu->play_texture, sfTrue);
    if (mouse_pos.x >= help_pos.x && mouse_pos.x <= help_pos.x + 66 &&
        mouse_pos.y >= help_pos.y && mouse_pos.y <= help_pos.y + 75)
        sfSprite_setTexture(menu->help_sprite, menu->help_over_texture, sfTrue);
    else
        sfSprite_setTexture(menu->help_sprite, menu->help_texture, sfTrue);
    if (mouse_pos.x >= exit_pos.x && mouse_pos.x <= exit_pos.x + 222 &&
        mouse_pos.y >= exit_pos.y && mouse_pos.y <= exit_pos.y + 174)
        sfSprite_setTexture(menu->exit_sprite, menu->exit_over_texture, sfTrue);
    else
        sfSprite_setTexture(menu->exit_sprite, menu->exit_texture, sfTrue);
}

void display_settings(project_info_t *info, menu_info_t *menu, int index)
{
    if (index == 0)
        sfRenderWindow_drawSprite(info->window, menu->info_sprite, NULL);
    if (index == 1)
        sfRenderWindow_drawSprite(info->window, menu->info_game_sprite, NULL);
    sfRenderWindow_drawSprite(info->window, menu->no_sprite, NULL);
    sfRenderWindow_drawSprite(info->window, menu->music_select_sprite, NULL);
    sfRenderWindow_drawSprite(info->window, menu->close_info_sprite, NULL);
    sfRenderWindow_drawSprite(info->window,
    menu->resolution_select_sprite, NULL);
    if (menu->fullscreen == 0)
        sfRenderWindow_drawSprite(info->window, menu->no_sprite, NULL);
    if (menu->fullscreen == 1)
        sfRenderWindow_drawSprite(info->window, menu->yes_sprite, NULL);
    if (check_event(info, menu) == 1)
        menu->info_menu = 0;
}

void display_main_menu(project_info_t *info, menu_info_t *menu)
{
    sfRenderWindow_clear(info->window, sfBlack);
    check_over_button(info, menu);
    sfRenderWindow_drawSprite(info->window, menu->menu_sprite, NULL);
    sfRenderWindow_drawSprite(info->window, menu->load_sprite, NULL);
    sfRenderWindow_drawSprite(info->window, menu->exit_sprite, NULL);
    sfRenderWindow_drawSprite(info->window, menu->play_sprite, NULL);
    sfRenderWindow_drawSprite(info->window, menu->help_sprite, NULL);
}

int display_menu(project_info_t *info, menu_info_t *menu)
{
    if (menu->info_menu == 1) {
        display_settings(info, menu, 0);
    } else {
        display_main_menu(info, menu);
    }
    if (menu->music == 1)
        sfRenderWindow_drawSprite(info->window, menu->music_sprite, NULL);
    else
        sfRenderWindow_drawSprite(info->window, menu->no_music_sprite, NULL);
    sfRenderWindow_display(info->window);
    return (0);
}
