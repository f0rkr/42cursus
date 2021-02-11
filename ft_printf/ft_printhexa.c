/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 11:49:31 by mashad            #+#    #+#             */
/*   Updated: 2019/11/15 12:11:04 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_hexpoint(int y, int num[])
{
	if (y == 0 && num[5] == 1)
	{
		if (num[1] == 0)
			ft_putnchar(' ', num[0]);
		else if (num[0] == 0)
			ft_putnchar('0', num[1]);
		return (1);
	}
	return (0);
}

void			ft_puthexa_m(int y[], int spc, int zr, int f)
{
	if (f == 1)
	{
		ft_putnchar('0', zr);
		ft_puthexa_fd(y[0], y[1], 1);
		ft_putnchar(' ', spc);
	}
	else
	{
		ft_putnchar(' ', spc);
		ft_putnchar('0', zr);
		ft_puthexa_fd(y[0], y[1], 1);
	}
}

static void		ft_gg(int y[], int n, int flag)
{
	if (n <= y[2])
		return (ft_puthexa_m(y, 0, 0, 0));
	if (flag == 2)
		ft_puthexa_m(y, 0, n - y[2], flag);
	else
		ft_puthexa_m(y, n - y[2], 0, flag);
}

void			ft_printhexa(int flag, int n[], va_list lst)
{
	int			y[3];

	y[1] = n[4];
	y[0] = va_arg(lst, int);
	y[2] = ft_hexalen(y[0]);
	if (ft_hexpoint(y[0], n) == 1)
		return ;
	if (n[2] != 0 && n[3] == 0)
		ft_gg(y, n[0], flag);
	else if (n[2] == 0 && n[3] == 0)
		ft_puthexa_m(y, 0, 0, 0);
	else if (n[2] == 0 && n[3] != 0)
		ft_puthexa_m(y, -1, n[1] - y[2], flag);
	else if (n[2] != 0 && n[3] != 0)
	{
		if (n[1] == 0 && flag == 2)
			flag = 0;
		if (n[1] <= y[2])
			return (n[0] <= y[2] ? ft_puthexa_m(y, 0, 0, 0)
			: ft_puthexa_m(y, n[0] - y[2] - 0, 0, flag));
		else
			return (n[0] <= y[2] ? ft_puthexa_m(y, 0, n[1] - y[2], flag)
			: ft_puthexa_m(y, n[0] - n[1], n[1] - y[2], flag));
	}
}
