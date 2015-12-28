#include <ncurses.h>

int main() {
  initscr(); // Start curses mode
  printw("Hello world!"); // Print Hello World

  /*
   * printw actually prints "Hello world!" to current x, y coords (0, 0).
   * This window is called `stdscr`.
   */

  refresh(); // Actually print it on the screen

  /*
   * In actuality, the printw function prints to the virtual window. So
   * we can do multiple writes, and call refresh() which will look at the
   * virtual window and update accordingly.
   */

  getch(); // Wait for user input
  endwin(); // End curses mode

  return 0;
}
