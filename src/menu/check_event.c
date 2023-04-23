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

void check_event_fullscreen(project_info_t *info, menu_info_t *menu)
{
    if (menu->fullscreen == 1) {
        menu->fullscreen = 0;
        sfRenderWindow_close(info->window);
        sfRenderWindow_destroy(info->window);
        info->window = sfRenderWindow_create
        ((sfVideoMode){1920, 1080, 32}, "My_RPG", sfResize | sfClose, NULL);
        set_all_postion_button(info, menu);
    } else {
        menu->fullscreen = 1;
        sfRenderWindow_close(info->window);
        sfRenderWindow_destroy(info->window);
        sfVideoMode mode = sfVideoMode_getDesktopMode();
        info->window = sfRenderWindow_create
        (mode, "My_RPG", sfFullscreen, NULL);
        sfRenderWindow_setPosition(info->window, (sfVector2i){0, 0});
        set_all_postion_button(info, menu);
    }
}

int check_event(project_info_t *info, menu_info_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(info->window);
    sfVector2f exit_pos = sfSprite_getPosition(menu->close_info_sprite);
    sfVector2f fullsc_pos = sfSprite_getPosition(menu->no_sprite);

    if (mouse_pos.x >= exit_pos.x && mouse_pos.x <= exit_pos.x + 300 &&
        mouse_pos.y >= exit_pos.y && mouse_pos.y <= exit_pos.y + 100) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                return (1);
            }
    }
    if (mouse_pos.x >= fullsc_pos.x && mouse_pos.x <= fullsc_pos.x + 300 &&
        mouse_pos.y >= fullsc_pos.y && mouse_pos.y <= fullsc_pos.y + 100) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                check_event_fullscreen(info, menu);
            }
    }
    return 0;
}
