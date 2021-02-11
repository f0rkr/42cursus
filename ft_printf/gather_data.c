/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:20:59 by mashad            #+#    #+#             */
/*   Updated: 2019/11/16 15:50:41 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_beforpoint(char *str, int *flag, int num[], va_list lst)
{
	if (*str == '*')
	{
		num[0] = va_arg(lst, int);
		num[2] = 1;
		if (num[0] < 0)
		{
			*flag = 1;
			num[0] = -num[0];
		}
	}
	else if (*str > '0' && *str <= '9')
	{
		num[0] = atoi(str);
		num[2] = 1;
	}
}

static int		ft_signum(int num[])
{
	num[0] = 0;
	num[1] = 0;
	num[2] = 0;
	num[3] = 0;
	num[4] = 0;
	num[5] = 0;
	return (0);
}

void			gather_data(char *str, va_list lst, char c,
		void (*f)(int, int[], va_list))
{
	int			num[6];
	int			flag;

	flag = ft_signum(num);
	while (*str == '-')
	{
		if (*(str + 1) == '0' && c == '%')
			num[3] = 1;
		flag = 1;
		str++;
	}
	if (*str == '0')
	{
		flag = 2;
		while (*str == '0')
			str++;
	}
	ft_beforpoint(str, &flag, num, lst);
	ft_point_exist(str, num, lst, c);
	(*f)(flag, num, lst);
}
