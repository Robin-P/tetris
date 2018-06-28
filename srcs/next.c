/*
** next.c for tetris in /home/benoit.pingris/delivery/PSU_2016_tetris/newTETRISBGJuL/3
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Mar  6 14:21:15 2017 benoit pingris
** Last update Fri Mar 10 14:08:42 2017 benoit pingris
*/

#include <ncurses.h>
#include "my.h"

void		tab_ncurses(char **tab, WINDOW *win, int height, int width)
{
  int		i;
  int		y;

  start_color();
  y = height - get_x_y(tab, 'y') - 1;
  i = 1;
  while (tab[i])
    {
      mvwprintw(win, y, 2, tab[i++]);
      ++y;
    }
}

int		max_width(char ***pieces)
{
  int		i;
  int		width;

  i = 0;
  width = 0;
  while (pieces[i])
    {
      if (max_len(pieces[i]) >= width)
	width = max_len(pieces[i]);
      i++;
    }
  return (width);
}

int		max_height(char ***pieces)
{
  int		i;
  int		height;

  i = 0;
  height = 0;
  while (pieces[i])
    {
      if (get_x_y(pieces[i], 'y') >= height)
	height = get_x_y(pieces[i], 'y');
      i++;
    }
  return (height);
}

void		disp_next(t_binding keys, int i, char ***pieces, WINDOW	*win)
{
  int		height;
  int		width;

  height = max_height(pieces) + 4;
  width = max_width(pieces) + 4;
  wattron(win, COLOR_PAIR(7));
  box(win, '|', '-');
  wattroff(win, COLOR_PAIR(7));
  tab_ncurses(pieces[i], win, height, width);
  wrefresh(win);
  wclear(win);
}
