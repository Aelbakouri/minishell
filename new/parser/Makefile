NAME = hello.out
CC			= gcc

SRCS = expand.c main.c fill_node.c ft_cmdtrim.c ft_cmdsubsplit.c parse_args.c utils.c ft_strtrim_all.c
LIBFT		= libft/libft.a

OBJS = $(SRCS:.c=.o)
flags = -Wall -Werror -Wextra

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

$(NAME): $(OBJS)
	${MAKE} -C libft
	$(CC)  -o $(NAME) $(OBJS) $(LIBFT) -lreadline
	@rm $(OBJS)

clean:
	-rm *.out
	-rm *.o
	-rm src/*.o

