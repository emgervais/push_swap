/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:10:08 by egervais          #+#    #+#             */
/*   Updated: 2023/05/10 12:38:12 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_freee(t_bruh **a, t_bruh **b)
{
    if(a)
        free(a);
    else if(b)
        free(b);
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}

static void free_a(t_bruh **a)
{
    t_bruh *temp;
    t_bruh *temp2;
    
    if(*a)
    {
        temp = (*a);
        while(temp)
        {
            temp2 = temp->next;
            free(temp);
            temp = temp2;
        }
    }
    free(a);
}
static void free_b(t_bruh **b)
{
    t_bruh *temp;
    t_bruh *temp2;
    
    if(*b)
    {
        temp = (*b);
        while(temp)
        {
            temp2 = temp->next;
            free(temp);
            temp = temp2;
        }
    }
    free(b);
}
void free_list(t_bruh **a, t_bruh **b, int error)
{
    free_a(a);
    free_b(b);
    if(error == 1)
    {
        write(2, "Error\n", 6);
        exit(1);
    }
    else
        return ;
}

int ft_clear(t_list *first)
{
    t_list *temp;

    while(temp)
    {
        temp = first->next;
        free(first);
        first = temp;
    }
    return(1);
}