/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:10:14 by egervais          #+#    #+#             */
/*   Updated: 2023/01/31 15:47:26 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!str || !to_find)
		return (NULL);
	if (!*to_find)
		return ((char *)str);
	i = 0;
	while (str[i] && (size_t)i < len)
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (str[i + j] == to_find[j] && i + j < len)
			{
				if (to_find[j + 1] == '\0')
					return ((char *)&str[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}

//#include<stdio.h>

// int main()
//{
//	char str[] = "MZIRIBMZIRIBMZE123";
//	char substr[] = "MZIRIBMZE";

//	printf("%s\n", ft_strnstr(str, substr, 9));
//	printf("%s\n", strnstr(str, substr, 9));
//}