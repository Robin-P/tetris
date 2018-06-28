/*
** ptr_f_1.c for tetris in /home/benoit.pingris/delivery/save_tetris/3
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Mar  2 14:25:39 2017 benoit pingris
** Last update Tue Mar 14 11:00:57 2017 benoit pingris
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

int	set_right(t_binding *tetris, char *s)
{
  if (s == NULL || !(s[0] >= ' ' && s[0] <= '~') || my_strlen(s) == 0)
    return (ERROR);
  tetris->k_right = s;
  return (SUCCESS);
}

int	set_left(t_binding *tetris, char *s)
{
  if (s == NULL || !(s[0] >= ' ' && s[0] <= '~') || my_strlen(s) == 0)
    return (ERROR);
  tetris->k_left = s;
  return (SUCCESS);
}

int	set_turn(t_binding *tetris, char *s)
{
  if (s == NULL || !(s[0] >= ' ' && s[0] <= '~') || my_strlen(s) == 0)
    return (ERROR);
  tetris->k_turn = s;
  return (SUCCESS);
}

int	set_drop(t_binding *tetris, char *s)
{
  if (s == NULL || !(s[0] >= ' ' && s[0] <= '~') || my_strlen(s) == 0)
    return (ERROR);
  tetris->k_drop = s;
  return (SUCCESS);
}

int	set_pause(t_binding *tetris, char *s)
{
  if (s == NULL || !(s[0] >= ' ' && s[0] <= '~') || my_strlen(s) == 0)
    return (ERROR);
  tetris->k_pause =  s;
  return (SUCCESS);
}
