/*
** ptr_f_3.c for tetris in /home/benoit.pingris/delivery/save_tetris/3
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Mar  2 14:51:45 2017 benoit pingris
** Last update Mon Mar  6 13:09:16 2017 benoit pingris
*/

#include <ncurses.h>
#include "my.h"
#include "struct.h"

int	set_help(t_binding *tetris, char *s)
{
  tetris->help = TRUE;
  return (SUCCESS);
}
