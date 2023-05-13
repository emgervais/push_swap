/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibilityb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:40:35 by egervais          #+#    #+#             */
/*   Updated: 2023/05/13 17:53:12 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	b_rra_rrb(t_bruh **a, t_bruh **b, int nbr, int index)
{
	int	rra;
	int	rrb;

	rra = ft_lstsize(*a) - index + 1;
	rrb = ft_lstsize(*b) - find_position_in_b(*b, nbr);
	if (find_position_in_b(*b, nbr) == 0)
		rrb = 0;
	if (index == 0)
		return (rrb);
	if (rra > rrb)
		return (rra);
	return (rrb);
}

int	b_ra_rb(t_bruh **b, int nbr, int index)
{
	int	rb;

	rb = find_position_in_b(*b, nbr);
	if (index > rb)
		return (index);
	return (rb);
}

int	b_rra_rb(t_bruh **a, t_bruh **b, int nbr, int index)
{
	int	rra;

	rra = ft_lstsize(*a) - index + 1;
	return (rra + find_position_in_b(*b, nbr));
}

int	b_ra_rrb(t_bruh **b, int nbr, int index)
{
	int	rrb;

	rrb = ft_lstsize(*b) - find_position_in_b(*b, nbr);
	return (index + rrb);
}
