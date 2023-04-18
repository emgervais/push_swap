/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:32:53 by egervais          #+#    #+#             */
/*   Updated: 2023/01/31 16:17:41 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str)
	{
		if (*str == (char) c)
			return (str);
		else
			str++;
	}
	if ((char) c == '\0')
		return (str);
	return (NULL);
}

//#include <stdio.h>
//#include <string.h>

//int main()
//{
//    printf("%s", ft_strchr((void *)0, '\0'));
//}