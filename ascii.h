#pragma once
#include <iostream>
#include <ncurses.h>
#include <cstdarg>

namespace ascii
{
  void init_scr(bool noecho_ = false); //Initializes the ncurses library
  void init_color();
  void end_scr(); //cleans up the ncurses library
  void print(const char* text, int x, int y, WINDOW* win, void* arg = NULL);
  void print_colored(const char* text, int x, int y, int color, WINDOW* win, void* arg = NULL);
  WINDOW* print_window(int height, int width, int x, int y, int border_horizontal = NULL, int border_vertical = NULL); //creates a window
}
