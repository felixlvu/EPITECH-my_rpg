/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** ability.c
*/

#include "include/42.h"
#include "include/functions_play_map.h"

int ability(rpg_player *player, my_time *time)
{
    if (player->ability->speed == sfFalse && player->ability->used == sfFalse) {
        return 0;
    }
    if (player->ability->speed == sfTrue && player->ability->used == sfFalse) {
        player->speed = 2000;
        player->ability->debut = time->second_1;
        player->ability->used = sfTrue;
    }
    return  0;
}

void check_ability(rpg_player *player, my_time *time)
{

    if (player->ability->used == sfTrue) {
        if (time->second_1 - player->ability->debut >= 0.2) {
            player->speed = 300;
            player->ability->speed = sfFalse;
            player->ability->used = sfFalse;
        }
    }
    if (player->ability->speed == sfFalse) {
        if (time->second_1 - player->ability->debut >= 5) {
            player->ability->speed = sfTrue;
            return;
        }
    }
    return;
}

int display_perso(project_info_t *info, rpg_player *player)
{
    sfVector2f taille = {4, 4};

    sfSprite_setTextureRect(player->sprite_p, player->image);
    sfSprite_setScale(player->sprite_p, taille);
    sfSprite_setPosition(player->sprite_p, player->pos);
    sfRenderWindow_drawRectangleShape(info->window, player->col, NULL);
    sfRenderWindow_drawRectangleShape(info->window, player->attack_col, NULL);
    sfRenderWindow_drawSprite(info->window, player->sprite_p, NULL);
    return 0;
}
