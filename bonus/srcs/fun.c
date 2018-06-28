/*
** fun.c<newbonus> for tetris in /home/benoit.pingris/delivery/PSU_2016_tetris/newbonus
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Mar 14 13:40:03 2017 benoit pingris
** Last update Thu Mar 23 10:03:02 2017 Robin Pronnier
*/

#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

void		print_tetris2(int a, int b, int fd)
{
  char		*s;

  while ((s = get_next_line(fd)) != NULL)
    {
      attron(COLOR_PAIR(bot_pos(13, 2)));
      a = 0;
      while (s[a] != '\0')
	{
	  if (s[a] == 'O')
	    mvprintw(LINES / 2 - 4 + b, COLS / 2 - 40 + a, "%c", s[a]);
	  a++;
	}
      b++;
      free(s);
    }
}

void		print_tetris(t_coord c)
{
  clock_t	start;
  clock_t	my_time;
  int		fd;

  sfMusic_play(c.duel);
  start = clock() / 10000;
  my_time = clock() / 10000;
  attron(A_BOLD);
  while (my_time - start < 450)
    {
      fd = open("lol", O_RDONLY);
      print_tetris2(0, 0, fd);
      close(fd);
      refresh();
      my_time = clock() / 10000;
    }
  attroff(A_BOLD);
  clear();
}
