/*
** func_printf_2.c for my_printf in /home/benoit.pingris/delivery/PSU_2016_my_printf
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Nov 16 10:29:01 2016 benoit pingris
** Last update Wed Mar  1 22:36:15 2017 benoit pingris
*/

#include "my_printf.h"

int	disp_pointer(long int nb, int size, int base)
{
  if (nb == 0)
    {
      my_putstr("(nil)", 1);
      return (0);
    }
  else
    {
      my_putstr("0x", 1);
      dec_to_base(nb, size, base);
    }
  return (0);
}
