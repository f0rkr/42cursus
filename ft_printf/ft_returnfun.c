/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_returnfun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:25:03 by mashad            #+#    #+#             */
/*   Updated: 2019/11/15 12:21:29 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_retfun(char c)
{
	if (c == 'd' || c == 'i')
		return (&ft_printint);
	else if (c == 's')
		return (&ft_printstr);
	else if (c == 'x' || c == 'X')
		return (&ft_printhexa);
	else if (c == 'p')
		return (&ft_printp);
	else if (c == 'c')
		return (&ft_printchar);
	else if (c == '%')
		return (&ft_printpurcent);
	else if (c == 'u')
		return (&ft_printuns);
	return (0);
}
