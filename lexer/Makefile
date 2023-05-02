NAME = hello.out
# SRCS = $(wildcard src/*.c)
SRCS = src/lexer.c  src/main.c src/token.c

OBJS = $(SRCS:.c=.o)
flags = -g


$(NAME): $(OBJS)
	gcc $(OBJS) $(flags) -o $(NAME) -lreadline
	mv *.o ..

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

install:
	make
	cp ./hello.out /usr/local/bin/hello

clean:
	-rm *.out
	-rm *.o
	-rm src/*.o
