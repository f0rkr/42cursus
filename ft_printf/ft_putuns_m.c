/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:22:59 by mashad            #+#    #+#             */
/*   Updated: 2019/11/16 15:45:15 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putuns_m(t_size_u y, int spc, int zr, int f)
{
	if (f == 1)
	{
		ft_putnchar('0', zr);
		ft_putuns_fd(y, 1);
		ft_putnchar(' ', spc);
	}
	else
	{
		ft_putnchar(' ', spc);
		ft_putnchar('0', zr);
		ft_putuns_fd(y, 1);
	}
}
