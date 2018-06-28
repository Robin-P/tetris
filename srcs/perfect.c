/*
** perfect.c for tetris in /home/benoit.pingris/delivery/PSU_2016_tetris/newTETRISBGJuL
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Mar  6 14:03:39 2017 benoit pingris
** Last update Mon Mar  6 14:03:42 2017 benoit pingris
*/

int		change2(char **av)
{
  int		i;
  int		x;

  i = 0;
  x = 0;
  while (av[i])
    {
      if (av[i][0] == ' ')
	x = x + 1;
      i = i + 1;
    }
  if (x == i)
    return (1);
  return (0);
}

char		**change(char **av)
{
  int		i;
  int		x;

  while (change2(av) != 0)
    {
      i = 0;
      while (av[i])
	{
	  x = 0;
	  while (av[i][x + 1] != '\0')
	    {
	      av[i][x] = av[i][x + 1];
	      x = x + 1;
	    }
	  av[i][x] = '\0';
	  i = i + 1;
	}
    }
  return (av);
}
