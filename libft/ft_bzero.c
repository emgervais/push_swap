/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:07:30 by egervais          #+#    #+#             */
/*   Updated: 2023/01/31 12:51:49 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*z;

	z = (unsigned char *)s;
	i = 0;
	if (!s)
		return ;
	while (i < n && n > 0)
	{
		z[i] = 0;
		i++;
	}
}

//#include<stdio.h>

//int main()
//{
//    char a[] = "123456789";

//    ft_bzero(a, 3);
//    printf("%c", a[2]);
//}