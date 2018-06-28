/*
** need.c for tetris in /home/benoit.pingris/delivery/PSU_2016_tetris
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Mar 14 12:00:08 2017 benoit pingris
** Last update Wed Mar 15 14:22:08 2017 benoit pingris
*/

#include <SFML/Audio.h>
#include <ncurses.h>
#include "my.h"
#include "spe.h"

int	any_key(int ret)
{
  press_key(1, 1, 0, 0);
  return (ret);
}

void		music_conf(sfMusic *music, char *s, t_binding *keys)
{
  static int	i;
  int		c;

  if (s != NULL)
    {
      if (my_strstr(s, keys->k_music) == 0)
	{
	  if (i == 0)
	    {
	      sfMusic_stop(music);
	      ++i;
	    }
	  else
	    {
	      sfMusic_play(music);
	      --i;
	    }
	  press_key(1, 1, 0, 0);
	}
    }
}
