/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** functions_play_map.h
*/

#include <SFML/Graphics.h>
#include <SFML/System/Types.h>
#include <stdbool.h>
#include "42.h"
#include "main_menu_struct.h"

#ifndef FUNCTIONS_PLAY_MAP_H_
	#define FUNCTIONS_PLAY_MAP_H_

    int display_tile(char elm, project_info_t* info, world_tile *txt);
    int display_world(world_tile *txt, project_info_t *info, char** map);
    void les_sprite(world_tile *txt);
    world_tile *create_world(world_tile *tiles);
    int check_cols(rpg_player *player, p_colision *colision);
    p_colision *set_colisions(world_tile *txt, p_colision *colision, char** map);
    int my_strlen(char* str);
    void check_ability(rpg_player *player, my_time *time_m);
    int ability(rpg_player *player, my_time *time_m);
    int update_perso(rpg_player *player, my_time *clock_m, p_colision *colisions);
    int display_perso(project_info_t *info, rpg_player *player);
    rpg_player *create_player(world_tile *txt, rpg_player *player, char** map);
    int my_clock(my_time *time, rpg_player *player);
    my_time *create_clock(my_time *clock);
    int display_Obj(world_tile *txt, project_info_t *info, char** map);
    void make_anim(rpg_player *player, my_time *time);
    int diags(rpg_player *player, p_colision *colision, my_time *clock);
    void perso_moovs(rpg_player *player, my_time *clock, p_colision *colisions);
    void set_monsters(world_tile *txt ,rpg_player *player, char** map);
    void display_monsters(world_tile *txt, project_info_t *info, my_monsters *monsters);
    void update_monsters(my_monsters *monsters, rpg_player *player, my_time *clock);
    void make_anim_sword(rpg_player *player, my_time *time);
    void upr(rpg_player *player, my_time *clock);
    void upl(rpg_player *player, my_time *clock);
    void downl(rpg_player *player, my_time *clock);
    void downr(rpg_player *player, my_time *clock);
    void attack(rpg_player *player, my_monsters *monsters);
    void define_base_stat(my_monsters *new_node, world_tile *txt);
    void define_boxs(my_monsters *new_node);
    int my_strncmp(char *str1, char *str2, int n);
    void check_event_game(project_info_t *info, menu_info_t *menu, sfVector2f pixelPos);
    menu_info_t *set_position_scale_help_game(project_info_t *info, menu_info_t *menu, sfVector2f pixelPos);
    void check_pnj_event(project_info_t *info, menu_info_t *menu, rpg_player *player, sfEvent *event);

#endif /*FUNCTIONS_PLAY_MAP_H_*///
