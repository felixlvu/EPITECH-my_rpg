/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** set_elements.c
*/

#include <stdlib.h>
#include "include/42.h"
#include "include/functions_play_map.h"

static const sfIntRect *elements[] = {&(sfIntRect){0,0,48,96},
                                &(sfIntRect){48,0,48,96},
                                &(sfIntRect){160, 0, 48, 96},
                                &(sfIntRect){207, 0, 50, 48},
                                &(sfIntRect){272,288,32,64},
                                &(sfIntRect){304,192,16,96},
                                &(sfIntRect){320, 176, 16, 64},
                                &(sfIntRect){128, 224,40, 31},
                                &(sfIntRect){176,224,16,64},
                                &(sfIntRect){0,591,128,64},
                                &(sfIntRect){64,784,16,16},
                                &(sfIntRect){208,256,32,16},
                                &(sfIntRect){128,592,112,160},
                                &(sfIntRect){272,1104,64,64},
                                &(sfIntRect){400,122,64,62},
                                &(sfIntRect){401,0,48,76},
                                &(sfIntRect){401,298,48,93},
                                &(sfIntRect){433,391,16,66},
                                &(sfIntRect){484,0,16,66},
                                &(sfIntRect){403,529,64,32},
                                &(sfIntRect){465,467,32,32},
                                &(sfIntRect){403,529,32,32},
                                &(sfIntRect){256,273,16,80},
                                &(sfIntRect){0,400,62,192},
                                &(sfIntRect){176,224,16,64},
                                &(sfIntRect){64, 96, 16, 16},
                                &(sfIntRect){160, 96,16, 16},
                                &(sfIntRect){64, 256, 16, 16},
                                &(sfIntRect){176,224,16,64}};

sfVector2f element_pos_conv(char el, world_tile *txt)
{
    sfVector2f result = txt->pos;

    if (el == 'A' || el == 'C' || el == 'B') {
        result.x -= 64;
        result.y -= 320;
    }
    if (el == '~') {
        result.y -= 700;
        result.x -= 15;
    }
    if (el == 'P') {
        result.y -= 190;
    }
    if (el == 'j') {
        result.x -= 48;
        result.y -= 555;
    }
    if (el == '*')
        result.y -= 165;
    return result;
}

int display_elms(char elm, project_info_t* info, world_tile *txt)
{
    char* l_elem = "ABCHWwk=+POtjc*@812345&~";
    sfVector2f scale = {4, 4};
    sfVector2f pos;
    int i = 0;

    while (l_elem[i] != elm && i <= my_strlen(l_elem)) {
        i++;
    }
    if (i <= my_strlen(l_elem)) {
        pos = element_pos_conv(l_elem[i], txt);
        sfSprite_setTextureRect(txt->sprite, *elements[i]);
        sfSprite_setScale(txt->sprite, scale);
        sfSprite_setPosition(txt->sprite, pos);
        sfRenderWindow_drawSprite(info->window, txt->sprite, NULL);
    }
    return 0;
}

int display_Obj(world_tile *txt, project_info_t *info, char **map)
{
    for (int x = 0; map[x] != NULL; x++) {
        for (int y = 0; map[x][y] != '\0'; y++) {
            display_elms(map[x][y], info, txt);
            txt->pos.x += 64;
        }
        txt->pos.y += 64;
        txt->pos.x = 0;
    }
    txt->pos.y = 0;
    txt->pos.x = 0;
    return 0;
}
