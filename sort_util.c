/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:54:18 by egervais          #+#    #+#             */
/*   Updated: 2023/05/03 17:40:49 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(t_bruh *list)
{
    int nbr = list->content;
    t_bruh *temp = list;

    while(temp)
    {
        if(nbr < temp->content)
            nbr = temp->content;
        temp = temp->next;
    }
    return(nbr);
}

int find_min(t_bruh *list)
{
    int nbr = list->content;
    t_bruh *temp = list;

    while(temp)
    {
        if(nbr > temp->content)
            nbr = temp->content;
        temp = temp->next;
    }
    return(nbr);
}

int find_position_in_b(t_bruh *b, int nbr)
{
    int pos = 1;
    t_bruh *temp;
    t_bruh *temp2;

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
			temp = temp->next;
			temp2 = temp->next;
			pos++;
		}
	}
    return(pos);
}

int find_position_in_a(t_bruh *a, int nbr)
{
    int pos = 1;
    t_bruh *temp;
    t_bruh *temp2;

    temp = a;

    if(nbr < temp->content && nbr > ft_lstlast(temp)->content)
        pos = 0;
    else if(nbr > find_max(a) || nbr < find_min(a))
        pos = (find_index(&a, find_max(a)) + 1) % ft_lstsize(a);
	else
	{
		temp2 = temp->next;
		while (temp->content > nbr || temp2->content < nbr)
		{
			temp = temp->next;
			temp2 = temp->next;
			pos++;
		}
	}
    return(pos);
}

int find_index(t_bruh **list, int nbr)
{
    t_bruh *temp = (*list);
    int i = 0;
    
    while(temp && temp->content != nbr)
    {
        ++i;
        temp = temp->next;
    }
    return (i);
}