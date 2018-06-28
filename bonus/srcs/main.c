/*
** main.c for  in /home/robin/delivery/PSU_2016_tetris
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Mar 10 14:43:31 2017 Robin Pronnier
** Last update Wed Mar 15 12:47:04 2017 benoit pingris
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include "my.h"
#include "struct.h"

int		disp_error()
{
  my_putstr("Usage : \t./tetris [option] ...\n", 2);
}

int		disp_help(char **av)
{
  char			*s;
  int			fd;

  if ((fd = open("srcs/help\0", O_RDONLY)) == -1)
    return (ERROR);
  my_printf("Usage:\t%s\n", av[0]);
  while ((s = get_next_line(fd)))
    {
      my_printf("%s\n", s);
      free(s);
    }
  close(fd);
  return (0);
}

void	print_end()
{
  int	choice;

  curs_set(0);
  clear();
  noecho();
  keypad(stdscr, TRUE);
  start_color();
  init_colors();
  choice = bot_pos(4, 1);
  refresh();
  if (choice == 1)
    curtain();
  else if (choice == 2)
    random_point();
  else if (choice == 3)
    spiral();
  else
    scanning();
  sleep(1);
  endwin();
}

int		main(int ac, char **av, char **envp)
{
  t_binding	tetris;
  t_tabs	my_tabs;
  t_time	my_time;
  char		**name;

  if (set_info(&tetris, &my_time, &my_tabs, envp) == ERROR)
    return (ERROR);
  if (check_flags(ac, av, &tetris) == ERROR)
    return (ERROR);
  if (tetris.help == TRUE)
    return (disp_help(av));
  if (tetris.debug == TRUE)
    if ((debug(tetris, name, 0, &my_tabs)) == NULL)
      return (ERROR);
  if (tetris.debug == FALSE)
    if ((debug(tetris, name, 1, &my_tabs)) == NULL)
      return (ERROR);
  if (set_game(tetris, my_time, my_tabs) == ERROR)
    return (ERROR);
  print_end();
  return (SUCCESS);
}
