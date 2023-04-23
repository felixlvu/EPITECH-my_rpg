/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** window_func.h
*/

#include "42.h"
#include "functions_play_map.h"

#ifndef WINDOW_FUNC_H_
	#define WINDOW_FUNC_H_

    project_info_t *create_window(project_info_t *info, int x, int y);
    project_info_t *draw_fond(project_info_t *info);
    int display_window(project_info_t *info);
    int get_event(project_info_t *info, sfEvent *event, rpg_player *player);
    void update_view(project_info_t *info, rpg_player *player);

#endif /*WINDOW_FUNC_H_*/
