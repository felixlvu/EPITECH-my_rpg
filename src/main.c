/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** menu.c
*/

#include <stdlib.h>
#include "include/42.h"
#include "include/functions_play_map.h"
#include "include/window_func.h"
#include "include/main_menu_struct.h"
#include "include/main_menu.h"
#include "include/inventory.h"


void display_pnj(project_info_t *info, rpg_player *player)
{

    sfIntRect sprite_pos = sfSprite_getTextureRect(player->pnj);
    sfIntRect message_pos = sfSprite_getTextureRect(player->message);
    sfRenderWindow_drawSprite(info->window, player->pnj, NULL);
    if (sprite_pos.left >= 240) {
        sprite_pos.left = 0;
        sfSprite_setTextureRect(player->pnj, sprite_pos);
    } else {
        sprite_pos.left = sprite_pos.left + 48; 
        sfSprite_setTextureRect(player->pnj, sprite_pos);
    }
    if (player->message_pnj == 0) {
        sfSprite_setTextureRect(player->message, (sfIntRect){0, 0, 800, 200});
        sfRenderWindow_drawSprite(info->window, player->message, NULL);
    }
    if (player->message_pnj == 1) {
        sfSprite_setTextureRect(player->message, (sfIntRect){0, 200, 800, 200});
        sfRenderWindow_drawSprite(info->window, player->message, NULL);
    }
    if (player->message_pnj == 2) {
        sfSprite_setTextureRect(player->message, (sfIntRect){0, 400, 800, 200});
        sfRenderWindow_drawSprite(info->window, player->message, NULL);
    }
    if (player->message_pnj == 3) {
        sfSprite_setTextureRect(player->message, (sfIntRect){0, 600, 800, 200});
        sfRenderWindow_drawSprite(info->window, player->message, NULL);
    }
}

void check_pnj_event(project_info_t *info, menu_info_t *menu, rpg_player *player, sfEvent *event)
{
    sfVector2i pixel_pos = sfMouse_getPositionRenderWindow(info->window);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(info->window, pixel_pos, NULL);
    sfFloatRect rect = sfSprite_getGlobalBounds(player->pnj);
    static bool is_pressed = false;

    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue) {  
        if (event->type == sfEvtMouseButtonReleased && event->mouseButton.button == sfMouseLeft && is_pressed == false) {
            is_pressed = true;
            player->message_pnj += 1;
            if (player->message_pnj == 4) {
                player->message_pnj = 0;
            }
        } else if (event->type != sfEvtMouseButtonReleased) {
            is_pressed = false;
        }
    }
}

void displays(world_tile *txt, project_info_t *info, rpg_player *player, char** map, menu_info_t *menu, sfVector2f pixel_pos, sfEvent *event, inventory_t *inventory, item_t *item, sfRenderWindow *window)
{
    display_world(txt, info, map);
    display_perso(info, player);
    display_monsters(txt, info, player->monsters);
    check_pnj_event(info, menu, player, event);
    display_Obj(txt, info, map);
    if (menu->index_menu == 1) {
        display_settings(info, menu, 1);
        check_event_game(info, menu, pixel_pos);
    }
    if (menu->index_menu != 1)  
        display_pnj(info, player);
        draw_sprite_inventory(inventory, item, window);
    display_window(info);
}

void create_pnj(rpg_player *player)
{
    player->pnj_texture = sfTexture_createFromFile("128x128/pnj.png", NULL);
    player->pnj = sfSprite_create();
    sfSprite_setTexture(player->pnj, player->pnj_texture, sfTrue);
    player->message_texture = sfTexture_createFromFile("128x128/messages.png", NULL);
    player->message = sfSprite_create();
    sfSprite_setTexture(player->message, player->message_texture, sfTrue);
    sfSprite_setScale(player->pnj, (sfVector2f){4, 4});
    sfSprite_setTextureRect(player->pnj, (sfIntRect){0, 0, 48, 48});
    sfSprite_setTextureRect(player->message, (sfIntRect){0, 0, 800, 200});
    sfSprite_setPosition(player->pnj, (sfVector2f){3980, 1450});
    sfSprite_setPosition(player->message, (sfVector2f){3880, 1350});
}

int run_rpg(project_info_t *info, world_tile *txt, rpg_player *player, menu_info_t *menu)
{
    sfEvent event;
    my_time *clock = NULL;
    p_colision *colisions = NULL;
    info->state_menu = 0;
    menu->index_menu = 0;
    player->message_pnj = 0;
    sfVector2i positon = {0, 0};
    inventory_t *inventory = malloc(sizeof(inventory_t));
    item_t *item = malloc(sizeof(item_t));

    char** map = get_map("map_test.txt");
    les_sprite(txt);
    inventory_struct_alloc(inventory);
    setup_inventory(inventory);
    item_struct_alloc(item);
    setup_item(item);
    setup_chained_list_case_sidebar(inventory);
    setup_chained_list_case_container(inventory);
    colisions = set_colisions(txt, colisions, map);
    clock = create_clock(clock);
    while (sfRenderWindow_isOpen(info->window)) {
        if (info->state_menu == 0) {
            my_clock(clock, player);
            display_menu(info, menu);
            check_button(info, menu);
            get_event(info, &event, player);
        } else {
            my_clock(clock, player);
            update_view(info, player);
            sfVector2f pixelPos = sfRenderWindow_mapPixelToCoords(info->window, positon, player->view);
            sfVector2u window_size = sfRenderWindow_getSize(info->window);
            sfVector2f scale = (sfVector2f){1, 1};
            displays(txt, info, player, map, menu, pixelPos, &event, inventory, item, info->window);
            if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
                sfSprite_setPosition(menu->info_game_sprite, pixelPos);
                sfSprite_setScale(menu->info_sprite, scale);
                set_position_scale_help_game(info, menu, pixelPos);
                menu->index_menu = 1;
            } else {
                menu->index_menu = 0;
            }
            inventory_f(info->window, inventory, item, player->view);
            update_perso(player, clock, colisions);
            update_monsters(player->monsters, player, clock);
            get_event(info, &event, player);
        }
    }
    return (0);
}

int rpg(void)
{
    project_info_t *info = NULL;
    world_tile *tiles = NULL;
    rpg_player *player = NULL;
    menu_info_t *menu = NULL;

    char** map = get_map("map_test.txt");
    tiles = malloc(sizeof(world_tile));
    tiles = create_world(tiles);
    player = malloc(sizeof(rpg_player));
    player = create_player(tiles, player, map);
    info = create_window(info, 1920, 1080);
    menu = create_menu(info, menu);
    create_pnj(player);
    if (info == NULL) {
        return (84);
    }
    info = draw_fond(info);
    run_rpg(info, tiles, player, menu);
    return (0);
}

int test_environment(char *env[])
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "DISPLAY=", 8) == 0)
            return (0);
    }
    return (1);
}

int main(int, char **, char *env[])
{
    if (test_environment(env) == 1) {
        return (84);
    }
    if (rpg() == 84) {
        return (84);
    }
    return (0);
}
