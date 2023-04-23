/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** monster_manager.c
*/

#include <stdlib.h>
#include <math.h>
#include "include/42.h"
#include "include/functions_play_map.h"

float my_ab(float x)
{
    if (x < 0) {
        x = x * -1;
        return x;
    }
    return x;
}

void moov_monsters(my_monsters *monsters, my_time *clock)
{
    float dx = 0;
    float dy = 0;
    float angle = 0;

    angle = atan2f(monsters->pos.x - monsters->dest.x, (monsters->pos.y - monsters->dest.y));
    dx = (sinf(angle) * monsters->speed);
    dy = (cosf(angle) * monsters->speed);
    monsters->pos.x -= dx * clock->delta_time;
    monsters->pos.y -= dy * clock->delta_time;
    monsters->col->left = monsters->pos.x;
    monsters->col->top = monsters->pos.y;
}

int in_range(my_monsters *monster, rpg_player *player)
{
    if(sfFloatRect_intersects(monster->range, player->futur_pos, NULL)) {
        return 1;
    }
    return 0;
}

void update_monsters(my_monsters *monsters, rpg_player *player, my_time *clock)
{
    my_monsters *tmp = monsters;

    int i = 0;
    while (tmp != NULL) {
        if (in_range(tmp, player)) {
            tmp->dest.x = player->pos.x;
            tmp->dest.y = player->pos.y;
        } else {
            tmp->dest.x = tmp->pos_deb.x;
            tmp->dest.y = tmp->pos_deb.y;
        }
        if (tmp->life >= 0)
            moov_monsters(tmp, clock);
        tmp = tmp->next;
    }
}

void draw_monster(project_info_t *info, my_monsters *tmp)
{
    sfVector2f taille = {4, 4};
    sfVector2f pos;

    pos.x = tmp->range->left;
    pos.y = tmp->range->top;
    if (tmp->boss == sfTrue) {
        taille.x = 8;
        taille.y = 8;
    }
    sfRectangleShape_setPosition(tmp->rec_range, pos);
    sfSprite_setTextureRect(tmp->sprite_p, tmp->image);
    sfSprite_setPosition(tmp->sprite_p, tmp->pos);
    sfSprite_setScale(tmp->sprite_p, taille);
    sfRenderWindow_drawSprite(info->window, tmp->sprite_p, NULL);
    sfRenderWindow_drawRectangleShape(info->window, tmp->rec_range, NULL);
}

void display_monsters(world_tile *txt, project_info_t *info, my_monsters *monsters)
{
    my_monsters *tmp = monsters;

    while (tmp != NULL) {
        if (tmp->life >= 0) {
            draw_monster(info, tmp);
        }
        tmp = tmp->next;
    }
}