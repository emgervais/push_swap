/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:19:09 by egervais          #+#    #+#             */
/*   Updated: 2023/05/13 17:55:38 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_bruh **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_bruh **a, t_bruh **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rra(t_bruh **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_bruh **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_bruh **a, t_bruh **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
