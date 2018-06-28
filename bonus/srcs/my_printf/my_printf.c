/*
** my_printf.c for my_printf in /home/benoit.pingris/delivery/PSU_2021_my_printf
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Nov  7 21:03:20 2016 benoit pingris
** Last update Wed Mar  1 22:30:11 2017 benoit pingris
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

int	(*fct_type[13])(va_list ap) =
{
  my_type_c,
  my_type_s,
  my_type_S,
  my_type_di,
  my_type_di,
  my_type_x,
  my_type_X,
  my_type_o,
  my_type_b,
  my_type_p,
  my_type_u,
  my_type_per,
  my_type_at_sign,
};

int	(*fct_flag[3])(va_list ap, char *str, int i) =
{
  my_flag_hash,
  my_flag_plus,
  my_flag_space,
};

int	check_flags_1(char *str, va_list ap, int i)
{
  char	*list_flags;
  int	index;

  index = 0;
  list_flags = "#+ \0";
  while (list_flags[index] != str[i + 1] && index < 4)
    ++index;
  if (index < 3)
    {
      ++i;
      i = fct_flag[index](ap, str, i);
    }
  return (i);
}

int	check_type_v2(char *str, va_list ap, int i)
{
  int	index;
  char	*list_types;

  index = 0;
  list_types = "csSdixXobpu%@\0";

  while (list_types[index] != str[i + 1])
    ++index;
  if (index < 13)
    {
      fct_type[index](ap);
      ++i;
    }
  return (i);
}

int	my_printf(char *format, ...)
{
  va_list	ap;
  int		i;

  i = 0;
  va_start(ap, format);
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  i = check_flags_1(format, ap, i);
	  i = check_type_v2(format, ap, i);
	}
      else
	my_putchar(format[i]);
      i = i + 1;
    }
  va_end(ap);
  return (0);
}
