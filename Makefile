CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I./include
LDFLAGS = 
SRC = src/main.c
TARGET = shoto

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET) *.o

debug: CFLAGS += -g -DDEBUG
debug: clean $(TARGET)

.PHONY: all clean debug
