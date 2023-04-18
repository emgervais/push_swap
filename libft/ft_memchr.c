/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:15:06 by egervais          #+#    #+#             */
/*   Updated: 2023/01/31 16:14:57 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	if (!s)
		return (0);
	str = (unsigned char *)s;
	c = (unsigned char)c;
	while (n > 0)
	{
		if (*str == c)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}

//#include <stdio.h>

//int main()
//{
//    printf("%s\n", ft_memchr("salutation", 'z', 4));
//    printf("%s\n", memchr("salutation", 'z', 4));
//}