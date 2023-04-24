/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** item
*/


#ifndef ITEM_H_
    #define ITEM_H_

    typedef struct inventory inventory_t;

    typedef struct item {
        struct sword *sword;
        sfBool is_selected;
    } item_t;

    typedef struct sword {
        sfSprite *sprt;
        sfTexture *text;
        sfVector2f pos;
        sfFloatRect bounds;
        sfBool in_inventory;
    } sword_t;

    void item_struct_alloc(item_t *item);
    void setup_item(item_t *item);
    void move_item_sidebar
    (inventory_t *inventory, item_t *item,
    sfRenderWindow *window, sfView *view);
    void change_isselected_value_item(item_t *item,
    sfRenderWindow *window, sfView *view);
    void move_item_container
    (inventory_t *inventory, item_t *item,
    sfRenderWindow *window, sfView *view);

#endif /* !ITEM_H_ */
