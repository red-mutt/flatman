CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -pedantic -MMD -MP -Isrc/include $(shell pkg-config --cflags flatpak glib-2.0 gio-2.0 ncurses)
LDLIBS = $(shell pkg-config --libs flatpak glib-2.0 gio-2.0 ncurses)

TARGET = flatman

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDLIBS)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
