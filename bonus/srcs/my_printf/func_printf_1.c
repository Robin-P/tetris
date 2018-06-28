/*
** func_printf.c for my_printf in /home/benoit.pingris/delivery/PSU_2016_my_printf
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Nov  8 18:11:57 2016 benoit pingris
** Last update Wed Mar  1 22:34:12 2017 benoit pingris
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

int	my_intlen(int nb)
{
  int	i;

  i = 0;
  if (nb < 0)
    i = i + 1;
  while (nb != 0)
    {
      nb = nb / 10;
      i = i + 1;
    }
  return (i);
}

int	dec_to_base(long int nb, int size, int base)
{
  char	*res_end;
  int	tmp;
  int	i;

  res_end = malloc(sizeof(char) * (my_intlen(nb) + 1) * 4);
  if (res_end == NULL)
    return (84);
  i = 0;
  while (nb != 0)
    {
      tmp = nb % base;
      if (tmp < 10)
	tmp = tmp + '0';
      else
	tmp = tmp + size;
      res_end[i] = tmp;
      nb = nb / base;
      i = i + 1;
    }
  my_putstr(my_revstr(res_end), 1);
  free(res_end);
  return (0);
}

void	my_special_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 32 && str[i] < 127)
	my_putchar(str[i]);
      else
	special_oct(str[i]);
      i = i + 1;
    }
}

void	special_oct(char a)
{
  char	res_oct[] = "007";
  int	i;

  i = 2;
  while (i >= 0)
    {
      res_oct[i] = a % 8 + '0';
      a = a / 8;
      i = i - 1;
    }
  my_putchar('\\');
  my_putstr(res_oct, 1);
}
