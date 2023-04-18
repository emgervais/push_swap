/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:12:18 by egervais          #+#    #+#             */
/*   Updated: 2023/02/05 14:51:04 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_punsigned(unsigned int n)
{
	int		print_length;
	char	*num;
	int		i;

	print_length = 0;
	if (n == 0)
	{
		i = write(1, "0", 1);
		if (i == ERROR)
			return (ERROR);
		print_length += i;
	}
	else
	{
		num = ft_uitoa(n);
		if (num == NULL)
			return (ERROR);
		i = ft_pstr(num);
		free(num);
		print_length += i;
		if (i == ERROR)
			return (ERROR);
	}
	return (print_length);
}
