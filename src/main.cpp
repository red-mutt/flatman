#include <ncurses.h>

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  printw("flatman\n");

  refresh();

  while (getch() != 'q') {
  }

  endwin();

  return 0;
}
