/*
** error.c for tetris in /home/benoit.pingris/delivery/save_tetris/3
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Mar  2 22:40:35 2017 benoit pingris
** Last update Tue Mar 14 10:29:03 2017 benoit pingris
*/

#include <stdlib.h>
#include "my.h"

static int		check_tab_2(char **t)
{
  int			i;
  int			j;

  i = 1;
  while (t[i])
    {
      j = 0;
      while (t[i][j])
	{
	  if (t[i][j] != ' ' && t[i][j] != '*')
	    return (-1);
	  ++j;
	}
      ++i;
    }
  return (0);
}

static int		check_tab(char **t, int a, int b)
{
  int			nb;
  int			i;

  nb = 0;
  if (count_lines(t) != b)
    return (-1);
  i = 0;
  if (check_tab_2(t) == -1)
    return (-1);
  while (t[i])
    {
      if (my_strlen(t[i]) == a)
	++nb;
      ++i;
    }
  if (nb == 0)
    return (-1);
  return (0);
}

int		my_getline(char *s)
{
  int		nb;
  static int	i = 0;

  nb = 0;
  while (((s[i] != '\0') && (s[i] < '0')) || (s[i] > '9'))
    ++i;
  if (s[i] == '\0')
    {
      i = 0;
      return (-1);
    }
  while (s[i] >= '0' && s[i] <= '9')
    {
      nb = nb * 10 + s[i] - '0';
      ++i;
    }
  if (s[i] == '\0')
    i = 0;
  return (nb);
}

static int		check_line(char *s)
{
  int			i;
  int			nb;

  i = 0;
  nb = 0;
  if (s == NULL)
    return (-1);
  while (s[i])
    {
      if (s[i] == ' ')
	++i;
      else if (s[i] < '0' || s[i] > '9')
	return (-1);
      else
	{
	  while (s[i] && s[i] <= '9' && s[i] >= '0')
	    ++i;
	  ++nb;
	}
    }
  if (nb != 3)
    return (-1);
  return (0);
}

int		check_error(char **t, int ch, t_binding k, t_tabs *m)
{
  int		a;
  int		b;
  int		c;

  if ((check_line(t[0]) == -1) || ((a = my_getline(t[0])) == -1)
      || ((b = my_getline(t[0])) == -1) || ((c = my_getline(t[0])) == -1)
      || (a > k.map_col) || (b > k.map_row) || (check_tab(t, a, b) == -1))
    {
      if (ch == 0)
	my_putstr("Error\n", 2);
      return (ERROR);
    }
  if (ch == 0)
    {
      my_printf("Size %d*%d : Color %d : \n", a, b, c);
      my_showtab1(t);
    }
  if (stock_pieces(t, m) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
