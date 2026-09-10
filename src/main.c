#include <ncurses.h>
#include "include/flatpak_service.h"

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  printw("flatman\n");

  move(5,5);

  size_t count;
  AppInfo *apps = get_installed_apps(&count);
  for (size_t i = 0; i < count; i++) {
    printw("%s - %s\n", apps[i].id, apps[i].branch);
  }
  
  refresh();

  while (getch() != 'q') {
  }

  endwin();

  return 0;
}
