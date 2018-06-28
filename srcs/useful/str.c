/*
** str.c for tetris in /home/benoit.pingris/delivery/save_tetris/3/srcs/useful
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Mar  1 21:46:38 2017 benoit pingris
** Last update Wed Mar 15 12:46:11 2017 benoit pingris
*/

#include <unistd.h>

int	my_strlen(const char *s)
{
  int	i;

  i = 0;
  while (s[++i]);
  return (i);
}

void	my_putchar(const char a)
{
  write(1, &a, 1);
}

void	my_putstr(const char *s, const int stream)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] == 27)
	{
	  my_putstr("^E", 1);
	  ++i;
	}
      else
	write(stream, &s[i++], 1);
    }
}

void	my_showtab(char **t)
{
  int	i;

  i = 0;
  while (t[i])
    {
      my_putstr(t[i++], 1);
      my_putchar('\n');
    }
}

int	my_getnbr(const char *s)
{
  int	i;
  int	nb;
  int	sign;

  nb = 0;
  i = -1;
  sign = 1;
  while (s[++i] == '-')
    sign = -sign;
  while (s[i] >= '0' && s[i] <= '9')
    nb = nb * 10 + s[i++] - '0';
  return (nb * sign);
}
