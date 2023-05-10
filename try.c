/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:35:03 by egervais          #+#    #+#             */
/*   Updated: 2023/05/10 15:23:41 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void presort(int *list, int ac)
{
    int i = 1;
    int temp;

    while(i < ac)
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
    list[i] = 0;
}
int init_arg(long *sorted, t_list *nums)
{
    int i;
    t_list *temp;

    i = 0;
    temp = nums;
    while(temp)
    {
        sorted[i++] = temp->nbr;
        temp = temp->next;
    }
    return (0);
}
int fill_arg(long *sorted, char **list, int size, t_list *nums)
{
    t_list *temp;
    t_list *temp2;
    int i;

    i = 0;
    if(!nums)
        return(1);
    nums->nbr = ft_atoi(list[i++]);
    nums->pos = i;
    while(list[i])
    {
        temp = malloc(sizeof(t_list));
        if(!temp)
            return(ft_clear(nums));
        temp->nbr = ft_atoi(list[i++]);
        temp->pos = i;
        temp2 = nums;
        while(temp2->next)
            temp2 = temp2->next;
        temp->next = NULL;
        temp->back = temp2;
        temp2->next = temp;
    }
    return(init_arg(sorted, nums));
}

int valid(char *str)
{
    int i;

    i = 0;
    if(str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9'))
        i++;
    while(str[i])
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            if(ft_atoi(str) <= INT_MAX && ft_atoi(str) >= INT_MIN)
                i++;
            else
                return(1);
        }
        else
            return (1);
    }
    return(0);
}
int nums_valid(char **list)
{
    int i;

    i = 0;
    while(list[i])
    {
        if(valid(list[i]))
            return(1);
        i++;
    }
    return(0);
}
int duble(t_list *first, t_list *current)
{
    long num;
    t_list *temp;

    num = current->back;
    temp = current;
    if(first == current)
        return(0);
    while(temp != first)
    {
        if(num == temp->nbr)
            return(1);
        temp = temp->back;
    }
    return (0);
}
int clear_all(t_list *nums, long *sorted)
{
    t_list *temp;

    temp = nums->next;
    free(nums);
    while(temp)
    {
        nums = temp;
        temp = temp->next;
        free(nums);
    }
    free(sorted);
}
int sort_list(t_list *nums, long *sorted, int ac)
{
    t_list *temp;
    int pos;

    temp = nums;
    presort(sorted, ac);
    while(temp)
    {
        if(duble(nums, temp))
            return(clear_all(nums, sorted));
        else
            temp->pos = check(temp->nbr, sorted);
        temp = temp->next;
    }
    free(sorted);
    return(0);
}
int init_a(t_bruh **a, t_list *nums)
{
       //a = num->pos
}
int parsing_arg(t_bruh **a, t_bruh **b, char **av, int ac)
{
    long *sorted;
    t_list *nums;
    
    nums = malloc(sizeof(t_list));
    sorted = malloc(sizeof(long) * ac);
    if(!sorted)
    {
        free(av);
        ft_freee(a, b);
    }
    if(nums_valid(av) || fill_arg(sorted, av, ac, nums))
    {
        free(av);
        free(sorted);
        ft_freee(a, b);
    }
    if(sort_list(nums, sorted, ac) || init_a(a, nums))//init pile a
    {
        free(av);
        free_list(a, b, 1);
    }
}

void parsing_str(t_bruh **a, t_bruh **b, char *av)
{
    char **list;
    int  *nbr;
    int   i;

    list = ft_split(av, ' ');
    if(!list)
        ft_freee(a, b);
    i = 0;
    while(list[i])
        i++;
    parsing_arg(a, b, list, i);
}

int main(int ac, char **av)
{
    int i = 0;
    int size;
    t_bruh **a = malloc(sizeof(t_bruh**));
    t_bruh **b = malloc(sizeof(t_bruh**));
    t_bruh *temp;
    if(!a || !b)
        ft_freee(a, b);
    (*b) = NULL;
    if(ac == 2)
        parsing_str(a, b, av[1]);
    else
        parsing_arg(a, b, av, ac - 1);
    temp = *a;
    while(temp)
    {
        printf("list %d\n", temp->content);
        temp = temp->next;
    }//segfault with doubles or infinite loop for 2 args : size's diffrent
    redirect(ft_lstsize((*a)), a, b);//segfault with weird number
    free_list(a, b, 0);//weird with negative;
    return (0);//check int max
}