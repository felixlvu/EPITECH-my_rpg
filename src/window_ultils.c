/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** window_ultils.c
*/

#include <stdlib.h>
#include "include/42.h"
#include "include/functions_play_map.h"

project_info_t *create_window(project_info_t *info, int x, int y)
{
    sfVideoMode mode = {x, y, 32};

    info = malloc(sizeof(*info));
    if (info == NULL) {
        return (NULL);
    }
    info->x_size = x;
    info->y_size = y;
    info->window = sfRenderWindow_create(mode , "My_rpg", sfResize | sfClose,
    NULL);
    if (info->window == NULL) {
        return (NULL);
    }
    return (info);
}

project_info_t *draw_fond(project_info_t *info)
{
    sfVector2f my_pos = {0, 0};
    sfVector2f my_scale = {0.5, 0.5};

    info->bck_tx = sfTexture_createFromFile("128x128/tile_000.png", NULL);
    info->bck_sprite = sfSprite_create();
    if (info->bck_sprite == NULL || info->bck_tx == NULL) {
        return (info);
    }
    sfSprite_setTexture(info->bck_sprite, info->bck_tx, sfTrue);
    sfSprite_setScale(info->bck_sprite, my_scale);
    sfSprite_setPosition(info->bck_sprite, my_pos);
    return info;
}

int display_window(project_info_t *info, rpg_player *player)
{
    sfRenderWindow_display(info->window);
    sfRenderWindow_clear(info->window, sfColor_fromRGB(0, 128, 255));
    return (0);
}

int get_event(project_info_t *info, sfEvent *event, rpg_player *player)
{
    if (sfRenderWindow_pollEvent(info->window, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(info->window);
        }
    }
    if (player->life <= 0 || player->lvl >= 9) {
        if (player->lvl >= 9) {
            printf("Win ! quest finished\n");
        } else {
            printf("Game Over !\n");
        }
        sfRenderWindow_close(info->window);
    }
    return 0;
}

void update_view(project_info_t *info, rpg_player *player)
{
    sfView_setCenter(player->view, sfSprite_getPosition(player->sprite_p));
    sfRenderWindow_setView(info->window, player->view);
}
