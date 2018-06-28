/*
** quit.c for tetris in /home/benoit.pingris/delivery/PSU_2016_tetris/bonus
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Mar 10 15:39:09 2017 benoit pingris
** Last update Tue Mar 14 16:05:39 2017 benoit pingris
*/

#include <SFML/Audio.h>
#include "struct.h"

void	kill_music(t_coord *c)
{
  sfMusic_destroy(c->benoit);
  sfMusic_destroy(c->duel);
  sfMusic_destroy(c->plouf);
}
