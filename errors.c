/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:10:08 by egervais          #+#    #+#             */
/*   Updated: 2023/05/13 17:58:07 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freee(t_bruh **a, t_bruh **b)
{
	if (a)
		free(a);
	else if (b)
		free(b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	free_a(t_bruh **a)
{
	t_bruh	*temp;

	if (*a)
	{
		while (*a)
		{
			temp = (*a);
			(*a) = temp->next;
			free(temp);
		}
	}
	free(a);
}

static void	free_b(t_bruh **b)
{
	t_bruh	*temp;

	if (*b)
	{
		while (*b)
		{
			temp = (*b);
			(*b) = temp->next;
			free(temp);
		}
	}
	free(b);
}

void	free_list(t_bruh **a, t_bruh **b, int error)
{
	free_a(a);
	free_b(b);
	if (error == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else
		return ;
}

int	ft_clear(t_list *first)
{
	t_list	*temp;

	while (first)
	{
		temp = first;
		first = temp->next;
		free(temp);
	}
	return (1);
}
