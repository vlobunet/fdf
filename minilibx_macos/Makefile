
NAME	=	libmlx.a
SRC		= 	mlx_shaders.c \
			mlx_new_window.m \
			mlx_init_loop.m \
			mlx_new_image.m \
			mlx_xpm.c \
			mlx_int_str_to_wordtab.c \


OBJ1	=	$(SRC:.c=.o)
OBJ		=	$(OBJ1:.m=.o)
CFLAGS	+=	-O2

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
	
$(NAME):$(OBJ)
	@ar -r $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@cc -c $< -o $@
	@echo  "\b=>\c)"

%.o: %.m
	@cc -c $< -o $@
	@echo  "\b=>\c)"

clean:
	@rm -f $(NAME) $(OBJ) *~
	@rm -f mlx_app

re: clean all