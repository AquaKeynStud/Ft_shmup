CC = gcc
CFLAGS = -Wall -Wextra -Werror -lncurses
SRC = main.c player.c bullet.c enemy.c  game.c enemy_bullets.c
OBJ = $(SRC:.c=.o)
NAME = ft_shmup

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)