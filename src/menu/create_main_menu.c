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

menu_info_t *set_all_postion_button(project_info_t *info, menu_info_t *menu)
{
    sfVector2u window_size = sfRenderWindow_getSize(info->window);
    menu = set_position_new_button(info, menu);
    menu = set_position_load_button(info, menu);
    menu = set_position_exit_button(info, menu);
    menu = set_position_help_button(info, menu, window_size);
    menu = set_position_sound_button(info, menu);
    menu = set_position_menu(info, menu);
    return (menu);
}

menu_info_t *create_button(project_info_t *info, menu_info_t *menu)
{
    menu = create_new_button(menu);
    menu = create_load_button(menu);
    menu = create_exit_button(menu);
    menu = create_help_button(menu);
    menu = create_help_select_button(menu);
    menu = create_sound_button(menu);
    menu = set_all_postion_button(info, menu);
    return (menu);
}

menu_info_t *create_menu(project_info_t *info, menu_info_t *menu)
{
    menu = malloc(sizeof(menu_info_t));
    menu->music = 1;
    menu->info_menu = 0;
    menu->fullscreen = 0;
    menu->pos_music = 0;
    menu->menu_texture = sfTexture_createFromFile("assets_menu/Menu.jpg", NULL);
    menu->menu_sprite = sfSprite_create();
    sfSprite_setTexture(menu->menu_sprite, menu->menu_texture, sfTrue);
    menu = create_button(info, menu);
    return (menu);
}
