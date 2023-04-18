/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:54:09 by egervais          #+#    #+#             */
/*   Updated: 2023/02/05 14:58:23 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ilen(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa(int n)
{
	char		*f;
	int			l;
	int			i;
	long int	nb;

	nb = n;
	l = ft_ilen(nb);
	i = 0;
	f = malloc(sizeof(char) * (l + 1));
	if (!f)
		return (NULL);
	f[l--] = 0;
	if (nb < 0)
	{
		f[i++] = '-';
		nb *= -1;
	}
	while (l >= i)
	{
		f[l] = nb % 10 + 48;
		nb /= 10;
		l--;
	}
	return (f);
}

int	ft_int(int nb)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(nb);
	if (num == NULL)
		return (ERROR);
	len = ft_pstr(num);
	free(num);
	if (len == ERROR)
		return (ERROR);
	return (len);
}
