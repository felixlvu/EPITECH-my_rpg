##
## EPITECH PROJECT, 2023
## my_rpg
## File description:
## Makefile
##

NAME = my_rpg

SRC = src/main.c \
	  src/get_file.c \
	  src/map_creator.c \
	  src/collisions_manager.c \
	  src/ability.c \
	  src/player_moov.c \
	  src/set_player.c \
	  src/window_ultils.c \
	  src/clocks.c \
	  src/set_elements.c \
	  src/player_moov_diag.c \
	  src/player_all_moov.c \
	  src/menu/set_position_menu.c \
	  src/menu/check_button_music.c \
	  src/menu/check_button_main_menu.c \
	  src/menu/check_button_music_resolution.c \
	  src/menu/check_event.c \
	  src/menu/display_menu.c \
	  src/menu/create_music.c \
	  src/menu/create_button.c \
	  src/menu/create_main_menu.c \
	  src/menu/set_position_button.c \
	  src/inventory/inventory.c \
	  src/inventory/init_struct.c \
	  src/inventory/select_slot_sidebar.c \
	  src/inventory/init_struct_item.c \
	  src/inventory/move_item_sidebar.c \
	  src/inventory/move_item_container.c \
	  src/monster_manager.c \
	  src/set_monsters.c \
	  src/attack_moov.c \
	  src/attack_manager.c \
	  src/define_monsters.c \
	  src/set_scale_position_help_game.c \
	  src/check_event_help_game.c \

CFLAGS = -I include -g3

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

OBJ = $(SRC:.c=.o)

RESET = '\033[0m'
BOLD = '\033[1m'
RED = '\033[31m'
GREEN = '\033[32m'
YELLOW = '\033[33m'

$(NAME): $(OBJ)
	@echo "$(BOLD)$(GREEN)[Compilation]$(RESET) - $(GREEN)Finish$(RESET)"
	@echo "$(BOLD)$(GREEN)[Building]$(RESET) - $(YELLOW)$(NAME)$(RESET)"
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS)
	@sleep 0.5
	@tput cuu1 && tput dl1
	@echo "$(BOLD)$(GREEN)[Building]$(RESET) - $(GREEN)Finish$(RESET)"

all: $(NAME)

clean:
	@echo "$(BOLD)$(RED)[Cleaning]$(RESET) - Removing object files"
	@for file in $(OBJ); do \
		echo "$(YELLOW)$$file$(RESET)"; \
		sleep 0.1; \
		tput cuu1 && tput dl1; \
	done
	@rm -f $(OBJ)
	@tput cuu1 && tput dl1
	@echo "$(BOLD)$(RED)[Cleaning]$(RESET) - $(GREEN)Finish$(RESET)"

fclean: clean
	@echo "$(BOLD)$(RED)[Cleaning]$(RESET) - Removing $(NAME) executable"
	@echo "$(YELLOW)$(NAME)$(RESET)"
	@sleep 0.1
	@tput cuu1 && tput dl1
	@tput cuu1 && tput dl1
	@echo "$(BOLD)$(RED)[Force Cleaning]$(RESET) - $(GREEN)Finish$(RESET)"
	@rm -f $(NAME)

re: fclean all

$(OBJ): %.o: %.c
	@echo "$(BOLD)$(GREEN)[Compiling]$(RESET) - $(YELLOW)$<$(RESET)"
	@gcc $(CFLAGS) -c -o $@ $<
	@sleep 0.1
	@tput cuu1 && tput dl1

.PHONY: all clean fclean re