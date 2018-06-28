/*
** my_basics_funcs.c for header in /home/benoit.pingris/delivery/PSU_2016_my_printf
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Nov 18 16:45:22 2016 benoit pingris
** Last update Wed Mar  1 22:30:29 2017 benoit pingris
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_printf.h"

char	*my_revstr(char *str)
{
  int	i;
  int	f;
  int	tmp;

  i = my_strlen(str) - 1;
  f = 0;
  tmp = 0;
  while (i > f)
    {
      tmp = str[f];
      str[f] = str[i];
      str[i] = tmp;
      i--;
      f = i + 1;
    }
  return (str);
}
