/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** attack_manager.c
*/

#include <stdlib.h>
#include "include/42.h"
#include "include/functions_play_map.h"

void on_attack(rpg_player *player, my_monsters *tmp)
{
    tmp->life -= player->atk_pow + player->lvl;
    if (tmp->life <= 0) {
        tmp->col->top = -10000;
        player->lvl++;
    }
    if (tmp->life <= 0 && tmp->boss == sfTrue) {
        player->lvl++;
    }
}

void attack(rpg_player *player, my_monsters *monsters)
{
    my_monsters *tmp = monsters;

    while (tmp != NULL) {
        if (sfFloatRect_intersects(player->ability->attack_box, tmp->col, NULL)) {
            on_attack(player, tmp);
        }
        tmp = tmp->next;
    }
}