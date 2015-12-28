/*
 * Video Attributes:
 *
 * A_NORMAL - Normal display (no highlight)
 * A_STANDOUT- Best highlighting mode of the terminal.
 * A_UNDERLINE - Underlining
 * A_REVERSE - Reverse video
 * A_BLINK - Blinking
 * A_DIM - Half bright
 * A_BOLD - Extra bright or bold
 * A_PROTECT - Protected mode
 * A_INVIS - Invisible or blank mode
 * A_ALTCHARSET - Alternate character set
 * A_CHARTEXT - Bit-mask to extract a character
 * COLOR_PAIR(n) - Color-pair number n
 *
 */

#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int ch, prev, row, col;
  prev = EOF;
  FILE *fp;
  int y, x;

  if (argc != 2) {
    printf("Usage: %s <a c file name>\n", argv[0]);
    exit(1);
  }

  /*
   * Open the given file and set it to our file pointer.
   */

  fp = fopen(argv[1], "r");

  if (fp == NULL) {
    perror("Cannot open input file");
    exit(1);
  }

  /*
   * Init screen and get the max y and x, store those
   * in row, col variables.
   */

  initscr();
  getmaxyx(stdscr, row, col);

  while((ch = fgetc(fp)) != EOF) {
    getyx(stdscr, y, x);
    if (y == (row - 1)) {
      printw("<- Press Any Key ->");
      getch();
      clear();
      move(0, 0);
    }

    if (prev == '/' && ch == '*') {
      attron(A_BOLD);
      getyx(stdscr, y, x);
      move(y, x - 1);
      printw("%c%c", '/', ch);
    } else {
      printw("%c", ch);
    }

    refresh();

    if (prev == '*' && ch == '/')
      attroff(A_BOLD);

    prev = ch;
  }

  endwin();
  fclose(fp);

  return 0;
}
