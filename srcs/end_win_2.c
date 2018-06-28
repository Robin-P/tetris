/*
** end_win_2.c for tetris in /home/benoit.pingris/delivery/PSU_2016_tetris
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Mar 13 17:26:23 2017 benoit pingris
** Last update Tue Mar 14 12:11:25 2017 benoit pingris
*/

#include <unistd.h>
#include <ncurses.h>
#include "my.h"

void	scanning()
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j < COLS)
    {
      while (i < LINES)
	{
	  refresh();
	  attron(COLOR_PAIR(bot_pos(8, 1)));
	  mvprintw(i++, j, "a");
	  usleep(200);
	}
      ++j;
      while (i >= 0)
	{
	  refresh();
	  attron(COLOR_PAIR(bot_pos(8, 1)));
	  mvprintw(i--, j, "a");
	  usleep(200);
	}
      ++j;
    }
}
