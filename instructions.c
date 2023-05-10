/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:57:08 by egervais          #+#    #+#             */
/*   Updated: 2023/05/03 18:33:29 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_bruh** a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void pa(t_bruh** a, t_bruh** b)
{
    push_other(a, b);
    write(1, "pa\n", 3);
}

void pb(t_bruh** a, t_bruh** b)
{
    push_other(b, a);
    write(1, "pb\n", 3);
}

void ra(t_bruh** a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(t_bruh** b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(t_bruh** a, t_bruh** b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}

void rra(t_bruh** a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(t_bruh** b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(t_bruh** a, t_bruh** b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}