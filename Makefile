define Intro

		███████╗████████╗    ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗
		██╔════╝╚══██╔══╝    ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝
		█████╗     ██║       ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  
		██╔══╝     ██║       ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝  
		██║        ██║       ██║     ██║  ██║██║██║ ╚████║   ██║   ██║     
		╚═╝        ╚═╝       ╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝     

endef
export

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = Include/ft_printf.h

NAME = libftprintf.a

SRC = Src/ft_flags.c Src/ft_normalcase.c Src/ft_printf.c Src/ft_printtools.c Src/ft_putun.c Src/ft_printtools2.c

OBJ = ${SRC:.c=.o}

all : Intro $(NAME)
	@echo "\x1b[32m  The Program $(NAME) Is Ready To Use \x1b[0m"

$(NAME) : $(OBJ) $(HEADER)
	@ar -rc $(NAME) $(OBJ)
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\x1b[35m The Object File Of $< Is Created \x1b[0m"

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

bonus : all

re : fclean all

Intro :
	@echo "\x1b[32m $$Intro \x1b[0m"
