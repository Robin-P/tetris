/*
** check_flags.c for tetris in /home/benoit.pingris/delivery/save_tetris/3/srcs
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Mar  1 21:59:39 2017 benoit pingris
** Last update Wed Mar 15 12:47:50 2017 benoit pingris
*/

#include <stdlib.h>
#include <ncurses.h>
#include <getopt.h>
#include "option.h"
#include "my.h"
#include "struct.h"

static int	(*set_opt[20])(t_binding *tetris, char *optarg) =
{
  set_left,
  set_left,
  set_right,
  set_right,
  set_turn,
  set_turn,
  set_drop,
  set_drop,
  set_pause,
  set_pause,
  set_lvl,
  set_lvl,
  set_size,
  set_debug,
  set_debug,
  set_next,
  set_next,
  set_quit,
  set_quit,
  set_help,
};

static int	check_good_opt(int ac, char **av)
{
  int	i;

  i = 1;
  while (av[i])
    {
      if (av[i][0] != '-' && av[i - 1][0] != '-')
	return (ERROR);
      ++i;
    }
  return (SUCCESS);
}

static int	options_check(struct option *o, int c, char **v, t_binding *t)
{
  int	d;
  int	index;

  d = 0;
  index = 0;
  if (check_good_opt(c, v) == ERROR)
    return (ERROR);
  while ((d = getopt_long_only(c, v, "", o, &index)) != -1
  	 && d < 20)
    {
      if (set_opt[d](t, optarg) == ERROR)
	return (ERROR);
    }
  if (!(d >= -1 && d < 20))
    return (ERROR);
  return (SUCCESS);
}

int	check_flags(int ac, char **av, t_binding *tetris)
{
  return (options_check(options, ac, av, tetris));
}
