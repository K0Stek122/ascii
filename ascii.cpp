#include "ascii.h"

/*
 * COLOR_PAIR(n)
 * COLOR_BLACK   0
 * COLOR_RED     1
 * COLOR_GREEN   2
 * COLOR_YELLOW  3
 * COLOR_BLUE    4
 * COLOR_MAGENTA 5
 * COLOR_CYAN    6
 * COLOR_WHITE   7
 */

void ascii::init_scr(bool noecho_)
{
  initscr();
  cbreak();
  if (noecho_)
    noecho();
}

void ascii::init_color()
{
  if (!has_colors())
  {
    printw("ERROR! This terminal does not support colors");
    getch();
  }

  start_color();
  init_pair(0, 0, 0);
  init_pair(1, 1, 0);
  init_pair(2, 2, 0);
  init_pair(3, 3, 0);
  init_pair(4, 4, 0);
  init_pair(5, 5, 0);
  init_pair(6, 6, 0);
  init_pair(7, 7, 0);
}

void ascii::end_scr()
{
  endwin();
}

void ascii::print(const char* text, int x, int y, WINDOW* win, void* arg)
{ 
  if (!win)
  {
    move(y, x);
    printw(text, arg);
    move(0, 0);
  }
  else
  {
    mvwprintw(win, y, x, text);
  }
}

void ascii::print_colored(const char* text, int x, int y, int color, WINDOW* win, void* arg=NULL)
{
  if (!win)
  {
    attron(COLOR_PAIR(color));
    move(y, x);
    printw(text, arg);
    move(0, 0);
    attroff(COLOR_PAIR(color));
  }
  else
  {
    wattron(win, COLOR_PAIR(color));
    mvwprintw(win, y, x, text);
    wattroff(win, COLOR_PAIR(color));
  }
}

WINDOW* ascii::print_window(int height, int width, int x, int y, int border_horizontal, int border_vertical)
{
  WINDOW* win = newwin(height, width, y, x);
  refresh();
  if (border_horizontal || border_vertical)
    box(win, border_vertical, border_horizontal);
  else
    box(win, 0, 0);
  //wrefresh(win);
  return win;
}
