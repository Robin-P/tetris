/*
** fall.c for  in /home/robin/delivery/PSU_2016_tetris
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Mar 10 14:44:58 2017 Robin Pronnier
** Last update Wed Mar 15 14:22:32 2017 benoit pingris
*/

#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "my.h"

int	count_lines(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    ++i;
  return (i - 1);
}

char	**piece(char **tab, char **str)
{
  int	i;
  int	j;
  int	a;

  i = 1;
  a = 0;
  if ((tab = malloc(sizeof(char *) * (count_lines(str) + 2))) == NULL)
    return (NULL);
  while (str[i])
    {
      if ((tab[a] = malloc(sizeof(char) * (my_strlen(str[i]) + 2))) == NULL)
	return (NULL);
      j = 0;
      while (str[i][j] != '\0')
	{
	  tab[a][j] = str[i][j];
	  j = j + 1;
	}
      tab[a][j] = '\0';
      a = a + 1;
      i = i + 1;
    }
  tab[a] = NULL;
  return (tab);
}

char	**falling(t_coord *c, char **tab, t_binding k)
{
  int	var1;
  int	var2;

  while (c->p[c->tmp])
    {
      c->j = 0;
      while (c->p[c->tmp][c->j] != '\0')
	{
	  if (c->p[c->tmp][c->j] == '*')
	    {
	      var1 = c->tmp + c->x + 1;
	      var2 = k.map_col / 2 - max_len(c->p) / 2 + c->j + c->ctrl + 1;
	      tab[var1][var2] = c->n + 48;
	    }
	  c->j += 1;
	}
      c->tmp += 1;
    }
  return (tab);
}

char	*my_controls(t_coord *c, t_tabs *s, t_binding k, t_coord my_c)
{
  char	*str;

  if ((str = press_key(0, 1, 0, 0)) == SPECIAL_ERR)
    return (SPECIAL_ERR);
  if ((c->ret = controls(k, s->pieces[c->tmp], s->map, str)) == 5)
    {
      endwin();
      return (NULL);
    }
  else if (c->ret == 2)
    {
      if (check_turn(my_c, s->map, k) == 0)
	c->p = change(get_next_form(c->p));
      c->ctrl -= 2;
    }
  else if (c->ret == 3)
    while (check_stop(s->map) == 0)
      {
	s->map = copy(s->map, s->new, k);
	c->tmp = 0;
	s->map = falling(c, s->map, k);
	c->x = c->x + 1;
      }
  music_conf(c->benoit, str, &k);
  return ("ok");
}

char	**falling_2(t_tabs s, t_coord c, t_time t, t_binding k)
{
  t.start_t = clock() / 1000;
  while (check_stop(s.map) == 0)
    {
      t.end_t = clock() / 1000;
      refresh();
      s.map = copy(s.map, s.new, k);
      c.tmp = 0;
      if (t.end_t - t.start_t > 1000 - k.level * 100)
	{
	  t.start_t = clock() / 1000;
	  s.map = falling(&c, s.map, k);
	  c.x = c.x + 1;
	}
      s.map = falling(&c, s.map, k);
      my_controls(&c, &s, k, c);
      if (c.ret == 5)
	{
	  kill_music(&c);
	  endwin();
	  return (NULL);
	}
      c.ctrl += c.ret;
      showtab_ncurses(s.map, k, t, c.my_win);
    }
  return (s.map);
}
