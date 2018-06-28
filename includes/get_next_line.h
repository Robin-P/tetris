/*
** get_next_line.h for btsrp in /home/benoit.pingris/delivery/CPE_2016_getnextline
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Jan  5 15:31:29 2017 benoit pingris
** Last update Tue Jan 17 21:31:25 2017 benoit pingris
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

char	*get_next_line(int fd);
int	my_strlen(char *str);

typedef	struct	s_stuff
{
  char		c;
  char		*line;
  int		i;
}		t_stuff;

# ifndef READ_SIZE
#  define READ_SIZE 1
# endif /* !READ_SIZE */

#endif /* !GET_NEXT_LINE_H_ */
