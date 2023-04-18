/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:45:05 by egervais          #+#    #+#             */
/*   Updated: 2023/01/31 16:22:18 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ischar(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		i;
	int		z;
	char	*f;

	if (!s1 || !set)
		return (NULL);
	a = 0;
	i = 0;
	z = ft_strlen(s1) - 1;
	while (ischar(set, s1[a]) && s1[a])
		a++;
	while (ischar(set, s1[z]) && a <= z)
		z--;
	f = malloc(sizeof(*s1) * (z - a + 2));
	if (!f)
		return (NULL);
	while (a <= z)
		f[i++] = s1[a++];
	f[i] = 0;
	return (f);
}

//#include <stdio.h>

//int main()
//{
//    printf("%s", ft_strtrim("             ", " "));
//}