CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = my_mastermind
SRCS = main.c mastermind.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)

fclean: clean

re: fclean all
