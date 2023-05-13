/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:28:36 by egervais          #+#    #+#             */
/*   Updated: 2023/05/13 18:25:42 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	presort(long *list, int ac)
{
	int		i;
	long	temp;

	i = 1;
	while (i < ac)
	{
		if (list[i - 1] > list[i])
		{
			temp = list[i - 1];
			list[i - 1] = list[i];
			list[i] = temp;
			i = 0;
		}
		i++;
	}
	list[i] = 0;
}

static int	init_arg(long *sorted, t_list *nums)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = nums;
	while (temp)
	{
		sorted[i++] = temp->nbr;
		temp = temp->next;
	}
	return (0);
}

int	fill_arg(long *sorted, char **list, t_list *nums)
{
	t_list	*temp;
	t_list	*temp2;
	int		i;

	i = 0;
	if (!nums)
		return (1);
	nums->next = NULL;
	nums->back = NULL;
	nums->nbr = ft_atoi(list[i++]);
	while (list[i])
	{
		temp = malloc(sizeof(t_list));
		if (!temp)
			return (ft_clear(nums));
		temp->nbr = ft_atoi(list[i++]);
		temp2 = nums;
		while (temp2->next)
			temp2 = temp2->next;
		temp->next = NULL;
		temp->back = temp2;
		temp2->next = temp;
	}
	return (init_arg(sorted, nums));
}

static int	valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9'))
	{
		if (ft_atoi(str) <= INT_MAX && ft_atoi(str) >= INT_MIN)
			i++;
		else
			return (1);
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (ft_atoi(str) <= INT_MAX && ft_atoi(str) >= INT_MIN)
				i++;
			else
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

int	nums_valid(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if (!list[i][0])
			return (1);
		else if (valid(list[i]))
			return (1);
		i++;
	}
	return (0);
}
