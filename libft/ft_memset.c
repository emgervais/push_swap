/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:37:43 by egervais          #+#    #+#             */
/*   Updated: 2023/01/31 16:16:13 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int c, size_t len)
{
	size_t	i;

	if (!a)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((unsigned char *)a)[i] = c;
		i++;
	}
	return (a);
}

//#include<stdio.h>

//int main()
//{
//    char str[] = "123456789";
//    ft_memset(str, 'a', 6);
//    printf("%s", str);
//}