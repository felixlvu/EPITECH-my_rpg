/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** clocks.c
*/

#include <stdlib.h>
#include "include/42.h"
#include "include/functions_play_map.h"

int my_clock(my_time *time, rpg_player *player)
{
    sfTime clock;

    clock = sfClock_getElapsedTime(time->clock) ;
    time->seconds = clock.microseconds / 1000000.0;
    static float old_time = 0.0;
    time->delta_time = time->seconds - old_time;
    time->second_1 += time->delta_time;
    time->anim += time->delta_time;
    old_time = time->seconds;
    return 0;
}

void make_anim_mons(my_monsters *monsters, my_time *time)
{
    my_monsters *tmp = monsters;
    while (tmp != NULL) {
        tmp->image.left += 32;
        if (tmp->image.left >= 64) {
            tmp->image.left = 0;
        }
        tmp = tmp->next;
    }
}

void make_anim(rpg_player *player, my_time *time)
{
    if (time->anim >= 0.1) {
        make_anim_mons(player->monsters, time);
        player->image.left += 32;
        if (player->image.left >= 128) {
            player->image.left = 0;
        }
        time->anim = 0.0;
    }
}

void make_anim_sword(rpg_player *player, my_time *time)
{
    if (time->anim >= 0.05) {
        player->image.left += 32;
        if (player->image.left >= 160) {
            player->image.left = 0;
        }
        time->anim = 0.0;
    }
}

my_time *create_clock(my_time *clock)
{
    clock = malloc(sizeof(my_time));
    clock->clock = sfClock_create();
    clock->anim = 0.0;
    clock->delta_time = 0;
    clock->second_1 = 0;
    return clock;
}