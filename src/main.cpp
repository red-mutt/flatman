#include <ncurses.h>
#include "include/flatpak_service.hpp"

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  printw("flatman\n");

  move(5,5);
  
  refresh();

  while (getch() != 'q') {
  }

  endwin();

  return 0;
}
