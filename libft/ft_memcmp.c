/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:39:10 by egervais          #+#    #+#             */
/*   Updated: 2023/01/31 16:15:25 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (!s1 || !s2 || n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (*str1 == *str2 && n - 1 > 0)
	{
		str1++;
		str2++;
		n--;
	}
	return (*str1 - *str2);
}

//#include<stdio.h>

//int main()
//{
//	printf("%d\n", ft_memcmp("123ba", "123bx", 5));
//	printf("%d\n", memcmp("123ba", "123bx", 5));
//}