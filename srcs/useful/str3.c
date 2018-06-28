/*
** str3.c for tetris in /home/benoit.pingris/delivery/save_tetris/3
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Mar  2 21:58:18 2017 benoit pingris
** Last update Mon Mar 13 13:00:42 2017 benoit pingris
*/

#include <stdlib.h>
#include "my.h"

char	*my_mallocat(const char *s1, const char *s2)
{
  int	i;
  int	f;
  char	*new;

  i = my_strlen(s1) * my_strlen(s2);
  f = 0;
  if ((new = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  new[0] = '\0';
  while (s1[i])
    new[i] = s1[i++];
  while (s2[f])
    new[i++] = s2[f++];
  new[i] = '\0';
  return (new);
}

void	my_showtab1(char **tab)
{
  int	i;

  i = 1;
  while (tab[i])
    {
      my_putstr(tab[i++], 1);
      my_putchar('\n');
    }
}

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}

void	my_showtabtab(char ***tab)
{
  int	i;

  i = 0;
  while (tab[i])
    my_showtab(tab[i++]);
}

int	max_len(char **av)
{
  int	i;
  int	j;
  int	max;

  max = 0;
  i = 0;
  while (av[i] != NULL)
    {
      j = 0;
      while (av[i][j] != '\0')
	{
	  j = j + 1;
	}
      if (j > max)
	max = j;
      i = i + 1;
    }
  return (max);
}
