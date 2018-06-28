/*
** my.h for header in /home/benoit.pingris/delivery/PSU_2016_my_printf
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Nov  8 13:20:23 2016 benoit pingris
** Last update Wed Mar  1 22:33:11 2017 benoit pingris
*/

#ifndef MY_H_
# define MY_H_

#include <stdarg.h>

int	my_printf(char *format, ...);
int	my_type_c(va_list ap);
int	my_type_s(va_list ap);
int	my_type_S(va_list ap);
int	my_type_di(va_list ap);
int	my_type_x(va_list ap);
int	my_type_X(va_list ap);
int	my_type_o(va_list ap);
int	my_type_b(va_list ap);
int	my_type_p(va_list ap);
int	my_type_u(va_list ap);
int	my_type_per(va_list ap);
int	my_type_at_sign(va_list ap);
int	my_flag_hash(va_list ap, char *str, int i);
int	my_flag_plus(va_list ap, char *str, int i);
int	my_flag_space(va_list ap, char *str, int i);
int	check_type_v2(char *str, va_list ap, int i);
int	my_strlen(char *str);
int	my_intlen(int nb);
int	disp_pointer(long int nb, int size, int base);
int	dec_to_base(long int nb, int size, int base);
int	my_getnbr(char *str);
int	my_putstr(char *str, int);

void	my_put_uns_nbr(unsigned int nb);
void	my_putchar(char a);
void	my_put_nbr(int nb);
void	special_oct(char a);
void	my_special_putstr(char *str);

char	*my_revstr(char *str);

#endif /* !MY_H_ */
