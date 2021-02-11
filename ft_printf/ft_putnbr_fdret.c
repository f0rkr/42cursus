/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fdret.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:29:02 by mashad            #+#    #+#             */
/*   Updated: 2019/11/16 15:33:06 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fdret(int n, int fd)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fdret('-', fd);
		nb = -n;
	}
	if (nb > 9)
	{
		ft_putnbr_fdret((nb / 10), fd);
		ft_putchar_fdret((nb % 10) + '0', fd);
	}
	else
		ft_putchar_fdret((nb + '0'), fd);
}
