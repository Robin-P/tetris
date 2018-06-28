/*
** turn.c<3> for tetris in /home/benoit.pingris/delivery/PSU_2016_tetris/newTETRISBGJuL
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Mar  6 14:01:25 2017 benoit pingris
** Last update Tue Mar  7 18:20:34 2017 Robin Pronnier
*/

#include <stdlib.h>
#include "my.h"

int	check_turn(t_coord c, char **tab, t_binding k)
{
  int	var1;
  int	var2;

  c.p = change(get_next_form(c.p));
  c.tmp = 0;
  while (c.p[c.tmp])
    {
      c.j = 0;
      while (c.p[c.tmp][c.j] != '\0')
	{
	  var1 = c.tmp + c.x + 1 + 1;
	  var2 = k.map_col / 2 - max_len(c.p) / 2 + c.j + c.ctrl + 1;
	  if (c.p[c.tmp][c.j] == '*')
	    if ((tab[var1 + 2] != NULL) &&
		((tab[var1][var2] == '|') || (tab[var1][var2] == '-') ||
		 (tab[var1][var2] == '+') ||
		 (tab[var1][var2] >= 'A' && tab[var1][var2] <= 'H')))
	      return (1);
	  c.j += 1;
	}
      c.tmp += 1;
    }
  return (0);
}

int	get_x_y(char **form1, char x_or_y)
{
  int	x;
  int	y;
  int	max_x;

  y = 0;
  max_x = 0;
  while (form1[y] != NULL)
    {
      x = 0;
      while (form1[y][x] != '\0')
	x++;
      if (x > max_x)
	max_x = x;
      y++;
    }
  return (x_or_y == 'x' ? max_x : y);
}

char	**get_next_form(char **form1)
{
  char	**form2;
  int	nb_line;
  int	x;
  int	x2;
  int	y1;
  int	x_max;

  x_max = get_x_y(form1, 'x');
  nb_line = get_x_y(form1, 'y');
  if ((form2 = malloc(sizeof(char *) * (x_max + 1))) == NULL)
    return (NULL);
  x = 0;
  while (x < x_max)
    {
      x2 = 0;
      y1 = nb_line;
      if ((form2[x] = malloc(sizeof(char) * (nb_line + 1))) == NULL)
	return (NULL);
      while (--y1 >= 0)
	form2[x][x2++] = (form1[y1][x] == '\0' ? ' ' : form1[y1][x]);
      form2[x][x2] = '\0';
      x++;
    }
  form2[x] = NULL;
  return (form2);
}
