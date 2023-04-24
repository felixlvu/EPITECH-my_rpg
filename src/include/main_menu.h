/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** main_menu.h
*/

#include <SFML/Graphics.h>
#include <SFML/System/Types.h>
#include <stdbool.h>
#include "42.h"
#include "inventory.h"

#ifndef B_MUL_200_TLS_2_1_MYRPG_LOUIS_HUGUET_FUNCTIONS_MAIN_MENU_H
    #define B_MUL_200_TLS_2_1_MYRPG_LOUIS_HUGUET_FUNCTIONS_MAIN_MENU_H

    void check_button_music_25(menu_info_t *menu,
    sfVector2i mouse_pos, sfVector2u window_size);
    void check_button_music_50(menu_info_t *menu,
    sfVector2i mouse_pos, sfVector2u window_size);
    void check_button_music_100(menu_info_t *menu,
    sfVector2i mouse_pos, sfVector2u window_size);
    void check_button_resolution_800(project_info_t *info, menu_info_t *menu,
    sfVector2i mouse_pos, sfVector2u window_size);
    void check_button_resolution_1920(project_info_t *info, menu_info_t *menu,
    sfVector2i mouse_pos, sfVector2u window_size);
    menu_info_t *set_position_sound_button(project_info_t *info,
    menu_info_t *menu);
    menu_info_t *create_help_select_button(menu_info_t *menu);
    menu_info_t *set_position_exit_button(project_info_t *info,
    menu_info_t *menu);
    menu_info_t *set_position_load_button(project_info_t *info,
    menu_info_t *menu);
    menu_info_t *set_position_new_button(project_info_t *info,
    menu_info_t *menu);
    menu_info_t *set_all_postion_button(project_info_t *info,
    menu_info_t *menu);
    menu_info_t *create_sound_button(menu_info_t *menu);
    menu_info_t *create_help_button(menu_info_t *menu);
    menu_info_t *create_exit_button(menu_info_t *menu);
    menu_info_t *create_load_button(menu_info_t *menu);
    menu_info_t *create_new_button(menu_info_t *menu);
    menu_info_t *set_position_help_button(project_info_t *info,
    menu_info_t *menu, sfVector2u window_size);
    menu_info_t *create_button(project_info_t *info, menu_info_t *menu);
    menu_info_t *create_menu(project_info_t *info, menu_info_t *menu);
    void set_position_button(menu_info_t *menu, sfVector2f pos_background,
    sfVector2f pos_fullscreen, sfVector2f pos_close_info);
    void set_scale_button(menu_info_t *menu, sfVector2f scale);
    int check_button(project_info_t *info, menu_info_t *menu);
    int check_button_music(project_info_t *info, menu_info_t *menu);
    int display_menu(project_info_t *info, menu_info_t *menu);
    int check_event(project_info_t *info, menu_info_t *menu);
    void display_settings(project_info_t *info, menu_info_t *menu, int index);
    menu_info_t *set_position_menu(project_info_t *info, menu_info_t *menu);
    void check_event_fullscreen(project_info_t *info, menu_info_t *menu);
    void displays(world_tile *txt, project_info_t *info, rpg_player *player, char** map, menu_info_t *menu, sfVector2f pixel_pos, sfEvent *event, inventory_t *inventory, item_t *item, sfRenderWindow *window);
#endif