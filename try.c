/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:35:03 by egervais          #+#    #+#             */
/*   Updated: 2023/04/27 21:42:25 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void presort(int *list, int ac)
{
    int i = 1;
    int temp;

    while(i < ac - 1)
    {
        if(list[i - 1] > list[i])
        {
            temp = list[i - 1];
            list[i - 1] = list[i];
            list[i] = temp;
            i = 0;
        }
        i++;
    }
}

void tinynbr(t_list **a)
{
    t_list *temp = (*a);
    if(temp->content < temp->next->content && temp->next->content < temp->next->next->content)
        ft_printf("3 nums sorted\n");
    if(temp->content < temp->next->content && temp->next->content > temp->next->next->content && temp->content < temp->next->next->content)
    {
        rra(a);
        sa(a);
        ft_printf("rra\nsa\n");
    }
    if(temp->content > temp->next->content && temp->next->content > temp->next->next->content)
    {
        sa(a);
        rra(a);
        ft_printf("sa\nrra\n");
    }
    if(temp->content > temp->next->content && temp->next->content < temp->next->next->content && temp->content > temp->next->next->content)
    {
        rra(a);
        rra(a);
        ft_printf("rra\nrra\n");
    }
    if(temp->content > temp->next->content && temp->next->content < temp->next->next->content && temp->content < temp->next->next->content)
    {
        sa(a);
        ft_printf("sa\n");
    }
    if(temp->content < temp->next->content && temp->next->content > temp->next->next->content && temp->content > temp->next->next->content)
    {
        rra(a);
        ft_printf("rra\n");
    }
}
void redirect(t_list **a, t_list **b)
{
    int size = ft_lstsize((*a));

    if(size < 3)
        ft_printf("sorted\n");
    if(size == 3)
        tinynbr(a);
}
int *check(char *av, int *list, int ac)
{
    int k = 0;
    int num = ft_atoi(av);

    while(num != list[k] && k < ac - 1)
        k++;
    k++;
    int *temp = k;
    return (temp);
}

int main(int ac, char **av)
{
    int i = 0;
    t_list **a = malloc(sizeof(t_list**));
    t_list **b = malloc(sizeof(t_list**));
    (*b) = NULL;
    int *sorted = malloc(sizeof(int) * ac);
    while(i < ac - 1)
    {
        sorted[i] = ft_atoi(av[i + 1]);
        i++;
    }
    sorted[i] = '\0';
    i = 1;
    presort(sorted, ac);
    t_list *temp = ft_lstnew(check(av[i++], sorted, ac));
    (*a) = temp;
    while(i < ac)
    {
        temp = ft_lstnew(check(av[i++], sorted, ac));
        ft_lstadd_back(a, temp);
    }
    i = 0;
    algo2(a, b);
    //redirect(a, b);
    temp = (*b);
    while(temp)
    {
        printf("num : %d\n", (int)temp->content);
        temp = temp->next;
    }
    return 0;
}