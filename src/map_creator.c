/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** map_creator.c
*/

#include <stdlib.h>
#include "include/42.h"
#include "include/functions_play_map.h"

static const sfIntRect *tiles[] = {&(sfIntRect){0,112,16,16},
                                &(sfIntRect){0,128,16,16},
                                &(sfIntRect){64, 112, 16, 16},
                                &(sfIntRect){48, 128,16, 16},
                                &(sfIntRect){0, 144, 16, 16},
                                &(sfIntRect){16,144,16,16},
                                &(sfIntRect){48,144,16,16},
                                &(sfIntRect){0, 160, 16, 16},
                                &(sfIntRect){80, 144,16, 16},
                                &(sfIntRect){48, 160, 16, 16},
                                &(sfIntRect){80,128,16,16},
                                &(sfIntRect){64,128,16,16},
                                &(sfIntRect){16, 224, 16, 16},
                                &(sfIntRect){401,185,16,16},
                                &(sfIntRect){0,112,16,16},
                                &(sfIntRect){0,112,16,16},
                                &(sfIntRect){0,112,16,16},
                                &(sfIntRect){0,112,16,16},
                                &(sfIntRect){80,240,16,16},
                                &(sfIntRect){304,176,16,16},
                                &(sfIntRect){256,177,16,109},
                                &(sfIntRect){16,96,16,16},
                                &(sfIntRect){32,224,16,16},
                                &(sfIntRect){16,224,16,16},
                                &(sfIntRect){16,224,16,16},
                                &(sfIntRect){0,1128,86,52},
                                &(sfIntRect){225,1128,47,52},
                                &(sfIntRect){48,1040,16,16},
                                &(sfIntRect){64,96,16,16},
                                &(sfIntRect){80,96,16,16},
                                &(sfIntRect){90,70,16,16},
                                &(sfIntRect){401,185,16,16},
                                &(sfIntRect){64,1040,16,16},
                                &(sfIntRect){0,112,16,16},
                                &(sfIntRect){401,185,16,16},
                                &(sfIntRect){401,185,16,16}};

int display_tile(char elm, project_info_t* info, world_tile *txt)
{
    char* elements = " <->|y/#_]ut?GABCHb&w^$=+mMrgdz6e974";
    int i = 0;

    sfVector2f scale = {4, 4};
    while (elements[i] != elm && i <= my_strlen(elements)) {
        i++;
    }
    if (i <= my_strlen(elements)) {
        sfSprite_setTextureRect(txt->sprite, *tiles[i]);
        sfSprite_setScale(txt->sprite, scale);
        sfSprite_setPosition(txt->sprite, txt->pos);
        sfRenderWindow_drawSprite(info->window, txt->sprite, NULL);
    }
    return 0;
}

world_tile *create_world(world_tile *tiles)
{
    tiles->wrld_txt = sfTexture_createFromFile("128x128/assets_out.png", NULL);
    tiles->pos.x = 0;
    tiles->pos.y = 0;
    return (tiles);
}

int display_world(world_tile *txt, project_info_t *info, char **map)
{
    for (int x = 0; map[x] != NULL; x++) {
        for (int y = 0; map[x][y] != '\0'; y++) {
            display_tile(map[x][y], info, txt);
            txt->pos.x += 64;
        }
        txt->pos.y += 64;
        txt->pos.x = 0;
    }
    txt->pos.y = 0;
    txt->pos.x = 0;
    return 0;
}

void les_sprite(world_tile *txt)
{
    txt->sprite = sfSprite_create();
    sfSprite_setTexture(txt->sprite, txt->wrld_txt, sfTrue);
}
