/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:40:35 by egervais          #+#    #+#             */
/*   Updated: 2023/04/27 21:10:08 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rra_rrb(t_list **a, t_list **b, int nbr, int index)
{
    int sizeb = ft_lstsize(*b);
    int sizea = ft_lstsize(*a);
    int rra = sizea - index + 1;
    int rrb = sizeb - find_position_in_b(*b, nbr);
    if(index == 0)
        return (rrb);
    if(rra > rrb)
        return(rra);
    return(rrb);
}

int ra_rb(t_list **a, t_list **b, int nbr, int index)
{
    int rb = find_position_in_b(*b, nbr);

    if(index > rb)
        return(index);
    return(rb);
}

int rra_rb(t_list **a, t_list **b, int nbr, int index)
{
    int sizea = ft_lstsize(*a);
    int rra = sizea - index + 1;
    int rb = find_position_in_b(*b, nbr);
    return (rra + rb);
}

int ra_rrb(t_list **a, t_list **b, int nbr, int index)
{
    int sizeb = ft_lstsize(*b);
    int rrb = sizeb - find_position_in_b(*b, nbr);
    return(index + rrb);
}