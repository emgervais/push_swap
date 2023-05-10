/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:55:56 by egervais          #+#    #+#             */
/*   Updated: 2023/05/09 00:18:36 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push(t_bruh** top, int data)
{
    t_bruh* newnode;
    newnode = malloc(sizeof(t_bruh));
    if(!newnode)
        return (ERROR);
    newnode->content = data;
    if(!*top)
        newnode->next = NULL;
    else
        newnode->next = *top;
    *top = newnode;
    return (0);
}

int pop(t_bruh** top)
{
    t_bruh* temp;
    temp = *top;
    *top = (*top)->next;
    int data = temp->content;
    free(temp);
    return (data);
}

void swap(t_bruh** top)
{
    if (*top != NULL && (*top)->next != NULL)
    {
        int temp = (*top)->content;
        (*top)->content = (*top)->next->content;
        (*top)->next->content = temp;
    }
}

void push_other(t_bruh** dest, t_bruh** src)
{
    if(!*src)
        return ;
    int data;
    data = pop(src);
    if(push(dest, data))
        free_list(dest, src, 1);
}

void rotate(t_bruh** top) 
{
    if (*top != NULL && (*top)->next != NULL) 
    {
        t_bruh* last;
        last = *top;
        while(last->next)
            last = last->next;
        last->next = *top;
        last = (*top)->next;
        (*top)->next = NULL;
        (*top) = last;
    }
}

void reverse_rotate(t_bruh** top) 
{
    if (*top != NULL && (*top)->next != NULL)
    {
        t_bruh* last;
        last = *top;
        while (last->next->next != NULL) {
            last = last->next;
        }
        int data = last->next->content;
        t_bruh* temp;
        temp = last->next;
        last->next = NULL;
        free(temp);
        push(top, data);
    }
}