/*
** set.c for tetris in /home/benoit.pingris/delivery/PSU_2016_tetris
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Mar 10 14:13:44 2017 benoit pingris
** Last update Wed Mar 15 12:29:50 2017 benoit pingris
*/

#include <term.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <struct.h>
#include "my.h"

void		set_tabs(t_tabs *t)
{
  t->pieces = NULL;
  t->map = NULL;
  t->new = NULL;
  t->tetrimino = NULL;
}

void		set_info_2(t_binding *t, t_time *my_time, t_tabs *my_tabs)
{
  time(&my_time->time_2);
  set_tabs(my_tabs);
  t->k_pause = SPACE;
  t->k_quit = "q";
  t->map_row = 20;
  t->map_col = 10;
  t->no_next = FALSE;
  t->level = 1;
  t->debug = FALSE;
  t->help = FALSE;
  t->score = 0;
}

char		*find_term(t_binding *tetris, char **envp)
{
  int		i;

  i = 0;
  while (envp[i])
    {
      if (envp[i][0] == 'T' &&
	  envp[i][1] == 'E' &&
	  envp[i][2] == 'R' &&
	  envp[i][3] == 'M' &&
	  envp[i][4] == '=')
	return (&envp[i][5]);
      ++i;
    }
  return (NULL);
}

int		set_info(t_binding *t, t_time *my_time, t_tabs *my_tabs, char **e)
{
  int		fd;
  char		*nb;
  int		err;

  if ((fd = open("srcs/highscore", O_CREAT | O_RDONLY, 0777)) == -1)
    return (ERROR);
  if ((t->my_term = find_term(t, e)) == NULL)
    return (ERROR);
  if (setupterm(t->my_term, 1, &err) == -1)
    return (ERROR);
  if ((t->k_turn = tigetstr("kcuu1")) == NULL ||
      (t->k_drop = tigetstr("kcud1")) == NULL ||
      (t->k_left = tigetstr("kcub1")) == NULL ||
      (t->k_right = tigetstr("kcuf1")) == NULL ||
      (t->k_music = tigetstr("khome")) == NULL)
    return (ERROR);
  if ((nb = get_next_line(fd)) == NULL)
    t->highscore = 0;
  else
    t->highscore = my_getnbr(nb);
  set_info_2(t, my_time, my_tabs);
  return (SUCCESS);
}
