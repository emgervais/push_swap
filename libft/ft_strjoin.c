/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:27:43 by egervais          #+#    #+#             */
/*   Updated: 2023/01/31 16:19:27 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill(const char *s1, const char *s2, char *f, int i)
{
	int	z;

	z = 0;
	while (s1[z])
	{
		f[z] = s1[z];
		z++;
	}
	z = 0;
	while (s2[z])
	{
		f[i + z] = s2[z];
		z++;
	}
	f[i + z] = 0;
	return (f);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		c;
	char	*f;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	c = ft_strlen(s2);
	f = malloc(sizeof(char) * (c + i + 1));
	if (!f)
		return (NULL);
	f = ft_fill(s1, s2, f, i);
	return (f);
}

// #include<stdio.h>
// int main()
//{
//	printf("%s\n", ft_strjoin("they", "standalone"));
//}