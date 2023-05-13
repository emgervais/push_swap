/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:30:11 by egervais          #+#    #+#             */
/*   Updated: 2023/05/13 18:25:26 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	duble(t_list *first, t_list *current)
{
	long	num;
	t_list	*temp;

	num = current->nbr;
	temp = first;
	if (first == current)
		return (0);
	while (temp != current)
	{
		if (num == temp->nbr)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static int	check(long nbr, long *sorted)
{
	int	i;

	i = 0;
	while (nbr != sorted[i])
		i++;
	i++;
	return (i);
}

int	sort_list(t_list *nums, long *sorted, int ac)
{
	t_list	*temp;

	temp = nums;
	presort(sorted, ac);
	while (temp)
	{
		if (duble(nums, temp))
			return (1);
		else
			temp->pos = check(temp->nbr, sorted);
		temp = temp->next;
	}
	free(sorted);
	return (0);
}

int	init_a(t_bruh **a, t_list *nums)
{
	t_bruh	*temp;
	t_list	*temp2;

	(*a)->content = nums->pos;
	(*a)->next = NULL;
	temp2 = nums->next;
	while (temp2)
	{
		temp = ft_lstnew(temp2->pos);
		if (!temp)
			return (1);
		ft_lstadd_back(a, temp);
		temp2 = temp2->next;
	}
	return (0);
}
