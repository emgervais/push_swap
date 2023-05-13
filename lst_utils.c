/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:45:04 by egervais          #+#    #+#             */
/*   Updated: 2023/05/13 17:55:27 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bruh	*ft_lstlast(t_bruh *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_bruh *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_bruh	*ft_lstnew(int content)
{
	t_bruh	*a;

	a = malloc(sizeof(*a));
	if (!a)
		return (NULL);
	a->content = content;
	a->next = NULL;
	return (a);
}

void	ft_lstadd_back(t_bruh **lst, t_bruh *new)
{
	t_bruh	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}
