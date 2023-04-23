/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** set_player.c
*/

#include <stdlib.h>
#include "include/42.h"
#include "include/functions_play_map.h"

void set_player_image(rpg_player *player)
{
    player->view = sfView_create();
    sfView_setSize(player->view, (sfVector2f){1920, 1080});
    player->image.top = 0;
    player->image.left = 0;
    player->image.height = 32;
    player->image.width = 32;
}

void set_player_ability(rpg_player *player)
{
    player->life = 1000;
    player->ability = malloc(sizeof (my_ability));
    player->ability->attack_box = malloc(sizeof(sfFloatRect));
    player->ability->speed = sfTrue;
    player->ability->used = sfFalse;
    player->ability->sword = sfTrue;
    player->ability->sw_used = sfFalse;
    player->ability->sw_anim = sfFalse;
    player->ability->sw_debut = 0;
    player->ability->debut = 0;
    player->atk_pow = 25;
    player->lvl = 1;
}

void set_player_sprite(rpg_player *player)
{
    player->col = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(player->col, 2);
    sfRectangleShape_setFillColor(player->col, sfTransparent);
    sfRectangleShape_setOutlineColor(player->col, sfGreen);
    player->attack_col = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(player->attack_col, 2);
    sfRectangleShape_setFillColor(player->attack_col, sfTransparent);
    sfRectangleShape_setOutlineColor(player->attack_col, sfRed);
    player->sprites = sfTexture_createFromFile
    ("128x128/personage_v2.png", NULL);
    player->sprite_p = sfSprite_create();
    sfSprite_setTexture(player->sprite_p, player->sprites, sfTrue);
}

void set_player_poss(rpg_player *player)
{
    player->futur_pos = malloc(sizeof(sfFloatRect));
    player->pos.x = 2000;
    player->pos.y = 1000;
    player->speed = 300;
}

rpg_player *create_player(world_tile *txt, rpg_player *player, char** map)
{
    set_player_image(player);
    set_player_sprite(player);
    set_player_ability(player);
    set_player_poss(player);
    set_monsters(txt, player, map);
    return player;
}
