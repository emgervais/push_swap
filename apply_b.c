/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:52:42 by egervais          #+#    #+#             */
/*   Updated: 2023/05/13 17:58:28 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_rra_rrb_b(t_bruh **a, t_bruh **b, int nbr)
{
	while ((*a)->content != nbr && find_position_in_b(*b, nbr) > 0)
		rrr(a, b);
	while ((*a)->content != nbr)
		rra(a);
	while (find_position_in_b(*b, nbr) > 0)
		rrb(b);
	pb(a, b);
}

void	apply_ra_rb_b(t_bruh **a, t_bruh **b, int nbr)
{
	while ((*a)->content != nbr && find_position_in_b(*b, nbr) > 0)
		rr(a, b);
	while ((*a)->content != nbr)
		ra(a);
	while (find_position_in_b(*b, nbr) > 0)
		rb(b);
	pb(a, b);
}

void	apply_ra_rrb_b(t_bruh **a, t_bruh **b, int nbr)
{
	while ((*a)->content != nbr)
		ra(a);
	while (find_position_in_b(*b, nbr) > 0)
		rrb(b);
	pb(a, b);
}

void	apply_rra_rb_b(t_bruh **a, t_bruh **b, int nbr)
{
	while ((*a)->content != nbr)
		rra(a);
	while (find_position_in_b(*b, nbr) > 0)
		rb(b);
	pb(a, b);
}
