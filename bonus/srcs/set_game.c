/*
** set_game.c for tetris in /home/benoit.pingris/delivery/save_tetris/3
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Mar  3 13:38:35 2017 benoit pingris
** Last update Mon Mar  6 14:31:20 2017 benoit pingris
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

int		stock_pieces(char **tab, t_tabs *t)
{
  static int	i = 0;
  int		j;

  j = 0;
  if (i == 0)
    {
      if ((t->pieces = malloc(sizeof(char *) * (count_files() + 2))) == NULL)
	return (ERROR);
    }
  if ((t->pieces[i] = malloc(sizeof(char *) * (my_tablen(tab) + 2))) == NULL)
    return (ERROR);
  while (tab[j])
    {
      t->pieces[i][j] = tab[j];
      ++j;
    }
  t->pieces[i][j] = NULL;
  ++i;
  t->pieces[i] = NULL;
  return (SUCCESS);
}

int		fill_all_pieces(char *name, t_tabs *pieces)
{
  char		**tab;
  char		*path;
  int		fd;
  int		i;

  path = '\0';
  if ((tab = malloc(sizeof(char *) * 10)) == NULL)
    return (ERROR);
  if ((path = set_path(path, name)) == NULL)
    return (ERROR);
  if ((fd = open(path, O_RDONLY)) == -1)
    return (ERROR);
  free(path);
  i = 0;
  while ((tab[i] = get_next_line(fd)) != NULL)
    ++i;
  if (stock_pieces(tab, pieces) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

char		*fill_pieces(t_tabs *tab, char **name)
{
  int		i;

  i = 0;
  if ((name = malloc(sizeof(char *) * (count_files() + 1))) == NULL)
    return (NULL);
  fill_name(name);
  while (name[i])
    if (fill_all_pieces(name[i++], tab) == ERROR)
      return (NULL);
  return (name[0]);
}
