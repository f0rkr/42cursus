/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:26:53 by mashad            #+#    #+#             */
/*   Updated: 2019/11/15 15:29:44 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intpoint(int y, int num[])
{
	if (y == 0 && num[5] == 1)
	{
		if (num[1] == 0)
		{
			ft_putnchar(' ', num[0]);
			return (1);
		}
		else if (num[0] == 0)
		{
			ft_putnchar('0', num[1]);
			return (1);
		}
	}
	return (0);
}

void	ft_gg(int y, int n[], int flag, int k)
{
	int x;

	x = ft_numlen(y);
	if (n[0] <= x)
		return (ft_putnbr_m(y, 0, 0, 0));
	if (flag == 2 && n[4] == 0)
		ft_putnbr_m(y, 0, n[0] - x + k, flag);
	else
		ft_putnbr_m(y, n[0] - x - k, k, flag);
}

void	ft_bothexist(int y, int num[], int flag, int k)
{
	int x;

	x = ft_numlen(y);
	if (num[1] == 0 && flag == 2)
		flag = 0;
	if (num[1] <= x)
		return (num[0] <= x ? ft_putnbr_m(y, 0, k, 0)
				: ft_putnbr_m(y, num[0] - x - k, k, flag));
	else
		return (num[0] <= x ? ft_putnbr_m(y, 0, num[1] - x + k, flag)
				: ft_putnbr_m(y, num[0] - num[1] - k, num[1] - x + k, flag));
}

void	ft_printint(int flag, int num[], va_list lst)
{
	int x;
	int y;
	int k;

	k = 0;
	y = va_arg(lst, int);
	x = ft_numlen(y);
	if (ft_intpoint(y, num) == 1)
		return ;
	if (y < 0 && num[1] >= x)
		k = 1;
	if (num[2] != 0 && num[3] == 0)
		ft_gg(y, num, flag, k);
	else if (num[2] == 0 && num[3] == 0)
		ft_putnbr_m(y, 0, k, 0);
	else if (num[2] == 0 && num[3] != 0)
		ft_putnbr_m(y, -1, num[1] - x + k, flag);
	else if (num[2] != 0 && num[3] != 0)
		ft_bothexist(y, num, flag, k);
}
