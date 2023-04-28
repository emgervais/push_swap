#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include  <stdio.h>
#include "./libft/libft.h"

# define ERROR -1

typedef struct s_bruh
{
    int *data;
    struct t_bruh *next;
}   t_bruh;

typedef struct s_best
{
    int act;
    int nbr;
    int index;
}   t_best;

void sa(t_list** a);
void sb(t_list** b);
void ss(t_list** a, t_list** b);
void pa(t_list** a, t_list** b);
void pb(t_list** a, t_list** b);
void ra(t_list** a);
void rb(t_list** b);
void rr(t_list** a, t_list** b);
void rra(t_list** a);
void rrb(t_list** b);
void rrr(t_list** a, t_list** b);
void algo(t_list **a, t_list **b, t_best *best);
void algo2(t_list **a, t_list **b);
int find_index(t_list **list, int nbr);
int find_position_in_b(t_list *b, int nbr);
int rra_rrb(t_list **a, t_list **b, int nbr, int index);
int ra_rb(t_list **a, t_list **b, int nbr, int index);
int rra_rb(t_list **a, t_list **b, int nbr, int index);
int ra_rrb(t_list **a, t_list **b, int nbr, int index);
#endif

