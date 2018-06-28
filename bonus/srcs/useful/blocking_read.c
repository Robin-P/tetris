/*
** blocking_read.c for tetris in /home/benoit.pingris/delivery/tetris_save/PSU_2016_tetris
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Mar  7 15:53:17 2017 benoit pingris
** Last update Sat Mar 18 12:52:09 2017 Robin Pronnier
*/

#include <term.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stropts.h>
#include "my.h"

int			non_blocking_read()
{
  struct termios	old_t;
  struct termios	new_t;
  char			c;

  my_putstr("Press any key to start Tetris\n", 1);
  if ((ioctl(1, TCGETS, &old_t)) == -1)
    return (84);
  new_t = old_t;
  new_t.c_lflag &= ~ECHO;
  new_t.c_lflag &= ~ICANON;
  if (((ioctl(1, TCSETS, &new_t)) == -1)
      || ((read(1, &c, 1)) == -1)
      || ((ioctl(1, TCSETS, &old_t)) == -1))
    return (84);
  return (0);
}

struct termios	termios_struct_set(struct termios *old_t, struct termios *new)
{
  new = old_t;
  new->c_lflag &= ~ECHO;
  new->c_lflag &= ~ICANON;
  return (*new);
}

int		my_strstr(const char *s1, const char *s2)
{
  int			a;
  int			b;

  a = 0;
  while (s1[a])
    {
      b = 0;
      if (s1[a] == s2[b])
	{
	  while (s1[a] == s2[b] && s2[b] && s1[a])
	    {
	      ++a;
	      ++b;
	    }
	  if (s2[b] == '\0')
	    return (0);
	}
      ++a;
    }
  return (1);
}

char	*clear_str(char *str, int *i)
{
  int	a;

  a = 0;
  while (a <= 200)
    {
      str[a] = '\0';
      a++;
    }
  *i = 0;
  return (str);
}

char			*press_key(int reset, int on, int off, int j)
{
  struct termios	old_t;
  struct termios	new_t;
  static char		c[200];
  static int		i = 0;

  if (i == 200 || reset == 1)
    return (clear_str(c, &i));
  if ((ioctl(0, TCGETS, &old_t)) == -1)
    return (SPECIAL_ERR);
  new_t = termios_struct_set(&old_t, &new_t);
  if (((ioctl(0, TCSETS, &new_t)) == -1) || ((ioctl(0, FIONBIO, &on)) == -1) ||
      ((j = read(0, &c[i], 1)) == -1) || ((ioctl(0, FIONBIO, &off)) == -1))
    {
      if (j == -1)
	{
	  if (ioctl(0, TCSETS, &old_t) == -1)
	    return (SPECIAL_ERR);
	  return (NULL);
	}
      return (SPECIAL_ERR);
    }
  if ((ioctl(0, TCSETS, &old_t)) == -1)
    return (SPECIAL_ERR);
  c[i = i + j] = '\0';
  return (c);
}
