/*
** debug_2.c for tetris in /home/benoit.pingris/delivery/save_tetris/3
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Mar  2 21:50:58 2017 benoit pingris
** Last update Mon Mar 13 12:34:46 2017 benoit pingris
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

char	*set_path(char *s1, char *s2)
{
  if ((s1 = my_strdup("tetriminos/\0")) == NULL)
    return (NULL);
  if ((s1 = my_mallocat(s1, s2)) == NULL)
    return (NULL);
  return (s1);
}

static void	*disp_name(char *str)
{
  while (1)
    {
      if ((my_strcmp(str, ".tetrimino") == 0) && (my_strlen(str) == 10))
	{
	  my_printf(" : ");
	  return (NULL);
	}
      my_printf("%c", str[0]);
      ++str;
    }
}

int	check_tetriminos(char *str, int choice, t_binding k, t_tabs *t)
{
  char	**tab;
  char	*path;
  int	fd;
  int	i;

  if ((tab = malloc(sizeof(char *) * 100)) == NULL)
    return (ERROR);
  if ((path = set_path(path, str)) == NULL)
    return (ERROR);
  if ((fd = open(path, O_RDONLY)) == -1)
    return (ERROR);
  free(path);
  i = 0;
  while ((tab[i] = get_next_line(fd)) != NULL)
    ++i;
  if (choice == 0)
    disp_name(str);
  if (check_error(tab, choice, k, t) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
