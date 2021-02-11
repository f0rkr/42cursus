/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_porc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:26:47 by mashad            #+#    #+#             */
/*   Updated: 2019/11/15 15:44:40 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putpourcent_m(int y, int spc, int zr, int f)
{
	if (f == 1)
	{
		ft_putnchar('0', zr);
		ft_putchar_fdret(y, 1);
		ft_putnchar(' ', spc);
	}
	else
	{
		ft_putnchar(' ', spc);
		ft_putnchar('0', zr);
		ft_putchar_fdret(y, 1);
	}
}

void		ft_ggpourcent(int y, int num[], int flag, int k)
{
	if (num[0] <= 1)
		return (ft_putpourcent_m(y, 0, 0, 0));
	if (flag == 2 && num[4] == 0)
		ft_putpourcent_m(y, 0, num[0] - 1 + k, flag);
	else
		ft_putpourcent_m(y, num[0] - 1 - k, k, flag);
}

void		ft_printpurcent(int flag, int num[], va_list lst)
{
	lst = 0;
	if (num[3] == 1)
		flag = 1;
	ft_ggpourcent('%', num, flag, 0);
}
