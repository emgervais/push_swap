/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:56:19 by egervais          #+#    #+#             */
/*   Updated: 2023/05/13 18:08:23 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish(t_bruh **a)
{
	int	min;

	min = find_index(a, 1);
	if (min > ft_lstsize(*a) / 2)
		while (find_index(a, 1))
			rra(a);
	else
		while (find_index(a, 1))
			ra(a);
}

void	two_nbr(t_bruh **a)
{
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void	redirect(int size, t_bruh **a, t_bruh **b)
{
	if (size == 1)
		return ;
	else if (size == 2)
		two_nbr(a);
	else if (size == 3)
		tinynbr(a);
	else
	{
		algo2(a, b);
		if (ft_lstsize(*a) == 2)
			two_nbr(a);
		else
			tinynbr(a);
		algoa2(a, b);
		finish(a);
	}
}

void	reverse_rotate(t_bruh **top)
{
	int		data;
	t_bruh	*last;
	t_bruh	*temp;

	if (*top != NULL && (*top)->next != NULL)
	{
		last = *top;
		while (last->next->next != NULL)
		{
			last = last->next;
		}
		data = last->next->content;
		temp = last->next;
		last->next = NULL;
		free(temp);
		push(top, data);
	}
}

void	adjust_best(t_best *best, long content, int actions, int index)
{
	best->nbr = content;
	best->act = actions;
	best->index = index;
}
