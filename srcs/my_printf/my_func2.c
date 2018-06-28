/*
** my_func2.c for my_printf in /home/benoit.pingris/delivery/PSU_2016_my_printf
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Nov 18 09:43:45 2016 benoit pingris
** Last update Wed Mar  1 22:30:24 2017 benoit pingris
*/

#include "my_printf.h"

int	my_type_x(va_list ap)
{
  dec_to_base(va_arg(ap, int), 87, 16);
  return (0);
}

int	my_type_X(va_list ap)
{
  dec_to_base(va_arg(ap, int), 55, 16);
  return (0);
}

int	my_type_o(va_list ap)
{
  dec_to_base(va_arg(ap, int), 87, 8);
  return (0);
}

int	my_type_b(va_list ap)
{
  dec_to_base(va_arg(ap, int), 87, 2);
  return (0);
}
