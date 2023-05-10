/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:41:19 by egervais          #+#    #+#             */
/*   Updated: 2023/05/03 18:39:00 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algo(t_bruh **a, t_bruh **b, t_best *best)
{
    int actions;
    int index = 0;
    t_bruh *temp = (*a);
    actions = b_rra_rrb(a, b, temp->content, index);
    best->nbr = temp->content;
    best->act = actions;
    best->index = 0;
    while(temp)
    {
        if(actions > b_rra_rrb(a, b, temp->content, index))
            actions = b_rra_rrb(a, b, temp->content, index);
        if(actions > b_ra_rb(b, temp->content, index))
            actions = b_ra_rb(b, temp->content, index);
        if(actions > b_ra_rrb(b, temp->content, index))
            actions = b_ra_rrb(b, temp->content, index);
        if(actions > b_rra_rb(a, b, temp->content, index))
            actions = b_rra_rb(a, b, temp->content, index);
        if(actions < best->act)
        {
            best->nbr = temp->content;
            best->act = actions;
            best->index = index;
        }
        index++;
        temp = temp->next;
    }
}

void algo2(t_bruh **a, t_bruh **b)
{
    t_best *best = malloc(sizeof(t_best));
    pb(a, b);
    pb(a, b);
    while(ft_lstsize(*a) > 3)
    {
        algo(a, b, best);
        if(best->act == b_rra_rrb(a, b, best->nbr, best->index))
            apply_rra_rrb_b(a, b, best->nbr);
        else if(best->act == b_ra_rb(b, best->nbr, best->index))
            apply_ra_rb_b(a, b, best->nbr);
        else if(best->act == b_ra_rrb(b, best->nbr, best->index))
            apply_ra_rrb_b(a, b, best->nbr);
        else if(best->act == b_rra_rb(a, b, best->nbr, best->index))
            apply_rra_rb_b(a, b, best->nbr);
    }
    free(best);
}

void algoa1(t_bruh **a, t_bruh **b, t_best *best)
{
    int actions;
    int index = 0;
    t_bruh *temp = (*b);
    actions = a_rra_rrb(a, b, temp->content, index);
    best->nbr = temp->content;
    best->act = actions;
    best->index = 0;
    while(temp)
    {
        if(actions > a_rra_rrb(a, b, temp->content, index))
            actions = a_rra_rrb(a, b, temp->content, index);
        if(actions > a_ra_rb(a, temp->content, index))
            actions = a_ra_rb(a, temp->content, index);
        if(actions > a_ra_rrb(a, b, temp->content, index))
            actions = a_ra_rrb(a, b, temp->content, index);
        if(actions > a_rra_rb(a, temp->content, index))
            actions = a_rra_rb(a, temp->content, index);
        if(actions < best->act)
        {
            best->nbr = temp->content;
            best->act = actions;
            best->index = index;
        }
        index++;
        temp = temp->next;
    }
}

void algoa2(t_bruh **a, t_bruh **b)
{
    t_best *best = malloc(sizeof(t_best));
    while(*b)
    {
        algoa1(a, b, best);
        if(best->act == a_rra_rrb(a, b, best->nbr, best->index))
            apply_rra_rrb_a(a, b, best->nbr);
        else if(best->act == a_ra_rb(a, best->nbr, best->index))
            apply_ra_rb_a(a, b, best->nbr);
        else if(best->act == a_ra_rrb(a, b, best->nbr, best->index))
            apply_ra_rrb_a(a, b, best->nbr);
        else if(best->act == a_rra_rb(a, best->nbr, best->index))
            apply_rra_rb_a(a, b, best->nbr);
    }
    free(best);
}

void tinynbr(t_bruh **a)
{
    t_bruh *temp = (*a);
    if(temp->content < temp->next->content && temp->next->content > temp->next->next->content && temp->content < temp->next->next->content)
    {
        rra(a);
        sa(a);
    }
    else if(temp->content > temp->next->content && temp->next->content > temp->next->next->content)
    {
        sa(a);
        rra(a);
    }
    else if(temp->content > temp->next->content && temp->next->content < temp->next->next->content && temp->content > temp->next->next->content)
    {
        rra(a);
        rra(a);
    }
    else if(temp->content > temp->next->content && temp->next->content < temp->next->next->content && temp->content < temp->next->next->content)
    {
        sa(a);
    }
    else if(temp->content < temp->next->content && temp->next->content > temp->next->next->content && temp->content > temp->next->next->content)
    {
        rra(a);
    }
}