CC = gcc
CFLAGS = -Wall -Wextra -Werror -lncurses
SRC = main.c player.c bullet.c enemy.c  game.c enemy_bullets.c decors.c
HEADERS = headers/
OBJ_D = obj
DEP_D = dep
OBJ = $(SRC:%.c=$(OBJ_D)/%.o)
DEP = $($(OBJ_D)/%.o=$(DEP_D)/%.d)
NAME = ft_shmup

$(shell mkdir -p $(OBJ_D) $(DEP_D))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	@echo "\e[0;32mExecutable created successfully ! 🧬\e[0m"

-include $(DEP)

$(OBJ_D)/%.o: %.c
	@mkdir -p $(OBJ_D) $(DEP_D)
	$(CC) -MMD -MP -c $< -o $@ $(CFLAGS) -I$(HEADERS)
	@mv $(@:.o=.d) $(DEP_D)/

clean:
	rm -r $(OBJ_D) $(DEP_D)
	@echo "\e[0;36mNo object files in this directory anymore 🧹\e[0m"

fclean :
	$(MAKE) clean
	rm -f $(NAME)
	@echo "\e[0;34mEverything's clean :D 🧼\e[0m"

re : 
	$(MAKE) fclean all
	@echo "\e[0;32mExecutable recreated successfully ! 🫡\e[0m"