/*
** my.h for  in /home/robin/delivery/PSU_2016_tetris
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Mar 10 14:43:06 2017 Robin Pronnier
** Last update Wed Mar 15 14:22:19 2017 benoit pingris
*/

#ifndef MY_H_
# define MY_H_

#include "struct.h"
# define ERROR	84
# define SUCCESS 0
# define SPECIAL_ERR "42_3RR0R_iOctL_F41L3D_|+"
# define SPACE " "

int	any_key(int);
void	music_conf(sfMusic *, char *, t_binding *);

void	my_putchar(const char);
void	my_putstr(const char *, const int);
void	my_showtab(char **);
void	my_showtab1(char **);
void	my_showtabtab(char ***);

void	free_tab(char **);
void	free_tab_tab(char ***);

char	*my_strcpy(char *, char *);
char	*my_strdup(char *);
char	*my_strcat(char *, char *);
char	*my_mallocat(const char *, const char *);
char	*get_next_line(int);

int	my_strcmp(const char *, const char *);
int	my_strstr(const char *, const char *);

int	my_tablen(char **);
int	my_strlen(const char *);
int	my_getnbr(const char *);
int	my_printf(char *, ...);

int	get_row(const char *, const char);
int	get_col(const char *, const char);
int	count_lines(char **);
int	count_files();
int	max_len(char **);
int	max_height(char ***);
int	max_width(char ***);
int	bot_pos(int, int);

/*
**	functions game
*/

int	check_stop(char **);
int	lose(char **);
int	set_game(t_binding, t_time, t_tabs);
int	check_flags(int , char **, t_binding *);
int	check_tetriminos(char *, int, t_binding, t_tabs *);
int	check_error(char **, int, t_binding, t_tabs *);
int	game(t_binding, t_time, t_tabs, t_coord);
int	line_break(char **, t_binding, int, sfMusic *);
int	check_turn(t_coord, char **, t_binding);
int	check_lat(char **, int);
int	controls(t_binding, char **, char **, char *);
int	get_x_y(char **, char);
int	stock_pieces(char **, t_tabs *);
int	set_highscore(t_binding *);
int	non_blocking_read();

char	*set_path(char *, char *);
char	*press_key(int, int, int, int);
char	**change(char **);
char	**fill_name(char **);
char	*fill_pieces(t_tabs *, char **);
char	**sort_name(char **);
char	**debug(t_binding, char **, int, t_tabs *);
char	**piece(char **, char **);
char	**get_next_form(char **);
char	**copy(char **, char **, t_binding);
char	**change_map(char **);
char	**falling_2(t_tabs, t_coord, t_time, t_binding);
int	count_pieces(char ***);

void	showtab_ncurses(char **, t_binding , t_time , WINDOW *);
void	disp_next(t_binding, int, char ***, WINDOW *);
int	disp_help(char **);
void	init_colors();

void	spiral();
void	curtain();
void	random_point();
void	scanning();
void	set_tabs(t_tabs *);
void	set_info_2(t_binding *, t_time *, t_tabs *);
int	set_info(t_binding *, t_time *, t_tabs *, char **);

/*
**	functions pointers
*/

int	set_right(t_binding *, char *);
int	set_left(t_binding *, char *);
int	set_quit(t_binding *, char *);
int	set_turn(t_binding *, char *);
int	set_drop(t_binding *, char *);
int	set_debug(t_binding *, char *);
int	set_pause(t_binding *, char *);
int	set_help(t_binding *, char *);
int	set_size(t_binding *, char *);
int	set_lvl(t_binding *, char *);
int	set_next(t_binding *, char *);

void	kill_music(t_coord * );
void	print_tetris(t_coord);

#endif /* !MY_H_ */
