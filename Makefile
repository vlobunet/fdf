NAME		= fdf
SRCS		=	main.c \
				validation_map.c \
				get_next_line.c \
				check_color.c \
				src_file.c \
				rotation.c \
				key_hook.c \
				print_image.c \

SRCO		= $(SRCS:.c=.o)
FLAGS		= -Wall -Wextra -Werror
FRMW		= -lmlx -framework OpenGL -framework Appkit
LIB			= libft/libft.a minilibx_macos/libmlx.a
SRC_PATH	= .
OBJ_PATH	= obj
SRC = $(addprefix $(SRCS_PATH)/,$(SRCS))
OBJ = $(addprefix $(OBJ_PATH)/,$(SRCO))

.PHONY: all, clean, fclean, re


### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[01;38;05;46m
YELLOW      = \033[38;05;226m
BLUE        = \033[03;38;05;21m
VIOLET      = \033[01;38;05;201m
CYAN        = \033[1;36m
WHITE       = \033[01;38;05;15m
RES			= \033[m


all: $(NAME)
	@echo  "\b]$(RES)$(YELLOW) : OK$(RES)"

$(NAME): $(LIB) $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LIB) $(FRMW)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc -c $(FLAGS) -o $@ -c $<
	@echo  "\b=>\c)"

$(LIB):
	@echo  "$(GREEN)Compiling the libft : $(RES)$(WHITE)[ \c)"
	@make -C libft
	@echo  "$(GREEN)Compiling the minilibx : $(RES)$(WHITE)[ \c)"
	@make -C minilibx_macos
	@echo  "$(GREEN)Compiling the fdf : $(RES)$(WHITE)[ \c)"


clean:
	@rm -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make -C libft clean
	@make -C minilibx_macos clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

# NAME = fdf

# CC = gcc

# FLAGS = -Wall -Wextra -Werror

# FRAM = -lmlx -framework OpenGL -framework AppKit

# SRCS =	main.c \
# 		validation_map.c \
# 		get_next_line.c \
# 		check_color.c \
# 		src_file.c \

# OBJS = $(SRCS:.c=.o)

# LIBFT_DIR = ./libft/

# LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

# all: $(NAME)

# $(NAME): $(OBJS)
# 	make -C $(LIBFT_DIR)
# 	$(CC) $(FLAGS) $(FRAM) $(SRCS) $(LIBFT) -o $(NAME)

# .c.o.:
# 	$(CC) $(FLAGS) $(FRAM) -c $< -o $@

# clean:
# 	/bin/rm -rf $(OBJS)
# 	make -C $(LIBFT_DIR) clean

# fclean: clean
# 	/bin/rm -rf $(NAME)
# 	make -C $(LIBFT_DIR) fclean

# re: fclean all