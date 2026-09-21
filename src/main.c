#include <ncurses.h>
#include <stdlib.h>
#include "include/flatpak_service.h"

typedef enum {
  MENU_SEARCH,
  MENU_INSTALLED,
  MENU_REMOTES,
  MENU_RUNTIMES,
  MENU_EXIT,
  MENU_COUNT,
} MenuOption;

static const char *menu_labels[MENU_COUNT] = {
    "Search",
    "Installed Apps",
    "Remotes",
    "Runtimes",
    "Exit",
};

static void run_installed_apps(void) {
  clear();
  move(0, 0);
  printw("Installed Apps\n");
  printw("Press any key to return to the menu\n\n");

  size_t count;
  AppInfo *apps = get_installed_apps(&count);
  for (size_t i = 0; i < count; i++) {
    printw("%s - %s\n", apps[i].id, apps[i].branch);
  }
  free(apps);

  refresh();
  getch();
}

static void placeholder(MenuOption option) {
  clear();
  move(0, 0);
  printw("%s\n", menu_labels[option]);
  printw("Not implemented yet. Press any key to return to the menu.\n");

  refresh();
  getch();
}

static void draw_menu(MenuOption selected) {
  clear();
  move(0, 0);
  printw("flatman\n\n");

  for (MenuOption i = 0; i < MENU_COUNT; i++) {
    if (i == selected) {
      attron(A_REVERSE);
      printw("> %s\n", menu_labels[i]);
      attroff(A_REVERSE);
    } else {
      printw("  %s\n", menu_labels[i]);
    }
  }

  refresh();
}

static void run_menu(void) {
  MenuOption selected = MENU_SEARCH;
  int ch;

  draw_menu(selected);

  while ((ch = getch()) != 'q') {
    switch (ch) {
    case KEY_UP:
      if (selected > MENU_SEARCH)
        selected--;
      break;
    case KEY_DOWN:
      if (selected < MENU_COUNT - 1)
        selected++;
      break;
    case '\n':
    case '\r':
    case KEY_ENTER:
      if (selected == MENU_EXIT)
        return;
      if (selected == MENU_INSTALLED)
        run_installed_apps();
      else
        placeholder(selected);
      break;
    default:
      break;
    }
    draw_menu(selected);
  }
}

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  run_menu();

  endwin();

  return 0;
}
