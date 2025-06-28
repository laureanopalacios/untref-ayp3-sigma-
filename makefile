CC=gcc
CFLAGS=-Wall -g
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
TARGET=programa

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o $(TARGET)
