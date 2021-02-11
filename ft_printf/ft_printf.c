/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:14:04 by mashad            #+#    #+#             */
/*   Updated: 2019/11/15 12:02:16 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	g_ret;

int			ft_isconvertable(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd')
		return (1);
	if (c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

char		*check_flag(char *str)
{
	while (*(str))
	{
		if (ft_isconvertable(*(str)))
			return (str);
		str++;
	}
	return (NULL);
}

int			ft_printf(const char *str, ...)
{
	va_list		lst;
	char		*tmp;

	va_start(lst, str);
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '%')
		{
			if ((tmp = check_flag((char *)(str + 1))))
			{
				gather_data((char *)str + 1, lst, *tmp, ft_retfun(*tmp));
				str = tmp;
			}
		}
		else
			ft_putchar_fdret(*str, 1);
		str++;
	}
	va_end(lst);
	return (g_ret);
}
