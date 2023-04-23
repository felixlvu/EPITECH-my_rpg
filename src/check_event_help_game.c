/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** menu.c
*/

#include <stdlib.h>
#include "include/42.h"
#include "include/functions_play_map.h"
#include "include/window_func.h"
#include "include/main_menu_struct.h"
#include "include/main_menu.h"

void check_event_button_resolution(project_info_t *info, menu_info_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(info->window);
    sfVector2u window_size = sfRenderWindow_getSize(info->window);

    check_button_music_25(menu, mouse_pos, window_size);
    check_button_music_50(menu, mouse_pos, window_size);
    check_button_music_100(menu, mouse_pos, window_size);
    check_button_resolution_800(info, menu, mouse_pos, window_size);
    check_button_resolution_1920(info, menu, mouse_pos, window_size);
}

void check_event_game(project_info_t *info, menu_info_t *menu, sfVector2f pixelPos)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(info->window);
    sfVector2f fullsc_pos = sfSprite_getPosition(menu->no_sprite);
    sfVector2f close_pos = sfSprite_getPosition(menu->close_info_sprite);

    if (mouse_pos.x >= fullsc_pos.x && mouse_pos.x <= fullsc_pos.x + 300 &&
        mouse_pos.y >= fullsc_pos.y && mouse_pos.y <= fullsc_pos.y + 100) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                check_event_fullscreen(info, menu);
            }
    }
    close_pos = (sfVector2f){close_pos.x - pixelPos.x, close_pos.y - pixelPos.y};
    if (mouse_pos.x >= close_pos.x && mouse_pos.x <= close_pos.x + 300 &&
        mouse_pos.y >= close_pos.y && mouse_pos.y <= close_pos.y + 100) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfRenderWindow_close(info->window);
            }
    }
    check_event_button_resolution(info, menu);
}
