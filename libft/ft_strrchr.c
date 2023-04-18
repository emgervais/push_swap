/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:50:58 by egervais          #+#    #+#             */
/*   Updated: 2023/01/31 16:22:08 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	if (!s)
		return (NULL);
	str = 0;
	while (*s)
	{
		if (*s == (const char)c)
			str = (char *)s;
		s++;
	}
	if ((const char)c == 0)
		return ((char *)s);
	else
		return (str);
}

//#include <stdio.h>
//#include <string.h>

//int main()
//{
//    printf("%s\n", ft_strrchr("salutation", '\0'));
//    printf("%s", strrchr("salutation", '\0'));
//}