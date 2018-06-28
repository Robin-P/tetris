/*
** sort_name.c for tetris in /home/benoit.pingris/delivery/save_tetris/3
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Mar  2 21:30:58 2017 benoit pingris
** Last update Tue Mar 14 10:28:49 2017 benoit pingris
*/

#include "my.h"

static int		check_sort(char **t)
{
  int			i;

  i = 1;
  while (t[i])
    {
      if (my_strcmp(t[i - 1], t[i]) > 0)
	return (1);
      ++i;
    }
  return (0);
}

char		**sort_name(char **t)
{
  int		i;
  char		*str;

  while (check_sort(t) == 1)
    {
      i = 1;
      while (t[i])
	{
	  if (my_strcmp(t[i - 1], t[i]) > 0)
	    {
	      str = t[i - 1];
	      t[i - 1] = t[i];
	      t[i] = str;
	    }
	  ++i;
	}
    }
  return (t);
}
