/*
** display.c for  in /home/robin/delivery/PSU_2016_tetris
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Mar 10 14:45:10 2017 Robin Pronnier
** Last update Wed Mar 15 14:38:15 2017 benoit pingris
*/

#include <ncurses.h>
#include <time.h>
#include "my.h"

static void		disp_info(t_binding k, t_time t, WINDOW *win)
{
  long			timer;

  timer = t.time_1 - t.time_2;
  wattron(win, COLOR_PAIR(7));
  box(win, 'a', 'a');
  wattron(win, COLOR_PAIR(9));
  mvwprintw(win, 2, 2, "HIGH SCORE\t%d", k.highscore * 10);
  wattron(win, COLOR_PAIR(10));
  mvwprintw(win, 3, 2, "SCORE\t\t%d", k.score * 10);
  wattron(win, COLOR_PAIR(11));
  mvwprintw(win, 5, 2, "LEVEL\t\t%d", k.level + k.score / 10);
  wattron(win, COLOR_PAIR(12));
  if (timer % 60 < 10)
    mvwprintw(win, 6, 2, "TIMER\t\t0%d : 0%d", timer / 60, timer % 60);
  else
    mvwprintw(win, 6, 2, "TIMER\t\t0%d : %d", timer / 60, timer % 60);
  wattron(win, COLOR_PAIR(14));
  mvwprintw(win, 7, 2, "LINES\t\t%d", k.score);
  wrefresh(win);
}

void		init_colors()
{
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_RED);
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(4, COLOR_BLUE, COLOR_BLUE);
  init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(6, COLOR_CYAN, COLOR_CYAN);
  init_pair(7, COLOR_WHITE, COLOR_WHITE);
  init_pair(8, COLOR_BLUE, COLOR_BLUE);
  init_pair(9, COLOR_GREEN, COLOR_BLACK);
  init_pair(10, COLOR_CYAN, COLOR_BLACK);
  init_pair(11, COLOR_RED, COLOR_BLACK);
  init_pair(12, COLOR_BLUE, COLOR_BLACK);
  init_pair(13, COLOR_WHITE, COLOR_BLACK);
  init_pair(14, COLOR_YELLOW, COLOR_BLACK);
}

static void		set_colors(char **tab, int i, int j, t_binding k)
{
  if ((tab[i][j] == '1') || (tab[i][j] == 'B'))
    attron(COLOR_PAIR(1));
  else if ((tab[i][j] == '2') || (tab[i][j] == 'C'))
    attron(COLOR_PAIR(2));
  else if ((tab[i][j] == '3') || (tab[i][j] == 'D'))
    attron(COLOR_PAIR(3));
  else if ((tab[i][j] == '4') || (tab[i][j] == 'E'))
    attron(COLOR_PAIR(4));
  else if ((tab[i][j] == '5') || (tab[i][j] == 'F'))
    attron(COLOR_PAIR(5));
  else if ((tab[i][j] == '6') || (tab[i][j] == 'G'))
    attron(COLOR_PAIR(6));
  else if ((tab[i][j] == '7') || (tab[i][j] == 'H'))
    attron(COLOR_PAIR(7));
  mvprintw(LINES/2 - k.map_row/2 + i, COLS/2 - k.map_col/2 + j, "%c", '#');
}

static void		print_map(char **tab, t_binding k, int i, int j)
{
  int			y;
  int			x;

  if ((tab[i][j] == '-') || (tab[i][j] == '+') || (tab[i][j] == '|')
      || (tab[i][j] == ' '))
    {
      if (tab[i][j] == '|' ||(tab[i][j] == '-') || (tab[i][j] == '+'))
	attron(COLOR_PAIR(7));
      else
	attron(COLOR_PAIR(13));
      y = LINES / 2 - k.map_row / 2 + i;
      x = COLS / 2 - k.map_col / 2 + j;
      mvprintw(y, x, "%c", tab[i][j]);
    }
  else
    set_colors(tab, i, j, k);
}

void		showtab_ncurses(char **tab, t_binding k, t_time t, WINDOW *win)
{
  int		y;
  int		x;
  int		i;
  int		j;

  time(&t.time_1);
  i = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  print_map(tab, k, i, j);
	  ++j;
	}
      ++i;
    }
  disp_info(k, t, win);
}
