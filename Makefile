SOURCES	= ft_printf.c ft_utils.c
# .c=.o implicitly compiles the source-code into binary objects.
OBJECTS	= $(SOURCES:.c=.o)
NAME	= libftprintf.a
LIBFT_PATH = ./libft
LIBFT	= $(LIBFT_PATH)/libft.a
MAKEC 	= make -C
COMPILE	= cc
FLAGS	= -Wall -Wextra -Werror
REMOVE	= rm -f

# Compiles from open-source to binary, but doesn't link. Necessary to run flags.
.c.o:		$(OBJECTS)
	$(COMPILE) $(FLAGS) -c $< -o $(<:.c=.o)

# Calling its name acts as its own makefile. Will compile only if the object 
# dependencies are fulfilled. ar creates an archive (here, library) from the 
# files member (objects), replacing them as needed. ranlib simply indexes 
# every function in the library (equivalent to s in crs).
# @ hides the clutter from the terminal.
$(NAME):	$(LIBFT) $(OBJECTS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJECTS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

all:		$(NAME)

# Removes only compiled objects.
clean:
	@$(MAKEC) $(LIBFT_PATH) clean
	@$(REMOVE) $(OBJECTS)

# Removes compiled objects first, then proceeds to remove the library itself.
fclean:		clean
	@make fclean -C $(LIBFT_PATH)
	@$(REMOVE) libft.a
	@$(REMOVE) $(NAME)

# Forces the recompilation even if everything is up to date.
re:			fclean all
	@$(MAKEC) $(LIBFT_PATH)

run:
#	@cc *.c ./libft/*.c && time valgrind -s ./a.out && rm a.out
	@cc *.c ./libft/*.c && ./a.out && rm a.out

# Ignores files that could eventually be named after any of these parameters.
.PHONY:		libft all clean fclean re run
