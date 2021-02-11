/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 00:02:53 by mashad            #+#    #+#             */
/*   Updated: 2019/11/15 11:53:06 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_printstr_m(int num, char *str, int len, int flag)
{
	if (flag == 1)
	{
		ft_putnstr(str, len);
		return (ft_putnchar(' ', num - len));
	}
	ft_putnchar(' ', num - len);
	return (ft_putnstr(str, len));
}

static void		ft_bothexist(char *str, int num[], int flag, int len)
{
	if (num[1] >= len)
		return (num[0] <= len ? ft_putnstr(str, len)
				: ft_printstr_m(num[0], str, len, flag));
	else
		return (num[0] <= num[1] ? ft_putnstr(str, num[1])
				: ft_printstr_m(num[0], str, num[1], flag));
}

void			ft_printstr(int flag, int num[], va_list lst)
{
	int		len;
	char	*str;

	if (!(str = va_arg(lst, char *)))
		str = "(null)";
	len = ft_strlen(str);
	if (num[4] == 1 && num[1] == 0)
		return (ft_printstr_m(num[0], str, 0, flag));
	if (num[2] == 0 && num[3] == 0)
		return (ft_putnstr(str, len));
	else if ((num[2] != 0 && num[3] == 0))
		return (num[0] <= len ? ft_putnstr(str, len)
				: ft_printstr_m(num[0], str, len, flag));
	else if (num[2] == 0 && num[3] != 0)
	{
		if (num[1] == 0)
			return ;
		return (num[1] < len ? ft_putnstr(str, num[1])
				: ft_putnstr(str, len));
	}
	else if (num[2] != 0 && num[3] != 0)
		ft_bothexist(str, num, flag, len);
}
