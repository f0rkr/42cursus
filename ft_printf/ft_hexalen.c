/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:52:34 by mashad            #+#    #+#             */
/*   Updated: 2019/11/14 18:48:36 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexalen(uintptr_t n)
{
	int		temp;
	char	c;
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			c = temp + 48;
		else
			c = temp + 55;
		i++;
		n = n / 16;
	}
	return (i);
}
