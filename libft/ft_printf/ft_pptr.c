/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:21:44 by egervais          #+#    #+#             */
/*   Updated: 2023/02/05 14:59:49 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static int	ft_put_ptr(uintptr_t num)
{
	int	i;

	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
		{
			i = ft_pchar((num + '0'));
			if (i == ERROR)
				return (ERROR);
		}
		else
		{
			i = ft_pchar((num - 10 + 'a'));
			if (i == ERROR)
				return (ERROR);
		}
	}
	return (0);
}

int	ft_pptr(unsigned long long ptr)
{
	int	print_length;
	int	i;

	print_length = 0;
	i = write(1, "0x", 2);
	if (i == ERROR)
		return (ERROR);
	print_length += i;
	if (ptr == 0)
	{
		i = write(1, "0", 1);
		if (i == ERROR)
			return (ERROR);
		print_length += i;
	}
	else
	{
		i = ft_put_ptr(ptr);
		if (i == ERROR)
			return (ERROR);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}
