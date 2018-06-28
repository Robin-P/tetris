/*
** game_2.c<3> for tetirs in /home/benoit.pingris/delivery/PSU_2016_tetris/newTETRISBGJuL
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Mar  6 13:42:45 2017 benoit pingris
** Last update Mon Mar 13 12:35:25 2017 benoit pingris
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

char		**change_map(char **av)
{
  int		i;
  int		j;

  i = 0;
  while (av[i] != NULL)
    {
      j = 0;
      while (av[i][j] != '\0')
	{
	  if (av[i][j] >= '0' && av[i][j] <= '9')
	    av[i][j] = av[i][j] + 17;
	  j = j + 1;
	}
      i = i + 1;
    }
  return (av);
}

char		**rotate(char **tab)
{
  int		ch;

  ch = getch();
  if (ch == KEY_UP)
    return (get_next_form(tab));
  if (ch == 'a')
    printw("sa");
  return (tab);
}

char		**copy(char **tab, char **real, t_binding keys)
{
  int		i;
  int		j;

  i = 0;
  while (real[i])
    {
      j = 0;
      while (real[i][j] != '\0')
	{
	  if (real[i][j] >= '0' && real[i][j] <= '9')
	    real[i][j] = ' ';
	  tab[i][j] = real[i][j];
	  j = j + 1;
	}
      i = i + 1;
    }
  return (tab);
}

int		lose(char **tab)
{
  int		i;

  i = 0;
  while (tab[1][i])
    {
      if (tab[1][i] >= 'A' && tab[1][i] <= 'Z')
	return (1);
      ++i;
    }
  return (0);
}
