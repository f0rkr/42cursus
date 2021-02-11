/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:42:14 by mashad            #+#    #+#             */
/*   Updated: 2019/11/16 08:47:35 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_ppoint(uintptr_t y, int num[])
{
	if (y == 0 && num[5] == 1)
	{
		if (num[1] == 0)
		{
			ft_putnchar(' ', num[0] - 2);
			ft_putnstr("0x", 2);
		}
		else if (num[0] == 0)
		{
			ft_putnstr("0x", 2);
			ft_putnchar('0', num[1]);
		}
		return (1);
	}
	return (0);
}

void			ft_putpoint_m(uintptr_t a, int spc, int zr, int f)
{
	if (f == 1)
	{
		ft_putnchar('0', zr);
		ft_putnstr("0x", 2);
		ft_putptr_fd(a, 0, 1);
		ft_putnchar(' ', spc - 2);
	}
	else
	{
		ft_putnchar(' ', spc - 2);
		ft_putnchar('0', zr);
		ft_putnstr("0x", 2);
		ft_putptr_fd(a, 0, 1);
	}
}

static void		ft_pgg(uintptr_t a, int n, int flag)
{
	int x;

	x = ft_hexalen(a);
	if (n <= x)
		return (ft_putpoint_m(a, 0, 0, 0));
	if (flag == 2)
		ft_putpoint_m(a, 0, n - x + 0, flag);
	else
		ft_putpoint_m(a, n - x, 0, flag);
}

void			ft_printp(int flag, int n[], va_list lst)
{
	uintptr_t	a;
	int			y;

	a = va_arg(lst, uintptr_t);
	y = ft_hexalen(a);
	if (ft_ppoint(a, n) == 1)
		return ;
	if (n[2] != 0 && n[3] == 0)
		ft_pgg(a, n[0], flag);
	else if (n[2] == 0 && n[3] == 0)
		ft_putpoint_m(a, 0, 0, 0);
	else if (n[2] == 0 && n[3] != 0)
		ft_putpoint_m(a, 0, n[1] - y, flag);
	else if (n[2] != 0 && n[3] != 0)
	{
		if (n[1] == 0 && flag == 2)
			flag = 0;
		if (n[1] <= y)
			return (n[0] <= y ? ft_putpoint_m(a, 0, 0, 0)
			: ft_putpoint_m(a, n[0] - y, 0, flag));
		else
			return (n[0] <= y ? ft_putpoint_m(a, 0, n[1] - y, flag)
			: ft_putpoint_m(a, n[0] - n[1], n[1] - y, flag));
	}
}
