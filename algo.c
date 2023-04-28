/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:41:19 by egervais          #+#    #+#             */
/*   Updated: 2023/04/27 21:50:52 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(t_list *list)
{
    int nbr = list->content;
    t_list *temp = list;

    while(temp)
    {
        if(nbr < temp->content)
            nbr = temp->content;
        temp = temp->next;
    }
    return(nbr);
}

int find_min(t_list *list)
{
    int nbr = list->content;
    t_list *temp = list;

    while(temp)
    {
        if(nbr > temp->content)
            nbr = temp->content;
        temp = temp->next;
    }
    return(nbr);
}

int find_position_in_b(t_list *b, int nbr)
{
    int pos = 1;
    t_list *temp;
    t_list *temp2;

    temp = b;

    if(nbr > temp->content && nbr < ft_lstlast(temp)->content)
        pos = 0;
    else if(nbr > find_max(b) || nbr < find_min(b))
        pos = (find_index(&b, find_min(b)) + 1) % ft_lstsize(b);
	else
	{
		temp2 = temp->next;
		while (temp->content < nbr || temp2->content > nbr)
		{
			temp2 = temp2->next;
			temp = temp->next;
			pos++;
		}
	}
    return(pos);
}


int find_index(t_list **list, int nbr)
{
    t_list *temp = (*list);
    int i = 0;
    
    while(temp && temp->content != nbr)
    {
        ++i;
        temp = temp->next;
    }
    return (i);
}
//int first_check(t_list **a, t_list **b, int nbr)
//{
//    int i = find_index(a, nbr);
//    t_list *temp = (*a);
//    while(temp)
//    {
        
//    }
//}
void algo(t_list **a, t_list **b, t_best *best)
{
    int actions;
    int index = 0;
    t_list *temp = (*a);
    actions = rra_rrb(a, b, temp->content, index);
    best->nbr = temp->content;
    best->act = actions;
    best->index = 0;
    while(temp)
    {
        if(actions > rra_rrb(a, b, temp->content, index))
            actions = rra_rrb(a, b, temp->content, index);
        printf("(rra_rrb)action : %d for num : %d\n", actions, temp->content);
        if(actions > ra_rb(a, b, temp->content, index))
            actions = ra_rb(a, b, temp->content, index);
        printf("(ra_rb)action : %d for num : %d\n", actions, temp->content);
        if(actions > ra_rrb(a, b, temp->content, index))
            actions = ra_rrb(a, b, temp->content, index);
        printf("(ra_rrb)action : %d for num : %d\n", actions, temp->content);
        if(actions > rra_rb(a, b, temp->content, index))
            actions = rra_rb(a, b, temp->content, index);
        printf("last (rra_rb)action : %d for num : %d\n\n", actions, temp->content);
        if(actions < best->act)
        {
            best->nbr = temp->content;
            best->act = actions;
            best->index = index;
        }
        index++;
        temp = temp->next;
    }
    //printf("best num : %d for act : %d to index %d\n", best->nbr, best->act, best->index);
}

void apply_rra_rrb(t_list **a, t_list **b, int nbr)
{
    int pos = ft_lstsize(*b) - find_position_in_b(*b, nbr);
    int i = 0;

    while((*a)->content != nbr && i < pos)
    {
        rrr(a, b);
        i++;
    }
    while((*a)->content != nbr)
        rra(a);
    while(i < pos)
    {
        rrb(b);
        i++;
    }
    pb(a, b);
}

void apply_ra_rb(t_list **a, t_list **b, int nbr)
{
    int pos = find_position_in_b(*b, nbr);
    int i = 0;

    while((*a)->content != nbr && i < pos)
    {
        rr(a, b);
        i++;
    }
    while((*a)->content != nbr)
    {
        ra(a);
    }
    while(i < pos)
    {
        rb(b);
        i++;
    }
    pb(a, b);
}

void apply_ra_rrb(t_list **a, t_list **b, int nbr)
{
    int pos = ft_lstsize(*b) - find_position_in_b(*b, nbr) - 1;
    int i = 0;

    while((*a)->content != nbr)
        ra(a);
    while(i < pos)
    {
        rrb(b);
        i++;
    }
    pb(a, b);
}

void apply_rra_rb(t_list **a, t_list **b, int nbr)
{
    int pos = find_position_in_b(*b, nbr);
    int i = 0;

    while((*a)->content != nbr)
        rra(a);
    while(i < pos)
    {
        rb(b);
        i++;
    }
    pb(a, b);
}

void algo2(t_list **a, t_list **b)
{
    t_list *temp = (*a);
    t_best *best = malloc(sizeof(t_best));
    pb(a, b);
    pb(a, b);
    while(ft_lstsize(*a) > 3)
    {
        algo(a, b, best);
        if(best->act == rra_rrb(a, b, best->nbr, best->index))
            apply_rra_rrb(a, b, best->nbr);
        else if(best->act == ra_rb(a, b, best->nbr, best->index))
            apply_ra_rb(a, b, best->nbr);
        else if(best->act == ra_rrb(a, b, best->nbr, best->index))
            apply_ra_rrb(a, b, best->nbr);
        else if(best->act == rra_rb(a, b, best->nbr, best->index))
            apply_rra_rb(a, b, best->nbr);
        //printf("act ;%d nbr : %d index ; %d\n\n\n", best->act, best->nbr, best->index);
    }
}
