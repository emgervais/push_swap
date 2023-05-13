/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 22:34:33 by egervais          #+#    #+#             */
/*   Updated: 2023/05/13 17:58:43 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_rra_rrb_a(t_bruh **a, t_bruh **b, int nbr)
{
	while ((*b)->content != nbr && find_position_in_a(*a, nbr) > 0)
		rrr(a, b);
	while ((*b)->content != nbr)
		rrb(b);
	while (find_position_in_a(*a, nbr) > 0)
		rra(a);
	pa(a, b);
}

void	apply_ra_rb_a(t_bruh **a, t_bruh **b, int nbr)
{
	while ((*b)->content != nbr && find_position_in_a(*a, nbr) > 0)
		rr(a, b);
	while ((*b)->content != nbr)
		rb(b);
	while (find_position_in_a(*a, nbr) > 0)
		ra(a);
	pa(a, b);
}

void	apply_ra_rrb_a(t_bruh **a, t_bruh **b, int nbr)
{
	while ((*b)->content != nbr)
		rrb(b);
	while (find_position_in_a(*a, nbr) > 0)
		ra(b);
	pa(a, b);
}

void	apply_rra_rb_a(t_bruh **a, t_bruh **b, int nbr)
{
	while ((*b)->content != nbr)
		rb(b);
	while (find_position_in_a(*a, nbr) > 0)
		rra(a);
	pa(a, b);
}
