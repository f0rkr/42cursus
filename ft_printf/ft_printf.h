/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:37:43 by mashad            #+#    #+#             */
/*   Updated: 2019/11/16 15:45:05 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef unsigned int	t_size_u;
void					*ft_retfun(char c);
size_t					ft_strlen(const char *s);
int						ft_isdigit(int c);
int						ft_numlen(int n);
void					ft_putuns_fd(t_size_u nb, int fd);
void					ft_putchar_fdret(char c, int fd);
void					ft_putuns_m(t_size_u y, int spc, int zr, int f);
void					ft_printuns(int flag, int num[], va_list lst);
void					ft_printstr(int flag, int n[], va_list lst);
void					ft_putnbr_fdret(int n, int fd);
void					ft_printpurcent(int flag, int num[], va_list lst);
void					ft_putnstr(char *s, int n);
void					ft_putnchar(char c, int i);
void					ft_putstrrev_fd(char *str, int fd);
int						ft_hexalen(uintptr_t n);
void					ft_printp(int flag, int n[], va_list lst);
void					ft_printchar(int flag, int num[], va_list lst);
void					ft_printhexa(int flag, int num[], va_list lst);
void					ft_putptr_fd(uintptr_t n, int m, int fd);
void					ft_puthexa_fd(unsigned int n, int m, int fd);
void					ft_putnbr_m(int y, int spc, int zr, int f);
void					ft_printint(int flag, int n[], va_list lst);
void					ft_point_exist(char *str, int num[],
		va_list lst, char c);
void					gather_data(char *str, va_list lst,
		char c, void(*f)(int, int[], va_list));
int						ft_printf(const char *str, ...);
#endif
