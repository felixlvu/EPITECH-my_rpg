/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** attack_moov.c
*/

#include <stdlib.h>
#include "include/42.h"
#include "include/functions_play_map.h"

void upl(rpg_player *player, my_time *clock)
{
    float val_y = player->pos.y;
    float val_x = player->pos.x;

    val_x = val_x - 40;
    val_y = val_y;
    player->ability->attack_box->height = 100;
    player->ability->attack_box->width = 100;
    player->ability->attack_box->left = val_x;
    player->ability->attack_box->top = val_y;
    sfVector2f pos;
    pos.x = val_x;
    pos.y = val_y;
    sfRectangleShape_setSize(player->attack_col, (sfVector2f){100, 100});
    sfRectangleShape_setPosition(player->attack_col, pos);
    attack(player, player->monsters);
    player->image.left = -32;
    player->image.top = 288;
    player->ability->sw_debut = clock->second_1;
    player->ability->sw_anim = sfTrue;
    player->ability->sw_used = sfTrue;
}
void downl(rpg_player *player, my_time *clock)
{
    float val_y = player->pos.y;
    float val_x = player->pos.x;

    val_x = val_x - 25;
    val_y = val_y + 70;
    player->ability->attack_box->height = 100;
    player->ability->attack_box->width = 100;
    player->ability->attack_box->left = val_x;
    player->ability->attack_box->top = val_y;
    sfVector2f pos;
    pos.x = val_x;
    pos.y = val_y;
    sfRectangleShape_setSize(player->attack_col, (sfVector2f){100, 100});
    sfRectangleShape_setPosition(player->attack_col, pos);
    attack(player, player->monsters);
    player->image.left = -32;
    player->image.top = 256;
    player->ability->sw_debut = clock->second_1;
    player->ability->sw_anim = sfTrue;
    player->ability->sw_used = sfTrue;
}
void downr(rpg_player *player, my_time *clock)
{
    float val_y = player->pos.y;
    float val_x = player->pos.x;

    val_x = val_x + 70;
    val_y = val_y + 30;
    player->ability->attack_box->height = 100;
    player->ability->attack_box->width = 100;
    player->ability->attack_box->left = val_x;
    player->ability->attack_box->top = val_y;
    sfVector2f pos;
    pos.x = val_x;
    pos.y = val_y;
    sfRectangleShape_setSize(player->attack_col, (sfVector2f){100, 100});
    sfRectangleShape_setPosition(player->attack_col, pos);
    attack(player, player->monsters);
    player->image.left = -32;
    player->image.top = 352;
    player->ability->sw_debut = clock->second_1;
    player->ability->sw_anim = sfTrue;
    player->ability->sw_used = sfTrue;
}

void upr(rpg_player *player, my_time *clock)
{
    float val_y = player->pos.y;
    float val_x = player->pos.x;

    val_x = val_x + 48;
    val_y = val_y - 30;
    player->ability->attack_box->height = 100;
    player->ability->attack_box->width = 100;
    player->ability->attack_box->left = val_x;
    player->ability->attack_box->top = val_y;
    sfVector2f pos;
    pos.x = val_x;
    pos.y = val_y;
    sfRectangleShape_setSize(player->attack_col, (sfVector2f){100, 100});
    sfRectangleShape_setPosition(player->attack_col, pos);
    attack(player, player->monsters);
    player->image.left = -32;
    player->image.top = 320;
    player->ability->sw_debut = clock->second_1;
    player->ability->sw_anim = sfTrue;
    player->ability->sw_used = sfTrue;
}