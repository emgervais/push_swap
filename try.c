#include <stdio.h>
#include <stdlib.h>
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
    return data;
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
}

void ra(t_list** a) {
    rotate(a);
}

void rb(t_list** b) {
    rotate(b);
}

void rr(t_list** a, t_list** b) {
    rotate(a);
    rotate(b);
}

void rra(t_list** a) {
    reverse_rotate(a);
}

void rrb(t_list** b) {
    reverse_rotate(b);
}

void rrr(t_list** a, t_list** b) {
    reverse_rotate(a);
    reverse_rotate(b);
}

void presort(int *list)
{
    int i = 1;
    int temp;

    while(list[i])
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

int *check(char *av, int *list)
{
    int k = 0;
    int num = ft_atoi(av);
    //int *temp = NULL;

    while(num != list[k] && list[k])
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
    presort(sorted);
    t_list *temp = ft_lstnew(check(av[i++], sorted));
    (*a) = temp;
    while(i < ac)
    {
        temp = ft_lstnew(check(av[i++], sorted));
        ft_lstadd_back(a, temp);
    }
    i = 0;
    //algo call
    temp = (*a);
    while(temp)
    {
        printf("num : %d\n", (int)temp->content);
        temp = temp->next;
    }
    return 0;
}