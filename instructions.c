/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:57:08 by egervais          #+#    #+#             */
/*   Updated: 2023/04/27 21:47:41 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_list** top, void *data) {
    t_list* newNode = malloc(sizeof(t_list));
    newNode->content = data;
    if(!*top)
        newNode->next = NULL;
    else
        newNode->next = *top;
    *top = newNode;
}

void *pop(t_list** top) {
    t_list* temp = *top;
    *top = (*top)->next;
    void *data = temp->content;
    free(temp);
    return (data);
}

void swap(t_list** top) {
    if (*top != NULL && (*top)->next != NULL)
    {
        void *temp = (*top)->content;
        (*top)->content = (*top)->next->content;
        (*top)->next->content = temp;
    }
}

void push_other(t_list** dest, t_list** src) {
    if(!*src)
        return ;
    void *data = pop(src);
    push(dest, data);
}

void rotate(t_list** top) {
    if (*top != NULL && (*top)->next != NULL) 
    {
        t_list* last = *top;
        while(last->next)
            last = last->next;
        last->next = *top;
        last = (*top)->next;
        (*top)->next = NULL;
        (*top) = last;
    }
}

void reverse_rotate(t_list** top) {
    if (*top != NULL && (*top)->next != NULL) {
        t_list* last = *top;
        while (last->next->next != NULL) {
            last = last->next;
        }
        void *data = last->next->content;
        t_list* temp = last->next;
        last->next = NULL;
        free(temp);
        push(top, data);
    }
}

void sa(t_list** a) {
    swap(a);
}

void sb(t_list** b) {
    swap(b);
}

void ss(t_list** a, t_list** b) {
    swap(a);
    swap(b);
}

void pa(t_list** a, t_list** b) {
    push_other(a, b);
}

void pb(t_list** a, t_list** b) {
    push_other(b, a);
    printf("pb\n");
}

void ra(t_list** a) {
    rotate(a);
    printf("ra\n");
}

void rb(t_list** b) {
    rotate(b);
    printf("rb\n");
}

void rr(t_list** a, t_list** b) {
    rotate(a);
    rotate(b);
    printf("rr\n");
}

void rra(t_list** a) {
    reverse_rotate(a);
    printf("rra\n");
}

void rrb(t_list** b) {
    reverse_rotate(b);
    printf("rrb\n");
}

void rrr(t_list** a, t_list** b) {
    reverse_rotate(a);
    reverse_rotate(b);
    printf("rrr\n");
}