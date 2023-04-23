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

menu_info_t *create_new_button(menu_info_t *menu)
{
    menu->play_texture = sfTexture_createFromFile("assets_menu/New.png", NULL);
    menu->play_sprite = sfSprite_create();
    sfSprite_setTexture(menu->play_sprite, menu->play_texture, sfTrue);
    menu->play_over_texture = sfTexture_createFromFile
    ("assets_menu/NewOver.png", NULL);
    return (menu);
}

menu_info_t *create_load_button(menu_info_t *menu)
{
    menu->load_texture = sfTexture_createFromFile("assets_menu/Load.png", NULL);
    menu->load_sprite = sfSprite_create();
    sfSprite_setTexture(menu->load_sprite, menu->load_texture, sfTrue);
    return (menu);
}

menu_info_t *create_exit_button(menu_info_t *menu)
{
    menu->exit_texture = sfTexture_createFromFile("assets_menu/Exit.png", NULL);
    menu->exit_sprite = sfSprite_create();
    sfSprite_setTexture(menu->exit_sprite, menu->exit_texture, sfTrue);
    menu->exit_over_texture = sfTexture_createFromFile
    ("assets_menu/ExitOver.png", NULL);
    return (menu);
}

menu_info_t *create_help_select_button(menu_info_t *menu)
{
    menu->yes_texture = sfTexture_createFromFile("assets_menu/yes.jpg", NULL);
    menu->yes_sprite = sfSprite_create();
    sfSprite_setTexture(menu->yes_sprite, menu->yes_texture, sfTrue);
    menu->no_texture = sfTexture_createFromFile("assets_menu/no.jpg", NULL);
    menu->no_sprite = sfSprite_create();
    sfSprite_setTexture(menu->no_sprite, menu->no_texture, sfTrue);
    menu->music_select_texture = sfTexture_createFromFile
    ("assets_menu/yes.jpg", NULL);
    menu->music_select_sprite = sfSprite_create();
    sfSprite_setTexture
    (menu->music_select_sprite, menu->music_select_texture, sfTrue);
    menu->resolution_select_texture = sfTexture_createFromFile
    ("assets_menu/yes.jpg", NULL);
    menu->resolution_select_sprite = sfSprite_create();
    sfSprite_setTexture
    (menu->resolution_select_sprite, menu->resolution_select_texture, sfTrue);
    return (menu);
}

menu_info_t *create_help_button(menu_info_t *menu)
{
    menu->help_texture = sfTexture_createFromFile("assets_menu/Help.png", NULL);
    menu->help_over_texture = sfTexture_createFromFile
    ("assets_menu/HelpOver.png", NULL);
    menu->help_sprite = sfSprite_create();
    sfSprite_setTexture(menu->help_sprite, menu->help_texture, sfTrue);
    menu->info_texture = sfTexture_createFromFile("assets_menu/info.jpg", NULL);
    menu->info_sprite = sfSprite_create();
    sfSprite_setTexture(menu->info_sprite, menu->info_texture, sfTrue);
    menu->info_game_texture = sfTexture_createFromFile
    ("assets_menu/info_game.jpg", NULL);
    menu->info_game_sprite = sfSprite_create();
    sfSprite_setTexture(menu->info_game_sprite,
    menu->info_game_texture, sfTrue);
    menu->close_info_texture = sfTexture_createFromFile
    ("assets_menu/close.jpg", NULL);
    menu->close_info_sprite = sfSprite_create();
    sfSprite_setTexture(menu->close_info_sprite,
    menu->close_info_texture, sfTrue);
    return (menu);
}
