/*
** game.c for  in /home/robin/delivery/PSU_2016_tetris
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Mar 10 14:44:32 2017 Robin Pronnier
** Last update Wed Mar 15 12:19:09 2017 benoit pingris
*/

#include <SFML/Audio.h>
#include <unistd.h>
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include "struct.h"
#include "my.h"

int		bot_pos(int max, int min)
{
  static int		i;

  if (i == 0)
    {
      srand(time(NULL));
      i = 1;
    }
  return (rand() % max + min);
}

static char	*last_line(int col)
{
  char		*str;
  int		i;

  i = 1;
  if ((str = malloc(sizeof(char) * (col + 3))) == NULL)
    return (NULL);
  str[0] = '+';
  while (i <= col)
    str[i++] = '-';
  str[i++] = '+';
  str[i] = '\0';
  return (str);
}

static char	**draw_map(t_binding tetris)
{
  char		**map;
  int		i;
  int		j;

  i = 1;
  j = 0;
  if ((map = malloc(sizeof(char *) * (tetris.map_row + 3))) == NULL)
    return (NULL);
  while (i <= tetris.map_row)
    {
      j = 1;
      if ((map[i] = malloc(sizeof(char) * (tetris.map_col + 3))) == NULL)
	return (NULL);
      map[i][0] = '|';
      while (j <= tetris.map_col)
	map[i][j++] = ' ';
      map[i][j] = '|';
      map[i++][j + 1] = '\0';
    }
  map[0] = last_line(tetris.map_col);
  map[i] = last_line(tetris.map_col);
  map[i + 1] = NULL;
  return (map);
}

int		game(t_binding keys, t_time t, t_tabs ta, t_coord c)
{
  c.i = bot_pos(count_pieces(ta.pieces) + 1, 0);
  t.start_t = clock();
  showtab_ncurses(ta.map, keys, t, c.my_win);
  while (lose(ta.map) == 0)
    {
      clear();
      refresh();
      c.tmp = c.i;
      if (set_highscore(&keys) == ERROR)
	return (ERROR);
      c.i = bot_pos(count_pieces(ta.pieces) + 1, 0);
      c.p = piece(c.p, ta.pieces[c.tmp]);
      c.n = ta.pieces[c.tmp][0][my_strlen(ta.pieces[c.tmp][0]) - 1] - '0';
      if (keys.no_next == FALSE)
	disp_next(keys, c.i, ta.pieces, c.my_next);
      c.x = 0;
      if ((ta.map = falling_2(ta, c, t, keys)) == NULL)
	return (SUCCESS);
      ta.new = change_map(ta.map);
      keys.score += line_break(ta.new, keys, 0, c.plouf);
      free_tab(c.p);
    }
  endwin();
  kill_music(&c);
  return (SUCCESS);
}

int		set_game(t_binding keys, t_time t, t_tabs my_tab)
{
  t_coord		c;
  int			height;
  int			width;

  c.benoit = sfMusic_createFromFile("tourne.wav");
  c.duel = sfMusic_createFromFile("duel.wav");
  c.plouf = sfMusic_createFromFile("cortex.wav");
  c.ctrl = 0;
  initscr();
  curs_set(0);
  clear();
  noecho();
  start_color();
  init_colors();
  print_tetris(c);
  my_tab.map = draw_map(keys);
  my_tab.new = draw_map(keys);
  sfMusic_play(c.benoit);
  init_colors();
  start_color();
  height = max_height(my_tab.pieces) + 4;
  width = max_width(my_tab.pieces) + 4;
  c.my_win = newwin(10, 25, LINES / 2, COLS / 2 - keys.map_col - 21);
  c.my_next = newwin(height, width, LINES/2, COLS * 0.7);
  return (game(keys, t, my_tab, c));
}
