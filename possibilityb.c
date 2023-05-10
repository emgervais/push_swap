/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibilityb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:40:35 by egervais          #+#    #+#             */
/*   Updated: 2023/05/03 18:02:17 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int b_rra_rrb(t_bruh **a, t_bruh **b, int nbr, int index)
{
    int sizeb = ft_lstsize(*b);
    int sizea = ft_lstsize(*a);
    int rra = sizea - index + 1;
    int rrb = sizeb - find_position_in_b(*b, nbr);
    
    if(find_position_in_b(*b, nbr) == 0)
        rrb = 0;
    if(index == 0)
        return (rrb);
    if(rra > rrb)
        return(rra);
    return(rrb);
}

int b_ra_rb(t_bruh **b, int nbr, int index)
{
    int rb = find_position_in_b(*b, nbr);

    if(index > rb)
        return(index);
    return(rb);
}

int b_rra_rb(t_bruh **a, t_bruh **b, int nbr, int index)
{
    int sizea = ft_lstsize(*a);
    int rra = sizea - index + 1;
    int rb = find_position_in_b(*b, nbr);
    return (rra + rb);
}

int b_ra_rrb(t_bruh **b, int nbr, int index)
{
    int sizeb = ft_lstsize(*b);
    int rrb = sizeb - find_position_in_b(*b, nbr);
    return(index + rrb);
}