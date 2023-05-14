/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:35:03 by egervais          #+#    #+#             */
/*   Updated: 2023/05/13 18:56:52 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_l(char **a)
{
	int	i;

	i = 0;
	while (a[i])
		free(a[i++]);
	free(a);
}

static void	parsing_arg(t_bruh **a, t_bruh **b, char **av, int ac)
{
	long	*sorted;
	t_list	*nums;

	if (!(*a)->pars)
	{
		av++;
		av[ac] = NULL;
	}
	nums = malloc(sizeof(t_list));
	sorted = malloc(sizeof(long) * (ac + 1));
	if (!sorted || nums_valid(av) || fill_arg(sorted, av, nums)
		|| sort_list(nums, sorted, ac) || init_a(a, nums))
	{
		if ((*a)->pars)
			free_l(av);
		free(sorted);
		ft_clear(nums);
		free_list(a, b, 1);
	}
	ft_clear(nums);
}

static void	parsing_str(t_bruh **a, t_bruh **b, char *av)
{
	char	**list;
	int		i;

	(*a)->pars = 1;
	list = ft_split(av, ' ');
	if (!list)
		ft_freee(a, b);
	i = 0;
	while (list[i])
		i++;
	parsing_arg(a, b, list, i);
}

static void	init_var(t_bruh **a, t_bruh **b)
{
	(*a)->pars = 0;
	(*a)->next = NULL;
	(*b) = NULL;
}

int	main(int ac, char **av)
{
	t_bruh	**a;
	t_bruh	**b;

	if (ac < 2)
		return (1);
	if(!av[1][0])
		return (0);
	a = malloc(sizeof(t_bruh **));
	(*a) = malloc(sizeof(t_bruh));
	b = malloc(sizeof(t_bruh **));
	if (!a || !b || !*a)
		ft_freee(a, b);
	init_var(a, b);
	if (ac == 2)
		parsing_str(a, b, av[1]);
	else
		parsing_arg(a, b, av, ac - 1);
	redirect(ft_lstsize(*a), a, b);
	free_list(a, b, 0);
	return (0);
}
