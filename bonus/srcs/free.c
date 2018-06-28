/*
** free.c for tetris in /home/benoit.pingris/delivery/save_tetris/3
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Mar  2 22:10:57 2017 benoit pingris
** Last update Fri Mar 10 14:04:41 2017 Robin Pronnier
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

void	free_tab_tab(char ***tab)
{
  int	i;
  int	j;

  j = 0;
  while (tab[j])
    {
      free_tab(tab[j]);
      j = j + 1;
    }
  free_tab(tab[j]);
  free(tab);
}
