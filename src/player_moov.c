/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** player_moov.c
*/

#include "include/42.h"
#include "include/functions_play_map.h"

void moov_right(rpg_player *player, p_colision *colision, my_time *time)
{
    float val_x = player->pos.x;
    float val_y = player->pos.y;
    int added = 0;

    player->futur_pos->height = 56;
    player->futur_pos->width = 1;
    player->futur_pos->left = (val_x + 99 +(player->speed * time->delta_time));
    player->futur_pos->top = (val_y + 40);
    sfVector2f pos;
    pos.x = val_x + (player->speed * time->delta_time);
    pos.x += 100;
    pos.y = val_y + 40;
    sfRectangleShape_setSize(player->col, (sfVector2f){1, 56});
    sfRectangleShape_setPosition(player->col, pos);
    if (check_cols(player, colision) == 1) {
        added = (player->lvl * 10);
        player->pos.x += (player->speed + added) * time->delta_time;
        player->image.top = 0;
        return;
    }
    player->image.top = 0;
    return;
}

void moov_left(rpg_player *player, p_colision *colision, my_time *time)
{
    float val_x = player->pos.x;
    float val_y = player->pos.y;
    int added = 0;

    player->futur_pos->height = 56;
    player->futur_pos->width = 1;
    player->futur_pos->left = ((val_x) - (player->speed * time->delta_time) + 28);
    player->futur_pos->top = val_y + 40;
    sfVector2f pos;
    pos.x = val_x - (player->speed * time->delta_time) + 28;
    pos.y = val_y + 40;
    sfRectangleShape_setSize(player->col, (sfVector2f){1, 56});
    sfRectangleShape_setPosition(player->col, pos);
    if (check_cols(player, colision) == 1) {
        added = (player->lvl * 10);
        player->pos.x -= (player->speed + added) * time->delta_time;
        player->image.top = 96;
        return;
    }
    player->image.top = 96;
    return;
}

void moov_top(rpg_player *player, p_colision *colision, my_time *time)
{
    float val_y = player->pos.y;
    float val_x = player->pos.x;
    int added = 0;

    player->futur_pos->height = 1;
    player->futur_pos->width = 56;
    player->futur_pos->left = val_x + 36;
    player->futur_pos->top = (val_y) + 24;
    sfVector2f pos;
    pos.x = val_x + 36;
    pos.y = val_y + 24;
    sfRectangleShape_setSize(player->col, (sfVector2f){56, 1});
    sfRectangleShape_setPosition(player->col, pos);
    if (check_cols(player, colision) == 1) {
        added = (player->lvl * 10);
        player->pos.y -= (player->speed + added) * time->delta_time;
        player->image.top = 32;
        return;
    }
    player->image.top = 32;
    return;
}

void moov_bot(rpg_player *player, p_colision *colision, my_time *time)
{
    float val_y = player->pos.y;
    float val_x = player->pos.x;
    int added = 0;

    player->futur_pos->height = 1;
    player->futur_pos->width = 48;
    player->futur_pos->left = val_x + 40;
    player->futur_pos->top = val_y + 115;
    sfVector2f pos;
    pos.x = val_x + 40;
    pos.y = val_y + 115;
    sfRectangleShape_setSize(player->col, (sfVector2f){48, 1});
    sfRectangleShape_setPosition(player->col, pos);
    if (check_cols(player, colision) == 1) {
        added = (player->lvl * 10);
        player->pos.y += (player->speed + added) * time->delta_time;
        player->image.top = 64;
        return;
    }
    player->image.top = 64;
    return;
}

void perso_moovs(rpg_player *player, my_time *clock, p_colision *colisions)
{
    if (diags(player, colisions, clock) == 0) {
        make_anim(player, clock);
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        make_anim(player, clock);
        moov_right(player, colisions, clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        make_anim(player, clock);
        moov_left(player, colisions, clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        make_anim(player, clock);
        moov_top(player, colisions, clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        make_anim(player, clock);
        moov_bot(player, colisions, clock);
    }
}
