#include <iostream>
#include <ncurses.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>

#include "ascii.h"

struct vector
{
  vector(int x, int y)
  {
    this->x = x;
    this->y = y;
  }
  
  int x;
  int y;
};

int main()
{

  unsigned int inc = 69;
  std::string str = std::to_string(inc);
  
  ascii::init_scr(true);
  //ascii::init_color();

  int x = 0;
  int y = 0;

  std::vector<vector> items;
  
  while (true)
  {
    //WINDOW* win = ascii::print_window(15, 15, 0, 0);

    int c = getch();
    switch (c)
      {
      case 97: //a
	x--;
	clear();
	break;
      case 100: //d
	x++;
	clear();
	break;
      case 119: //w
	y--;
	clear();
	break;
      case 115: //s
	y++;
	clear();
	break;
      case 112: //p
	items.push_back(vector(x, y));
	break;
      }

    ascii::print("+", x, y, NULL);

    for (int i = 0; i < items.size(); i++)
    {
      ascii::print("#", items[i].x, items[i].y, NULL);
    }
    
    //clear();
    refresh();
    //wrefresh(win);
  }
  
  ascii::end_scr();
  
  return 0;
}
