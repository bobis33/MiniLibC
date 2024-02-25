##
## EPITECH PROJECT, 2024
## MiniLibC
## File description:
## Makefile
##

SRC         = src/memcpy.asm     \
			  src/memmove.asm    \
			  src/memset.asm     \
			  src/strchr.asm	 \
			  src/strcmp.asm     \
			  src/strlen.asm     \
			  src/strncmp.asm    \
			  src/strrchr.asm    \

CFLAGS	=	-fprofile-arcs -ftest-coverage

SRC_TESTS	= tests/tests.c

OBJ         = $(SRC:.asm=.o)

OBJ_TESTS	= $(SRC_TESTS:.c=.o)

NAME 		= libasm.so

NAME_TESTS	= unit_tests

%.o: %.asm
	nasm -f elf64 $<

all: $(NAME)

$(NAME): $(OBJ)
		ld -shared -fPIC -o $(NAME) $(OBJ)

tests_run: all $(OBJ_TESTS)
		gcc -o $(NAME_TESTS) $(OBJ_TESTS) -L. -lcriterion -lgcov
		-./$(NAME_TESTS)

clean:
		find -name "*.o" -delete

fclean: clean
		rm -f $(NAME)
		rm -f $(NAME_TESTS)
		find -name "*.gcda" -delete -or -name "*.gcno" -delete

re : fclean all

.PHONY: all clean tests_run fclean re