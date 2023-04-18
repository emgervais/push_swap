/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:10:37 by egervais          #+#    #+#             */
/*   Updated: 2023/01/31 16:20:07 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstl;
	size_t	srcl;

	if (!dst || !src)
		return (0);
	srcl = ft_strlen(src);
	dstl = ft_strlen(dst);
	j = dstl;
	if (dstl < size - 1 && size > 0)
	{
		i = 0;
		while (src[i] && dstl + i < size - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (dstl >= size)
		dstl = size;
	return (dstl + srcl);
}

//#include<stdio.h>

//int main()
//{
//    const char src[] = "zxcvbnm";
//    char dst[14] = "a\0";

//    printf("%u\n", ft_strlcat(dst, "lorem ipsum dolor sit amet", 15));
//	ft_strlcat(dst, "lorem ipsum dolor sit amet", 15);
//    printf("%s", dst);
//}