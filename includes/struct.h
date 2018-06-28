/*
** struct.h for tetris in /home/benoit.pingris/delivery/save_tetris/3
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Mar  1 21:41:43 2017 benoit pingris
** Last update Tue Mar 14 15:45:41 2017 benoit pingris
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#include <ncurses.h>
#include <time.h>

typedef struct	s_binding
{
  char		*my_term;
  char		*k_turn;
  char		*k_drop;
  char		*k_left;
  char		*k_right;
  char		*k_pause;
  char		*k_quit;
  int		map_row;
  int		map_col;
  int		no_next;
  int		level;
  int		debug;
  int		help;
  int		score;
  int		highscore;
}		t_binding;

typedef struct	s_tabs
{
  char		***pieces;
  char		**map;
  char		**new;
  char		**tetrimino;
}		t_tabs;

typedef struct	s_coord
{
  WINDOW	*my_win;
  WINDOW	*my_next;
  char		**p;
  int		tmp;
  int		ctrl;
  int		a;
  int		i;
  int		x;
  int		ret;
  int		j;
  int		n;
}		t_coord;

typedef struct	s_time
{
  clock_t	start_t;
  clock_t	end_t;
  clock_t	disp_t;
  time_t	time_1;
  time_t	time_2;
}		t_time;

#endif /* !STRUCT_H_ */
