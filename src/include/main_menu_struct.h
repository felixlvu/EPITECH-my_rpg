/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** main_menu_struct.h
*/

#include <SFML/Graphics.h>
#include <SFML/System/Types.h>
#include <stdbool.h>
#include <SFML/Audio.h>

#ifndef main_menu_strcut_H_
    #define main_menu_strcut_H_

    typedef struct menu_info {
        int music_volume;
        int fullscreen;
        int info_menu;
        int index_menu;
        int pos_music;
        int music;

        sfTexture *menu_texture;
        sfSprite *menu_sprite;

        sfTexture *play_texture;
        sfSprite *play_sprite;

        sfTexture *load_texture;
        sfSprite *load_sprite;

        sfTexture *exit_texture;
        sfSprite *exit_sprite;

        sfTexture *help_texture;
        sfSprite *help_sprite;

        sfTexture *music_texture;
        sfSprite *music_sprite;

        sfSprite *no_music_sprite;

        sfTexture *info_texture;
        sfSprite *info_sprite;

        sfTexture *info_game_texture;
        sfSprite *info_game_sprite;

        sfTexture *close_info_texture;
        sfSprite *close_info_sprite;

        sfTexture *yes_texture;
        sfSprite *yes_sprite;

        sfTexture *no_texture;
        sfSprite *no_sprite;

        sfTexture *music_select_texture;
        sfSprite *music_select_sprite;

        sfTexture *resolution_select_texture;
        sfSprite *resolution_select_sprite;

        sfTexture *play_over_texture;
        sfTexture *exit_over_texture;
        sfTexture *help_over_texture;

        sfMusic *music_menu;
    } menu_info_t;

#endif