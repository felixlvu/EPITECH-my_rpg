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

void check_button_music_played(menu_info_t *menu)
{
    if (menu->music == 1) {
        sfMusic_pause(menu->music_menu);
        menu->music = 0;
    } else {
        sfMusic_play(menu->music_menu);
        menu->music = 1;
    }
}

int check_button_music(project_info_t *info, menu_info_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(info->window);
    sfVector2f music_pos = sfSprite_getPosition(menu->music_sprite);

    if (mouse_pos.x >= music_pos.x && mouse_pos.x <= music_pos.x + 300 &&
    mouse_pos.y >= music_pos.y && mouse_pos.y <= music_pos.y + 100) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            check_button_music_played(menu);
        }
    }
    return (0);
}
