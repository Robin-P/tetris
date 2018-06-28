/*
** str2.c for tetris in /home/benoit.pingris/delivery/save_tetris/3/srcs/useful
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Mar  1 21:49:23 2017 benoit pingris
** Last update Mon Mar 13 12:59:44 2017 benoit pingris
*/

#include <stdlib.h>
#include "my.h"

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i])
    ++i;
  return (s1[i] - s2[i]);
}

char	*my_strcat(char *s1, char *s2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (s1[i])
    s1[i++] = s2[j++];
  s1[i] = '\0';
  return (s1);
}

char	*my_strcpy(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s2[i])
    {
      s1[i] = s2[i];
      ++i;
    }
  s1[i] = '\0';
  return (s1);
}

char	*my_strdup(char *s)
{
  char	*str;

  if ((str = malloc(sizeof(char) * (my_strlen(s) + 1))) == NULL)
    return (NULL);
  my_strcpy(str, s);
  return (str);
}
