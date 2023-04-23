/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** player_all_moov.c
*/

#include <stdlib.h>
#include "include/42.h"
#include "include/functions_play_map.h"

void check_ability_sw(rpg_player *player, my_time *time)
{

    if (player->ability->sw_used == sfTrue) {
        if (time->second_1 - player->ability->sw_debut >= 0.25) {
            player->ability->sw_anim = sfFalse;
            player->ability->sword = sfFalse;
            player->ability->sw_used = sfFalse;
        }
    }
    if (player->ability->sw_anim == sfTrue) {
        if (time->second_1 - player->ability->sw_debut >= 1) {
            player->ability->sw_anim = sfFalse;
            player->ability->sword = sfTrue;
            return;
        }
    }
    return;
}

void selc_attack(rpg_player *player, my_time *clock)
{
    if ((player->image.top == 32 || player->image.top == 192)
            && (player->ability->sw_used == sfFalse)) {
        upr(player, clock);
    }
    if ((player->image.top == 96 || player->image.top == 160)
            && player->ability->sw_used == sfFalse) {
        upl(player, clock);
    }
    if ((player->image.top == 0 || player->image.top == 224)
            && (player->ability->sw_used == sfFalse)) {
        downr(player, clock);
    }
    if ((player->image.top == 64 || player->image.top == 128)
            && (player->ability->sw_used == sfFalse)) {
        downl(player, clock);
    }
}

void check_hitted(rpg_player *player, my_monsters *monsters)
{
    my_monsters *tmp = monsters;

    while (tmp != NULL) {
        if (sfFloatRect_intersects(player->futur_pos, tmp->col, NULL))
            player->life -= 1;
        tmp = tmp->next;
    }
}

int update_perso(rpg_player *player, my_time *clock, p_colision *colisions)
{
    check_ability(player, clock);
    check_ability_sw(player, clock);
    if (sfKeyboard_isKeyPressed(sfKeyA))
        ability(player, clock);
    if (sfKeyboard_isKeyPressed(sfKeyW)) {
        selc_attack(player, clock);
    }
    if (player->ability->sw_anim == sfTrue) {
        make_anim_sword(player, clock);
    }
    check_hitted(player, player->monsters);
    perso_moovs(player, clock, colisions);
}