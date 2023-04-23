/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** define_monsters.c
*/

#include <stdlib.h>
#include "include/42.h"
#include "include/functions_play_map.h"
#include <stddef.h>

int my_strncmp(char *str1, char *str2, int n)
{
    if (my_strlen(str1) < n || my_strlen(str2) < n) {
        return (1);
    }
    for (int i = 0; i < n; i++) {
        if (str1[i] != str2[i])
            return (1);
    }
    return (0);
}

void define_base_stat(my_monsters *new_node, world_tile *txt)
{
    new_node->col = malloc(sizeof(sfFloatRect));
    new_node->range = malloc(sizeof (sfFloatRect));
    new_node->life = 100;
    new_node->speed = 100;
    new_node->image.top = 0;
    new_node->image.left = 0;
    new_node->image.height = 32;
    new_node->image.width = 32;
    new_node->col->height = 128;
    new_node->col->width = 128;
    new_node->boss = sfFalse;
    new_node->range->height = 700;
    new_node->range->width = 700;
    new_node->pos.x = txt->pos.x;
    new_node->pos.y = txt->pos.y;
    new_node->col->left = txt->pos.x;
    new_node->col->top = txt->pos.y;
    new_node->range->left = new_node->pos.x - 300;
    new_node->range->top = new_node->pos.y - 300;
    new_node->pos_deb = new_node->pos;

}

void define_boxs(my_monsters *new_node)
{
    new_node->rec_range = sfRectangleShape_create();
    new_node->sprite_p = sfSprite_create();
    new_node->sprite = sfTexture_createFromFile("128x128/mons.png",NULL);
    sfSprite_setTexture(new_node->sprite_p, new_node->sprite, sfTrue);
    sfRectangleShape_setSize(new_node->rec_range, (sfVector2f){700, 700});
    sfRectangleShape_setOutlineThickness(new_node->rec_range, 2);
    sfRectangleShape_setFillColor(new_node->rec_range, sfTransparent);
    sfRectangleShape_setOutlineColor(new_node->rec_range, sfBlue);
}

