/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:07:48 by egervais          #+#    #+#             */
/*   Updated: 2023/01/31 16:21:19 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

//int	ft_strncmp(const char *s1, const char *s2, size_t n)
//{
//	if (n == 0)
//	{
//		return (0);
//	}
//	while (*s1 == *s2 && *s1 != '\0' && n - 1 > 0)
//	{
//		s1++;
//		s2++;
//		n--;
//	}
//	return (*s1 - *s2);
//}
//#include<stdio.h>
//#include<string.h>

//int main()
//{
//	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
//	printf("%d", strncmp("test\200", "test\0", 6));
//}