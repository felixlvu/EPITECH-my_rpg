/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** start_menu.c
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include<time.h>
#include "../include/main_menu_struct.h"
#include "../include/main_menu.h"

void select_music(menu_info_t *menu)
{
    int music = 4;
    srand(time(NULL));
    music = rand() % 3;
    if (music == 0) {
        menu->music_menu = sfMusic_createFromFile("music_menu/music1.ogg");
    }
    if (music == 1) {
        menu->music_menu = sfMusic_createFromFile("music_menu/music2.ogg");
    }
    if (music == 2) {
        menu->music_menu = sfMusic_createFromFile("music_menu/music3.ogg");
    }
}

menu_info_t *create_sound_button(menu_info_t *menu)
{
    menu->music_texture = sfTexture_createFromFile
    ("assets_menu/Music.png", NULL);
    menu->music_sprite = sfSprite_create();
    sfSprite_setTexture(menu->music_sprite, menu->music_texture, sfTrue);
    menu->music_texture = sfTexture_createFromFile
    ("assets_menu/NoMusic.png", NULL);
    menu->no_music_sprite = sfSprite_create();
    sfSprite_setTexture(menu->no_music_sprite, menu->music_texture, sfTrue);
    select_music(menu);
    sfMusic_setVolume(menu->music_menu, 100);
    sfMusic_setLoop(menu->music_menu, sfTrue);
    sfMusic_play(menu->music_menu);

    return (menu);
}
