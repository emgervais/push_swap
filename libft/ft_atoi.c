/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:45:43 by egervais          #+#    #+#             */
/*   Updated: 2023/01/31 12:51:43 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!str)
		return (0);
	while ((str[i] == '\n' || str[i] == ' ' || str[i] == '\f')
		|| (str[i] == '\t' || str[i] == '\v' || str[i] == '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}

//#include<stdio.h>
//#include<stdlib.h>

//int main()
//{
//    printf("%d\n", ft_atoi("\n    \t\v   -34867ds213salut"));
//    printf("%d\n", atoi("\n    \t\v   -34867ds213salut"));
//}