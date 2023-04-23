/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** 42.h
*/

#include <SFML/Graphics.h>
#include <SFML/System/Types.h>
#include <stdbool.h>

#ifndef struct_H_
	#define struct_H_
    typedef struct button_s button_t;
    typedef struct menu_s menu_t;

    struct menu_s {
        sfRectangleShape *rect;
        sfSprite *sprite;
        sfTexture *texture;
        int display;
        bool (*hover)(sfVector2i, sfFloatRect, button_t *);
        menu_t *next;
    };

    typedef struct project_info {
        sfRenderWindow *window;
        sfFont *my_font;
        sfVector2i old_pos;
        sfVector2i new_pos;
        sfSprite *bck_sprite;
        sfTexture *bck_tx;
        int x_size;
        int y_size;
        int state_menu;
        char **map;
    } project_info_t;

    typedef struct world_tile {
        sfTexture *wrld_txt;
        sfVector2f pos;
        sfSprite* sprite;
    }world_tile;

    struct my_ability {
        sfBool speed;
        sfBool used;
        float debut;
        sfBool sword;
        sfBool sw_used;
        sfBool sw_anim;
        float sw_debut;
        sfFloatRect *attack_box;
    };
    typedef struct my_ability my_ability;

    struct monsters {
        int life;
        int speed;
        sfBool boss;
        sfTexture *sprite;
        sfVector2f pos_deb;
        sfVector2f dest;
        sfSprite * sprite_p;
        sfVector2f pos;
        sfIntRect image;
        sfFloatRect* col;
        sfFloatRect* range;
        sfRectangleShape *rec_range;
        struct monsters *next;
    };
    typedef struct monsters my_monsters;

    typedef struct player {
        int life;
        sfView *view;
        sfTexture *sprites;
        sfVector2f pos;
        sfFloatRect* futur_pos;
        sfSprite *sprite_p;
        sfTexture *pnj_texture;
        sfSprite *pnj;
        sfTexture *message_texture;
        sfSprite *message;
        sfIntRect image;
        float speed;
        sfRectangleShape *col;
        sfRectangleShape *attack_col;
        my_ability *ability;
        my_monsters *monsters;
        int lvl;
        int atk_pow;
        int message_pnj;
    } rpg_player;

    typedef struct my_time {
        sfClock *clock;
        sfTime time;
        float second_1;
        float seconds;
        float delta;
        float delta_time;
        float anim;
    } my_time;

    typedef struct my_collision {
        sfFloatRect* p_col;
        struct my_collision *next;
    }p_colision;
    char** get_map(char* link);
#endif /*eeee_H_*/