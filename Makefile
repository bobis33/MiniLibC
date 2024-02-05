##
## EPITECH PROJECT, 2024
## MiniLibC
## File description:
## Makefile
##

SRC 		= src/strlen.asm 	\
			  src/strchr.asm	\
			  src/strrchr.asm

OBJ         = $(SRC:.asm=.o)

NAME 		= libasm.so

%.o: %.asm
	nasm -f elf64 $<

all: $(NAME)

$(NAME): $(OBJ)
		ld -shared -fPIC -o $(NAME) $(OBJ)

clean:
		find -name "*.o" -delete

fclean: clean
		rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re