/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** player_moov_diag.c
*/

#define VECTEUR 0.70710678
#include "include/42.h"
#include "include/functions_play_map.h"

void moov_upl(rpg_player *player, p_colision *colision, my_time *time)
{
    float val_y = player->pos.y;
    float val_x = player->pos.x;
    float add = 0;

    val_x = val_x - player->speed * VECTEUR * time->delta_time + 30;
    val_y = val_y - player->speed * VECTEUR * time->delta_time + 25;
    player->futur_pos->height = 48;
    player->futur_pos->width = 48;
    player->futur_pos->left = val_x;
    player->futur_pos->top = val_y;
    sfVector2f pos;
    pos.x = val_x;
    pos.y = val_y;
    sfRectangleShape_setSize(player->col, (sfVector2f){48, 48});
    sfRectangleShape_setPosition(player->col, pos);
    if (check_cols(player, colision) == 1) {
        add = (player->speed + (player->lvl * 10)) * VECTEUR;
        player->pos.y -= add * time->delta_time;
        player->pos.x -= add * time->delta_time;
        player->image.top = 160;
        return;
    }
    player->image.top = 160;
    return;
}

void moov_upr(rpg_player *player, p_colision *colision, my_time *time)
{
    float val_y = player->pos.y;
    float val_x = player->pos.x;
    float add = 0;

    val_x = val_x + player->speed * VECTEUR * time->delta_time + 48;
    val_y = val_y - player->speed * VECTEUR * time->delta_time + 30;
    player->futur_pos->height = 48;
    player->futur_pos->width = 48;
    player->futur_pos->left = val_x;
    player->futur_pos->top = val_y;
    sfVector2f pos;
    pos.x = val_x;
    pos.y = val_y;
    sfRectangleShape_setSize(player->col, (sfVector2f){48, 48});
    sfRectangleShape_setPosition(player->col, pos);
    if (check_cols(player, colision) == 1) {
        add = (player->speed + (player->lvl * 10)) * VECTEUR;
        player->pos.y -= add * time->delta_time;
        player->pos.x += add * time->delta_time;
        player->image.top = 192;
        return;
    }
    player->image.top = 192;
    return;
}

void moov_downl(rpg_player *player, p_colision *colision, my_time *time)
{
    float val_y = player->pos.y;
    float val_x = player->pos.x;
    float add = 0;

    val_x = val_x - player->speed * VECTEUR * time->delta_time + 30;
    val_y = val_y - player->speed * VECTEUR * time->delta_time + 70;
    player->futur_pos->height = 32;
    player->futur_pos->width = 32;
    player->futur_pos->left = val_x;
    player->futur_pos->top = val_y;
    sfVector2f pos;
    pos.x = val_x;
    pos.y = val_y;
    sfRectangleShape_setSize(player->col, (sfVector2f){48, 48});
    sfRectangleShape_setPosition(player->col, pos);
    if (check_cols(player, colision) == 1) {
        add = (player->speed + (player->lvl * 10)) * VECTEUR;
        player->pos.y += add * time->delta_time;
        player->pos.x -= add * time->delta_time;
        player->image.top = 128;
        return;
    }
    player->image.top = 128;
    return;
}

void moov_downr(rpg_player *player, p_colision *colision, my_time *time)
{
    float val_y = player->pos.y;
    float val_x = player->pos.x;
    float add = 0;

    val_x = val_x - player->speed * VECTEUR * time->delta_time + 55;
    val_y = val_y - player->speed * VECTEUR * time->delta_time + 70;
    player->futur_pos->height = 32;
    player->futur_pos->width = 32;
    player->futur_pos->left = val_x;
    player->futur_pos->top = val_y;
    sfVector2f pos;
    pos.x = val_x;
    pos.y = val_y;
    sfRectangleShape_setSize(player->col, (sfVector2f){48, 48});
    sfRectangleShape_setPosition(player->col, pos);
    if (check_cols(player, colision) == 1) {
        add = (player->speed + (player->lvl * 10)) * VECTEUR;
        player->pos.y += add * time->delta_time;
        player->pos.x += add * time->delta_time;
        player->image.top = 224;
        return;
    }
    player->image.top = 224;
    return;
}

int diags(rpg_player *player, p_colision *colision, my_time *clock)
{
    if ((sfKeyboard_isKeyPressed(sfKeyD) && sfKeyboard_isKeyPressed(sfKeyQ))
            || (sfKeyboard_isKeyPressed(sfKeyZ)
            && sfKeyboard_isKeyPressed(sfKeyS)))
        return 0;
    if (sfKeyboard_isKeyPressed(sfKeyZ) && sfKeyboard_isKeyPressed(sfKeyQ)) {
        moov_upl(player, colision, clock);
        return 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) && sfKeyboard_isKeyPressed(sfKeyD)) {
        moov_upr(player, colision, clock);
        return 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyQ)) {
        moov_downl(player, colision, clock);
        return 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyD)) {
        moov_downr(player, colision, clock);
        return 0;
    }
    return 1;
}
