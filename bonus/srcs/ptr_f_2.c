/*
** ptr_f_2.c for tetris in /home/benoit.pingris/delivery/save_tetris/3
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Mar  2 14:35:11 2017 benoit pingris
** Last update Tue Mar 14 11:00:35 2017 benoit pingris
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

int	set_quit(t_binding *tetris, char *s)
{
  if (s == NULL || !(s[0] >= ' ' && s[0] <= '~'))
    return (ERROR);
  tetris->k_quit = s;
  return (SUCCESS);
}

int	set_size(t_binding *tetris, char *s)
{
  if ((tetris->map_row = get_row(s, ',')) <= 0 || tetris->map_row > 55)
    return (ERROR);
  if ((tetris->map_col = get_col(s, ',')) <= 0 || tetris->map_col > 200)
    return (ERROR);
  return (SUCCESS);
}

int	set_lvl(t_binding *tetris, char *s)
{
  if (s == NULL)
    return (ERROR);
  if ((tetris->level = my_getnbr(s)) <= 0)
    {
      my_printf("Error: the level must me positive.\n");
      return (ERROR);
    }
  return (SUCCESS);
}

int	set_next(t_binding *tetris, char *s)
{
  tetris->no_next = TRUE;
  return (SUCCESS);
}

int	set_debug(t_binding *tetris, char *s)
{
  tetris->debug = TRUE;
  return (SUCCESS);
}
