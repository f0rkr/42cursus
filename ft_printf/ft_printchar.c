/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:15:07 by mashad            #+#    #+#             */
/*   Updated: 2019/11/15 12:01:55 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(int flag, int num[], va_list lst)
{
	char c;

	c = va_arg(lst, int);
	if (flag == 1)
	{
		ft_putchar_fdret(c, 1);
		return (ft_putnchar(' ', num[0] - 1));
	}
	ft_putnchar(' ', num[0] - 1);
	return (ft_putchar_fdret(c, 1));
}
