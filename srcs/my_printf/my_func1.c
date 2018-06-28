/*
** my_func1.c for my_printf in /home/benoit.pingris/delivery/PSU_2016_my_printf
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Nov 17 20:25:16 2016 benoit pingris
** Last update Wed Mar  1 22:33:28 2017 benoit pingris
*/

#include "my_printf.h"

int	my_type_c(va_list ap)
{
  my_putchar(va_arg(ap, int));
  return (0);
}

int	my_type_s(va_list ap)
{
  my_putstr(va_arg(ap, char *), 1);
  return (0);
}

int	my_type_S(va_list ap)
{
  my_special_putstr(va_arg(ap, char *));
  return (0);
}

int	my_type_di(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
  return (0);
}

