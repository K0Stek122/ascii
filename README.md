# ascii
C++ ncurses basic wrapper

## What is this
A very basic (for now) linux ncurses wrapper to make the usage of ncurses simpler.
For now it only includes a handful of functions, but i play to expand this over time.

## How to use it
Simple. call the function init_scr() at the start of the main function, and end_scr() at the end of the program, every other function should be self explanatory,
However the next section will include explanation for all functions.

## Documentation
`void init_scr(bool noecho_ = false)` -> Initializes ncurses.\
`void init_color()` -> (optional) Initializes color support.\
`void end_scr()` -> cleans up the ncurses library after usage.\
`void print(const char* text, int x, int y, WINDOW* win, void* arg = NULL)` -> Prints text at the given coordinates. If there's no window, set it to NULL.\
`void print_colored(const char* text, int x, int y, int color, WINDOW* win, void* arg = NULL)` -> Prints colored text at the given coordinates. If there's no window, set it to NULL.\
`WINDOW* print_window(int height, int width, int x, int y, int border_horizontal = NULL, int border_vertical = NULL)` -> Creates a window (frame, buffer) at the given coordinates and height/width.\

## Example usage
```c++
int main()
{
  ascii::init_scr();
  while (true)
  {
    ascii::print("testing", 1, 1, NULL); //prints a text at coordinates 1, 1
    WINDOW* win = ascii::print_window(50, 50, 20, 20); //creates a window at coordinates 50, 50 with a size of 20, 20
    ascii::print("in a window!", 5, 5, win); //prints text at coordinates 5, 5 in a window
  }
  
  ascii::end_scr()
  return 0;
}
