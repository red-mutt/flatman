CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic -MMD -MP -Isrc/include $(shell pkg-config --cflags flatpak glib-2.0 gio-2.0 ncurses)
LDLIBS   := $(shell pkg-config --libs flatpak glib-2.0 gio-2.0 ncurses)

TARGET = flatman

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDLIBS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
