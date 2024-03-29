/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:57:08 by egervais          #+#    #+#             */
/*   Updated: 2023/05/13 18:09:52 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_bruh **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	pa(t_bruh **a, t_bruh **b)
{
	push_other(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_bruh **a, t_bruh **b)
{
	push_other(b, a);
	write(1, "pb\n", 3);
}

void	ra(t_bruh **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	apply_tiny_nbr(int s, int orientation, t_bruh **a)
{
	if (s)
	{
		if (orientation == 1)
		{
			rra(a);
			sa(a);
			return ;
		}
		sa(a);
		rra(a);
		return ;
	}
	rra(a);
	rra(a);
}
