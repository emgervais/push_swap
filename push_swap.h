#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define ERROR -1

typedef struct s_bruh
{
    int content;
    struct s_bruh *next;
}   t_bruh;

typedef struct s_best
{
    int act;
    int nbr;
    int index;
}   t_best;

typedef struct s_list
{
    int pos;
    long nbr;
    struct s_list *next;
    struct s_list *back;
} t_list;

void reverse_rotate(t_bruh** top);
void rotate(t_bruh** top);
void push_other(t_bruh** dest, t_bruh** src);
void swap(t_bruh** top);
int  pop(t_bruh** top);
int push(t_bruh** top, int data);

void sa(t_bruh** a);
void sb(t_bruh** b);
void ss(t_bruh** a, t_bruh** b);
void pa(t_bruh** a, t_bruh** b);
void pb(t_bruh** a, t_bruh** b);
void ra(t_bruh** a);
void rb(t_bruh** b);
void rr(t_bruh** a, t_bruh** b);
void rra(t_bruh** a);
void rrb(t_bruh** b);
void rrr(t_bruh** a, t_bruh** b);

void algo(t_bruh **a, t_bruh **b, t_best *best);
void algo2(t_bruh **a, t_bruh **b);
void algoa1(t_bruh **a, t_bruh **b, t_best *best);
void algoa2(t_bruh **a, t_bruh **b);
void tinynbr(t_bruh **a);
void finish(t_bruh **a);
void two_nbr(t_bruh **a);

int b_rra_rrb(t_bruh **a, t_bruh **b, int nbr, int index);
int b_ra_rb(t_bruh **b, int nbr, int index);
int b_rra_rb(t_bruh **a, t_bruh **b, int nbr, int index);
int b_ra_rrb(t_bruh **b, int nbr, int index);
int a_rra_rrb(t_bruh **a, t_bruh **b, int nbr, int index);
int a_ra_rb(t_bruh **a, int nbr, int index);
int a_rra_rb(t_bruh **a, int nbr, int index);
int a_ra_rrb(t_bruh **a, t_bruh **b, int nbr, int index);

void apply_rra_rrb_b(t_bruh **a, t_bruh **b, int nbr);
void apply_ra_rb_b(t_bruh **a, t_bruh **b, int nbr);
void apply_ra_rrb_b(t_bruh **a, t_bruh **b, int nbr);
void apply_rra_rb_b(t_bruh **a, t_bruh **b, int nbr);
void apply_rra_rrb_a(t_bruh **a, t_bruh **b, int nbr);
void apply_ra_rb_a(t_bruh **a, t_bruh **b, int nbr);
void apply_ra_rrb_a(t_bruh **a, t_bruh **b, int nbr);
void apply_rra_rb_a(t_bruh **a, t_bruh **b, int nbr);

int find_max(t_bruh *list);
int find_min(t_bruh *list);
int find_position_in_b(t_bruh *b, int nbr);
int find_position_in_a(t_bruh *a, int nbr);
int find_index(t_bruh **list, int nbr);

t_bruh	*ft_lstlast(t_bruh *lst);
int	ft_lstsize(t_bruh *lst);
t_bruh	*ft_lstnew(int content);
void	ft_lstadd_back(t_bruh **lst, t_bruh *new);

char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_count_word(char const *s, char c);

void free_list(t_bruh **a, t_bruh **b, int error);
void ft_freee(t_bruh **a, t_bruh **b);
int ft_clear(t_list *first);

void redirect(int size, t_bruh **a, t_bruh **b);
#endif

