/*
** my_basics_funcs_2.c for my_printf in /home/benoit.pingris/delivery/PSU_2016_my_printf
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Nov 18 16:57:29 2016 benoit pingris
** Last update Wed Mar  1 22:30:44 2017 benoit pingris
*/

#include "my_printf.h"

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0 && nb <= 9)
    my_putchar(nb + '0');
  if (nb > 9)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
}

void	my_put_uns_nbr(unsigned int nb)
{
  if (nb < 0)
    nb =  4294967295 + nb;
  if (nb >= 0 && nb <= 9)
    my_putchar(nb + '0');
  if (nb > 9)
    {
      my_put_uns_nbr(nb / 10);
      my_put_uns_nbr(nb % 10);
    }
}
