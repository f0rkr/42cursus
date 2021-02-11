/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrrev_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:50:54 by mashad            #+#    #+#             */
/*   Updated: 2019/11/15 12:04:03 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstrrev_fd(char *str, int fd)
{
	int i;

	i = ft_strlen(str) - 1;
	while (i != -1)
	{
		ft_putchar_fdret(str[i], fd);
		i--;
	}
}
