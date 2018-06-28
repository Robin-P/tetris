/*
** check.c for  in /home/robin/delivery/PSU_2016_tetris
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Tue Mar  7 18:15:10 2017 Robin Pronnier
** Last update Thu Mar  9 17:09:11 2017 Robin Pronnier
*/

#include <unistd.h>
#include "my.h"

int		check_stop(char **tab)
{
  int		i;
  int		j;

  i = 1;
  while (tab[i + 1] != NULL)
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] >= '0' && tab[i][j] <= '9')
	    if ((tab[i + 1][j] >= 'A' && tab[i + 1][j] <= 'H') ||
		(tab[i + 1][j] == '-'))
	      return (1);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (0);
}

int		check_lat(char **tab, int nb)
{
  int		i;
  int		j;

  i = 1;
  while (tab[i + 2] != NULL)
    {
      j = 1;
      while (tab[i][j] != '|')
	{
	  if (tab[i][j] >= '0' && tab[i][j] <= '9')
	    if ((tab[i][j + nb] == '|') || (tab[i][j + nb] == '+')
		|| (tab[i][j + nb] >= 'A' && tab[i][j + nb] <= 'H'))
	      return (1);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (0);
}
