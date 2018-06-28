/*
** get_next_line.c for navy in /home/benjamin.g/delivery/PSU_2016_navy
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Jan 30 21:00:18 2017 Benjamin GAYMAY
** Last update Mon Jan 30 21:00:21 2017 Benjamin GAYMAY
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char		*end(char *str)
{
  free(str);
  return (NULL);
}

char		*my_realloc(char *str)
{
  char		*new;
  int		h;

  h = 0;
  while (str[h] != '\0')
    h++;
  if ((new = malloc(sizeof(char) * (h + READ_SIZE + 1))) == NULL)
    return (NULL);
  new[h] = '\0';
  h = 0;
  while (str[h] != '\0')
    {
      new[h] = str[h];
      h = h + 1;
    }
  new[h] = '\0';
  free(str);
  return (new);
}

char		get_next_char(const int fd)
{
  static char	buffer[READ_SIZE + 1];
  static int	len = 0;
  static int	i = 0;
  char		c;

  if (len == 0)
    {
      if ((len = read(fd, buffer, READ_SIZE)) == 0)
	return ('\0');
      i = 0;
    }
  c = buffer[i];
  i = i + 1;
  len = len - 1;
  return (c);
}

char		*get_next_line(const int fd)
{
  t_stuff	info;
  int		count;

  count = 0;
  info.i = 0;
  if ((info.line = malloc(sizeof(char *) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  info.line[0] = '\0';
  info.c = get_next_char(fd);
  while (info.c != '\n' && info.c != '\0')
    {
      info.line[info.i] = info.c;
      info.c = get_next_char(fd);
      info.i = info.i + 1;
      if (count == READ_SIZE)
	{
	  info.line[info.i] = '\0';
	  if ((info.line = my_realloc(info.line)) == NULL)
	    return (NULL);
	  count = 0;
	}
      count = count + 1;
    }
  info.line[info.i] = '\0';
  return (info.c == '\0' && info.line[0] == '\0' ? end(info.line) : info.line);
}
