/*
** game_3.c for tetris in /home/benoit.pingris/delivery/PSU_2016_tetris/newTETRISBGJuL/3
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Mar  6 14:12:52 2017 benoit pingris
** Last update Wed Mar 15 14:18:40 2017 benoit pingris
*/

#include <unistd.h>
#include <time.h>
#include <ncurses.h>
#include "my.h"

int		controls(t_binding keys, char **piece, char **t, char *s)
{
  int		ret;

  ret = 0;
  keypad(stdscr, TRUE);
  if (s != NULL)
    {
      if (((my_strstr(s, keys.k_left)) == 0) && (check_lat(t, -1) == 0))
	ret = (any_key(-1));
      else if (((my_strstr(s, keys.k_right)) == 0)  && (check_lat(t, 1) == 0))
	ret = (any_key(1));
      else if ((my_strstr(s, keys.k_turn)) == 0)
	ret = (any_key(2));
      else if ((my_strstr(s, keys.k_quit)) == 0)
	ret = (any_key(5));
      else if ((my_strstr(s, keys.k_drop)) == 0)
	ret = (any_key(3));
      else if ((my_strstr(s, keys.k_pause)) == 0)
	{
	  press_key(1, 1, 0, 0);
	  while ((my_strstr(s, keys.k_pause)) != 0)
	    press_key(0, 1, 0, 0);
	  press_key(1, 1, 0, 0);
	}
    }
  return (ret);
}

static int		prep_line(char **tab, sfMusic *plouf)
{
  int			i;
  int			j;
  int			a;

  i = 1;
  while (tab[i + 1] != NULL)
    {
      j = 1;
      a = 1;
      while (tab[i][j] != '|')
	{
	  if (tab[i][j] >= 'A' && tab[i][j] <= 'H')
	    a = a + 1;
	  j = j + 1;
	}
      if (a == j)
	{
	  sfMusic_play(plouf);
	  return (1);
	}
      i = i + 1;
    }
  return (0);
}

static void		line_break1(char **tab, t_binding keys, int i, int j)
{
  while (tab[i - 1][0] != '+')
    {
      j = 1;
      while (tab[i][j] != '|')
	{
	  tab[i][j] = tab[i - 1][j];
	  j = j + 1;
	}
      i = i - 1;
    }
  tab[i][j] = '|';
  tab[i][0] = '|';
  j = 1;
  while (tab[i][j] != '|')
    {
      tab[i][j] = ' ';
      j = j + 1;
    }
}

int		line_break(char **tab, t_binding keys, int x, sfMusic *plouf)
{
  int		i;
  int		j;
  int		a;

  while (prep_line(tab, plouf) == 1)
    {
      a = 1;
      i = 1;
      j = 1;
      while ((tab[i + 1] != NULL) && (a != 0))
	{
	  j = 1;
	  a = 0;
	  while (tab[i][j] != '\0')
	    {
	      if (tab[i][j] == ' ')
		a = a + 1;
	      j = j + 1;
	    }
	  i = i + 1;
	}
      x = x + 1;
      line_break1(tab, keys, i - 1, j);
    }
  return (x);
}
