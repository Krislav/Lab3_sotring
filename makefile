CC = gcc
CFLAGS = -Wall -Wextra -g

SRCS = main.c args_parser.c sorting_method.c struct_inf.c struct_stack.c
HEADERS = args_parser.h sorting_method.h struct_inf.h struct_stack.h
OBJS = $(SRCS:.c=.o)

TARGET = var

.PHONY: all clean cleanall

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

cleanall:
	rm -rf $(OBJS) $(TARGET)