CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
SANITIZE	:= -fsanitize=address -g -O1 -fno-omit-frame-pointer -fsanitize=undefined

NAME		:= push_swap

LIBFT_DIR	:= libft
LIB			:= libft.a
LIBFT		:= $(addprefix $(LIBFT_DIR)/,$(LIB))

INCLUDES	:= -I. -I./$(LIBFT_DIR)/includes

SRC			:= push_swap.c validate_input.c validate_integer_input.c \
			   operations1.c operations2.c compute_disorder.c \
			   bubble_sort.c insertion_sort.c call_backs.c

OBJ			:= $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SANITIZE) $^ -L./$(LIBFT_DIR) -lft -o $@ 

%.o: %.c
	$(CC) $(SANITIZE) $(INCLUDES) $(CFLAGS) -c $< -o $@ 

$(LIBFT): $(LIBFT_DIR)/*.c $(LIBFT_DIR)/includes/libft.h
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

clear:
	@clear
	
norminette: clear $(SRC)
	norminette $(SRC) push_swap.h
	@echo
	norminette $(LIBFT_DIR)/*.c $(LIBFT_DIR)/libft.h
	@echo

t: all input swap swap push rotate reverse_rotate

input: 
	@$(CC) $(SANITIZE) $(OBJ) -L./$(LIBFT_DIR) -lft -o push_swap_input
	@./tests/test_input.sh
	@rm push_swap_input

swap: test_swap swap2
	@./tests/test_swap.sh
	@rm test_swap
	@rm tests/operations/swap/test_swap.o
tests/operations/swap/test_swap.o: tests/operations/swap/test_swap.c
	@$(CC) $(CFLAGS) $(SANITIZE) -c $<  $(INCLUDES) -lft -o $@
test_swap: tests/operations/swap/test_swap.o validate_integer_input.o validate_input.o operations1.o operations2.o call_backs.o
	@$(CC) $(SANITIZE) $^ -L./$(LIBFT_DIR) -lft -o $@
swap2: test_swap2
	@./tests/test_swap2.sh
	@rm test_swap2
	@rm tests/operations/swap/test_swap2.o
tests/operations/swap/test_swap2.o: tests/operations/swap/test_swap2.c
	@$(CC) $(CFLAGS) $(SANITIZE) -c $<  $(INCLUDES) -lft -o $@
test_swap2: tests/operations/swap/test_swap2.o validate_integer_input.o validate_input.o operations1.o operations2.o call_backs.o

	@$(CC) $(SANITIZE) $^ -L./$(LIBFT_DIR) -lft -o $@

push: test_push
	@./tests/test_push.sh
	@rm test_push
	@rm tests/operations/push/test_push.o
tests/operations/push/test_push.o: tests/operations/push/test_push.c
	@$(CC) $(CFLAGS) $(SANITIZE) -c $<  $(INCLUDES) -lft -o $@
test_push: tests/operations/push/test_push.o validate_integer_input.o validate_input.o operations1.o operations2.o call_backs.o
	@$(CC) $(SANITIZE) $^ -L./$(LIBFT_DIR) -lft -o $@

rotate: test_rotate
	@./tests/test_rotate.sh
	@rm test_rotate
	@rm tests/operations/rotate/test_rotate.o
tests/operations/rotate/test_rotate.o: tests/operations/rotate/test_rotate.c
	@$(CC) $(CFLAGS) $(SANITIZE) -c $<  $(INCLUDES) -lft -o $@
test_rotate: tests/operations/rotate/test_rotate.o validate_integer_input.o validate_input.o operations1.o operations2.o call_backs.o
	@$(CC) $(SANITIZE) $^ -L./$(LIBFT_DIR) -lft -o $@

reverse_rotate: test_reverse_rotate
	@./tests/test_reverse_rotate.sh
	@rm test_reverse_rotate
	@rm tests/operations/reverse_rotate/test_reverse_rotate.o
tests/operations/reverse_rotate/test_reverse_rotate.o: tests/operations/reverse_rotate/test_reverse_rotate.c
	@$(CC) $(CFLAGS) $(SANITIZE) -c $<  $(INCLUDES) -lft -o $@
test_reverse_rotate: tests/operations/reverse_rotate/test_reverse_rotate.o validate_integer_input.o validate_input.o operations1.o operations2.o call_backs.o
	@$(CC) $(SANITIZE) $^ -L./$(LIBFT_DIR) -lft -o $@

.PHONY: all clean fclean re t rt norminette swap swap2 push rotate
