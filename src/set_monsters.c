/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** set_monsters.c
*/

#include <stdlib.h>
#include "include/42.h"
#include "include/functions_play_map.h"

static const sfFloatRect *l_colisions[] = {&(sfFloatRect){0,0,64,64},
                                        &(sfFloatRect){0,0,64,64},
                                        &(sfFloatRect){0,0,64,64}};

void adde_node(my_monsters **head , my_monsters *new_node)
{
    my_monsters *last_node = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        last_node = *head;

        while (last_node->next != NULL) {
            last_node = last_node->next;
        }

        last_node->next = new_node;
    }
}

void lo_colision(world_tile *txt, my_monsters **head, char sprite)
{
    int i = 0;
    my_monsters *new_node = NULL;
    char* col_posibilities = "97";

    while (col_posibilities[i] != sprite && i <= my_strlen(col_posibilities)) {
        i++;
    }
    if (i < my_strlen(col_posibilities)) {
        new_node = malloc(sizeof(my_monsters));
        define_base_stat(new_node, txt);
        define_boxs(new_node);
        if (sprite == '7') {
            new_node->boss = sfTrue;
            new_node->life = 300;
            new_node->col->height = 256;
            new_node->col->width = 256;
        }
        new_node->next = NULL;
        adde_node(head, new_node);
    }
}

my_monsters *set_colision(world_tile *txt, my_monsters *head, char** map)
{
    head = NULL;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            lo_colision(txt, &head, map[i][j]);
            txt->pos.x += 64;
        }
        txt->pos.y += 64;
        txt->pos.x = 0;
    }
    txt->pos.y = 0;
    txt->pos.x = 0;
    return head;
}

void set_monsters(world_tile *txt ,rpg_player *player, char** map)
{
    player->monsters = set_colision(txt, player->monsters, map);
}
