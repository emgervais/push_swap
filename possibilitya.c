/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibilitya.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:01:15 by egervais          #+#    #+#             */
/*   Updated: 2023/05/13 17:53:35 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_rra_rrb(t_bruh **a, t_bruh **b, int nbr, int index)
{
	int	rra;
	int	rrb;

	rra = ft_lstsize(*b) - find_position_in_a(*a, nbr);
	rrb = ft_lstsize(*a) - index;
	if (find_position_in_a(*a, nbr) == 0)
		rra = 0;
	if (index == 0)
		return (rra);
	if (rrb > rra)
		return (rrb);
	return (rra);
}

int	a_ra_rb(t_bruh **a, int nbr, int index)
{
	int	ra;

	ra = find_position_in_a(*a, nbr);
	if (index > ra)
		return (index);
	return (ra);
}

int	a_rra_rb(t_bruh **a, int nbr, int index)
{
	int	rra;

	rra = ft_lstsize(*a) - find_position_in_a(*a, nbr);
	if (find_position_in_a(*a, nbr) == 0)
		rra = 0;
	return (rra + index);
}

int	a_ra_rrb(t_bruh **a, t_bruh **b, int nbr, int index)
{
	int	rrb;
	int	ra;

	rrb = ft_lstsize(*b) - index;
	ra = find_position_in_a(*a, nbr);
	if (index == 0)
		rrb = 0;
	return (ra + rrb);
}
