/*
** end_win.c for tetris in /home/benoit.pingris/delivery/PSU_2016_tetris
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Mar 13 16:49:26 2017 benoit pingris
** Last update Tue Mar 14 13:09:44 2017 benoit pingris
*/

#include <ncurses.h>
#include <unistd.h>
#include "my.h"

void	curtain()
{
  int	i;
  int	h;

  h = 0;
  while (h <= LINES / 2)
    {
      i = 0;
      while (i <= COLS)
	{
	  refresh();
	  attron(COLOR_PAIR(bot_pos(8, 1)));
	  mvprintw(h, i, "a");
	  mvprintw(LINES - 1 - h, COLS - i , "a");
	  usleep(300);
	  ++i;
	}
      ++h;
    }
}

void	random_point()
{
  int	h;
  int	i;
  int	r;

  r = 0;
  while (r < 22000)
    {
      refresh();
      attron(COLOR_PAIR(bot_pos(8, 1)));
      h = bot_pos(LINES, 0);
      i = bot_pos(COLS, 0);
      mvprintw(h, i, "a");
      ++r;
      usleep(12);
    }
}

void	spiral_2(int *i, int *j, int *new_l, int *new_c)
{
  while (*j < *new_c)
    {
      refresh();
      attron(COLOR_PAIR(bot_pos(8, 1)));
      mvprintw(*i, *j, "a");
      *j = *j + 1;
      usleep(50);
    }
  *new_c = *new_c - 1;
  while (*i < *new_l)
    {
      refresh();
      attron(COLOR_PAIR(bot_pos(8, 1)));
      mvprintw(*i, *j, "a");
      *i = *i + 1;
      usleep(50);
    }
  *new_l = *new_l - 1;
}

void	spiral_3(int *i, int *j, int *a, int *b)
{
  while (*j > *a)
    {
      refresh();
      attron(COLOR_PAIR(bot_pos(8, 1)));
      mvprintw(*i, *j, "a");
      *j = *j - 1;
      usleep(50);
    }
  *a = *a + 1;
  while (*i > *b)
    {
      refresh();
      attron(COLOR_PAIR(bot_pos(8, 1)));
      mvprintw(*i, *j, "a");
      *i = *i - 1;
      usleep(50);
    }
  *b = *b + 1;
}

void	spiral()
{
  int	a;
  int	b;
  int	i;
  int	j;
  int	new_c;
  int	new_l;

  a = 0;
  b = 0;
  new_c = COLS;
  new_l = LINES;
  i = 0;
  j = 0;
  while (i != (LINES + 1) / 2  && j != COLS / 2 + 1)
    {
      spiral_2(&i, &j, &new_l, &new_c);
      spiral_3(&i, &j, &a, &b);
    }
}
