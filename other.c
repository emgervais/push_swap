/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:56:19 by egervais          #+#    #+#             */
/*   Updated: 2023/05/10 11:56:42 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void finish(t_bruh **a)
{
    int min = find_index(a, 1);
    if(min > ft_lstsize(*a) / 2)
        while(find_index(a, 1))
            rra(a);
    else
        while(find_index(a, 1))
            ra(a);
}

void two_nbr(t_bruh **a)
{
    if((*a)->content > (*a)->next->content)
        sa(a);
}
void redirect(int size, t_bruh **a, t_bruh **b)
{
    if(size == 1)
        return ;
    else if(size == 2)
        two_nbr(a);
    else if(size == 3)
        tinynbr(a);
    else
    {
        algo2(a, b);
        tinynbr(a);
        algoa2(a, b);
        finish(a);
    }
}
