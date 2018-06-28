/*
** debug.c for  in /home/robin/delivery/PSU_2016_tetris
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Mar 10 14:51:13 2017 Robin Pronnier
** Last update Sat Mar 18 14:02:37 2017 Robin Pronnier
*/

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include "my.h"
#include "struct.h"

static void		print_keys(t_binding tetri)
{
  my_printf("***DEBUG MODE***\n");
  my_printf("Key Left :  %s\nKey Right :  %s\n", tetri.k_left, tetri.k_right);
  my_printf("Key Turn :  %s\nKey Drop :  %s\n", tetri.k_turn, tetri.k_drop);
  my_printf("Key Quit :  %s\n", tetri.k_quit);
  if (my_strcmp(tetri.k_pause, " ") == 0)
    my_printf("KeyPause :  (space)\n");
  else
    my_printf("KeyPause :  %s\n", tetri.k_pause);
  if (tetri.no_next == FALSE)
    my_printf("Next :  Yes\n");
  else
    my_printf("Next :  No\n");
  my_printf("Level :  %d\n", tetri.level);
  my_printf("Size :  %d*%d\n", tetri.map_row, tetri.map_col);
}

static int		check_file(char *str)
{
  while (str[0] != '\0')
    {
      if (my_strcmp(str, ".tetrimino") == 0 && (my_strlen(str) == 10))
	return (0);
      str++;
    }
  return (1);
}

int		count_files()
{
  DIR		*dir;
  struct dirent	*file;
  int		nb;

  nb = 0;
  if ((dir = opendir("tetriminos\0")) == NULL)
    return (ERROR);
  while ((file = readdir(dir)) != NULL)
    {
      if (file->d_type == DT_REG && check_file(file->d_name) == 0)
	++nb;
    }
  closedir(dir);
  return (nb);
}

char		**fill_name(char **tab)
{
  struct dirent	*file;
  DIR		*dir;
  int		i;

  i = 0;
  if ((dir = opendir("tetriminos/\0")) == NULL)
    return (NULL);
  while ((file = readdir(dir)) != NULL)
    {
      if (file->d_type == DT_REG && check_file(file->d_name) == 0)
	tab[i++] = file->d_name;
    }
  tab[i] = NULL;
  sort_name(tab);
  return (tab);
}

char		**debug(t_binding tetris, char **name, int choice, t_tabs *my_t)
{
  int		i;

  i = 0;
  if (count_files() == 0 || count_files() == ERROR)
    return (NULL);
  if (choice == 0)
    {
      print_keys(tetris);
      my_printf("Tetriminos : %d\n", count_files());
    }
  if ((name = malloc(sizeof(char *) * (count_files() + 1))) == NULL)
    return (NULL);
  if (fill_name(name) == NULL)
    return (NULL);
  while (name[i])
    {
      if (choice == 0)
	my_printf("Tetriminos : Name ");
      if (check_tetriminos(name[i++], choice, tetris, my_t) == ERROR)
	return (NULL);
    }
  if (choice == 0)
    if (non_blocking_read() == ERROR)
      return (NULL);
  return (name);
}
