/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:40:59 by egervais          #+#    #+#             */
/*   Updated: 2023/02/06 11:43:05 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_pchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_pstr(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_pptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += ft_int(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_punsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_hexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_ppercent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;
	int		check;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		check = 0;
		if (str[i] == '%')
		{
			check = ft_formats(args, str[i + 1]);
			i++;
		}
		else
			check = ft_pchar(str[i]);
		if (check == ERROR)
			return (ERROR);
		print_length += check;
		i++;
	}
	va_end(args);
	return (print_length);
}
