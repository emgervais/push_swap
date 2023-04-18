/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:49:36 by egervais          #+#    #+#             */
/*   Updated: 2023/02/05 14:58:50 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexalen(uintptr_t num)
{
	int	i;

	i = 0;
	while (num)
	{
		num /= 16;
		i++;
	}
	return (i);
}

static int	ft_hexap(uintptr_t num, const char format)
{
	int	i;

	if (num <= 9)
	{
		i = ft_pchar((num + '0'));
		if (i == ERROR)
			return (ERROR);
	}
	else
	{
		if (format == 'x')
		{
			i = ft_pchar((num - 10 + 'a'));
			if (i == ERROR)
				return (ERROR);
		}
		else if (format == 'X')
		{
			i = ft_pchar(num - 10 + 'A');
			if (i == ERROR)
				return (ERROR);
		}
	}
	return (0);
}

static int	ft_puthex(uintptr_t num, const char format)
{
	int	i;

	if (num >= 16)
	{
		i = ft_puthex(num / 16, format);
		if (i == ERROR)
			return (ERROR);
		i = ft_puthex(num % 16, format);
		if (i == ERROR)
			return (ERROR);
	}
	else
	{
		i = ft_hexap(num, format);
		if (i == ERROR)
			return (ERROR);
	}
	return (ft_hexalen(num));
}

int	ft_hexa(uintptr_t num, const char format)
{
	int	i;

	if (num == 0)
	{
		i = ft_pchar(48);
		if (i == ERROR)
			return (ERROR);
		return (1);
	}
	i = ft_puthex(num, format);
	if (i == ERROR)
		return (ERROR);
	return (i);
}
