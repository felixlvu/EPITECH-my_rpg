/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory
*/


#ifndef INVENTORY_H_
    #define INVENTORY_H_

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include "item.h"

    typedef struct inventory {
        struct inventory_sidebar *sidebar;
        struct inventory_menu *menu;
        struct inventory_selected *selected;
        struct case_sb_chained *case_sb;
        struct case_container *case_container;
        sfBool is_open;
        sfBool e_key_down;
        sfBool isDownKeyPressed ;
        sfBool isUpKeyPressed ;
    } inventory_t;

    typedef struct case_container {
        sfFloatRect bounds;
        sfRectangleShape *rect;
        struct case_container *next;
        struct case_container *prev;
        struct case_container *head;
    } case_container_t;

    typedef struct case_sb_chained {
        sfFloatRect bounds;
        sfRectangleShape *rect;
        struct case_sb_chained *next;
        struct case_sb_chained *prev;
        struct case_sb_chained *head;
    } case_sb_chained_t;

    typedef struct inventory_sidebar {
        sfSprite *sprt;
        sfTexture *text;
    } inventory_sidebar_t;

    typedef struct inventory_menu {
        sfSprite *sprt;
        sfTexture *text;
    } inventory_menu_t;

    typedef struct inventory_selected {
        sfSprite *sprt;
        sfTexture *text;
        sfVector2f pos;
    } inventory_selected_t;

    void inventory_struct_alloc(inventory_t *inventory);
    void inventory_f(sfRenderWindow *window,
    inventory_t *inventory, item_t *item, sfView *view);
    void setup_inventory(inventory_t *inventory);
    void select_slot_sidebar(inventory_t *inventory);
    void setup_chained_list_case_sidebar(inventory_t *inventory);
    void setup_chained_list_case_container(inventory_t *inventory);
    void move_with_view(inventory_t *inventory, item_t *item, sfView *view);

#endif /* !INVENTORY_H_ */
