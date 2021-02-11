/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:45:22 by mashad            #+#    #+#             */
/*   Updated: 2019/11/16 15:44:34 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuns_fd(t_size_u nb, int fd)
{
	if (nb > 9)
	{
		ft_putnbr_fdret((nb / 10), fd);
		ft_putchar_fdret((nb % 10) + '0', fd);
	}
	else
		ft_putchar_fdret((nb + '0'), fd);
}
