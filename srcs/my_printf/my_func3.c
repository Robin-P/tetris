/*
** my_func3.c for my_printf in /home/benoit.pingris/delivery/PSU_2016_my_printf
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Nov 18 09:49:03 2016 benoit pingris
** Last update Wed Mar  1 22:33:57 2017 benoit pingris
*/

#include "my_printf.h"

int	my_type_p(va_list ap)
{
  disp_pointer(va_arg(ap, long int), 87, 16);
  return (0);
}

int	my_type_u(va_list ap)
{
  my_put_uns_nbr(va_arg(ap, unsigned int));
  return (0);
}

int	my_type_per(va_list ap)
{
  my_putchar('%');
  return (0);
}

int	my_type_at_sign(va_list ap)
{
  my_putstr("%@", 1);
  return (0);
}
