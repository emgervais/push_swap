/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:49:06 by egervais          #+#    #+#             */
/*   Updated: 2023/02/05 14:50:50 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pstr(char *s)
{
	int	i;
	int	check;

	i = 0;
	if (!s)
	{
		check = ft_pstr("(null)");
		if (check == -1)
			return (ERROR);
		return (6);
	}
	while (s[i])
	{
		check = ft_pchar(s[i++]);
		if (check == -1)
			return (ERROR);
	}
	return (ft_strlen(s));
}

int	ft_ppercent(void)
{
	int	i;

	i = ft_pchar('%');
	if (i == ERROR)
		return (ERROR);
	return (1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
