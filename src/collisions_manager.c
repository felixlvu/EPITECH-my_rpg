/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** collisions_manager.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/42.h"
#include "include/functions_play_map.h"

static const sfFloatRect *l_colisions[] = {&(sfFloatRect){0,0,64,64},
                                           &(sfFloatRect){0,0,64,64},
                                           &(sfFloatRect){0,0,64,64},
                                           &(sfFloatRect){0,0,48,50},
                                           &(sfFloatRect){0,0,192,192},
                                           &(sfFloatRect){0,0,128,249},
                                           &(sfFloatRect){0,0,64,256},
                                           &(sfFloatRect){0,0,160,124},
                                           &(sfFloatRect){0,0,16,16},
                                           &(sfFloatRect){0,0,64,64},
                                           &(sfFloatRect){0,0,90,80},
                                           &(sfFloatRect){0,0,48,64},
                                           &(sfFloatRect){0,0,64,63},
                                           &(sfFloatRect){0,0,16,66},
                                           &(sfFloatRect){0,0,16,66},
                                           &(sfFloatRect){0,0,62,70}};

void add_node(p_colision **head , p_colision *new_node)
{
    p_colision *last_node = NULL;

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

void la_colision(world_tile *txt, p_colision **head, char sprite)
{
    int i = 0;
    p_colision *new_node = NULL;
    char* col_posibilities = "GABCHWw=POj+*12~";

    while (col_posibilities[i] != sprite && i <= my_strlen(col_posibilities)) {
        i++;
    }
    if (i < my_strlen(col_posibilities)) {
        new_node = malloc(sizeof(p_colision));
        new_node->p_col = malloc(sizeof(sfFloatRect));
        new_node->p_col->left = txt->pos.x;
        new_node->p_col->top = txt->pos.y;
        new_node->p_col->width = l_colisions[i]->width;
        new_node->p_col->height = l_colisions[i]->height;
        new_node->next = NULL;
        add_node(head, new_node);
    }
}

p_colision *set_colisions(world_tile *txt, p_colision *head, char** map)
{
    head = NULL;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            la_colision(txt, &head, map[i][j]);
            txt->pos.x += 64;
        }
        txt->pos.y += 64;
        txt->pos.x = 0;
    }
    txt->pos.y = 0;
    txt->pos.x = 0;
    return head;
}

int check_cols(rpg_player *player, p_colision *colision)
{
    p_colision *tmp = colision;
    while (tmp != NULL) {
        if (sfFloatRect_intersects(tmp->p_col, player->futur_pos, NULL)) {
            return 0;
        }
        tmp = tmp->next;
    }
    return 1;
}
