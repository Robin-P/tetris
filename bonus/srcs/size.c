/*
** size.c for tetris in /home/benoit.pingris/delivery/save_tetris/3
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Mar  3 17:10:45 2017 benoit pingris
** Last update Mon Mar 13 12:38:26 2017 benoit pingris
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"
#include "struct.h"

int	get_row(const char *s, const char separator)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (s[i] != separator && s[i] != '\0')
    nb = nb * 10 + s[i++] - '0';
  if (s[i] == '\0')
    nb = 0;
  return (nb);
}

int	get_col(const char *s, const char separator)
{
  int	i;
  int	nb;

  i = 0;
  while (s[i] != separator && s[i] != '\0')
    ++i;
  if (s[i] == '\0')
    return (0);
  nb = 0;
  while (s[++i] != '\0')
    nb = nb * 10 + s[i] - '0';
  return (nb);
}

static char		*my_itoa(int nb)
{
  int	        i;
  char		*s;
  int		tmp;

  tmp = nb;
  i = 1;
  while ((tmp /= 10) > 0)
    ++i;
  if ((s = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  s[i] = '\0';
  while (i--)
    {
      s[i] = nb % 10 + '0';
      nb /= 10;
    }
  return (s);
}

int	set_highscore(t_binding *k)
{
  int	fd;
  char	*s;

  if ((s = my_itoa(k->score)) == NULL)
    return (ERROR);
  if ((fd = open("srcs/highscore", O_RDWR, 0777)) == -1)
    return (ERROR);
  if (k->score > k->highscore)
    {
      k->highscore = k->score;
      write(fd, s, my_strlen(s));
    }
  return (SUCCESS);
}

int	count_pieces(char ***pieces)
{
  int	i;

  i = 0;
  while (pieces[i])
    {
      i = i + 1;
    }
  return (i - 1);
}
