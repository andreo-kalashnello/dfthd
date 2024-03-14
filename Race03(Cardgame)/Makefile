NAME = race03
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
SRC_DIR = src
INC_DIR = inc
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/poker.c $(SRC_DIR)/validation.c
OBJS = $(SRCS:.c=.o)
INC = -I $(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(INC)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
