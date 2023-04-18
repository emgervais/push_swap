/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:03:44 by egervais          #+#    #+#             */
/*   Updated: 2023/01/31 12:25:22 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_itoa(int n)
{
	char		*f;
	int			l;
	int			i;
	long int	nb;

	nb = n;
	l = ft_ilen(nb);
	i = 0;
	f = malloc(sizeof(char) * (l + 1));
	if (!(f))
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

//#include <stdio.h>

//int main()
//{
//    printf("%s", ft_itoa(-2147483648));
//}