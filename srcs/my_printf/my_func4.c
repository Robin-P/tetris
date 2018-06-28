/*
** my_func4.c for my_printf in /home/benoit.pingris/delivery/PSU_2016_my_printf
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Nov 18 14:25:40 2016 benoit pingris
** Last update Wed Mar  1 22:34:31 2017 benoit pingris
*/

#include "my_printf.h"

int	my_flag_hash(va_list ap, char *str, int i)
{
  if (str[i + 1] == 'x')
    my_putstr("0x", 1);
  else if (str[i + 1] == 'X')
    my_putstr("0X", 1);
  else if (str[i + 1] == 'o')
    my_putchar('0');
  else if (str[i + 1] == 'b')
    my_putchar('b');
  return (i);
}

int		my_flag_plus(va_list ap, char *str, int i)
{
  va_list	aq;
  int		nb;

  va_copy(aq, ap);
  if (str[i + 1] == 'd' || str[i + 1] == 'i')
    {
      nb = va_arg(aq, int);
      if (nb >= 0)
	my_putchar('+');
    }
  else if (str[i + 1] == 'p')
    {
      if (va_arg(aq, long int) >= 0)
	my_putchar('+');
    }
  va_end(aq);
  return (i);
}

int	my_flag_space(va_list ap, char *str, int i)
{
  va_list	aq;

  va_copy(aq, ap);
  while (str[i + 1] == ' ')
    {
      i = i + 1;
    }
  if (str[i + 1] == 'd' || str[i + 1] == 'i')
    {
      if (va_arg(aq, int) >= 0)
	my_putchar(' ');
    }
  return (i);
}
