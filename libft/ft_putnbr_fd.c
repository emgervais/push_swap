/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:51:17 by egervais          #+#    #+#             */
/*   Updated: 2023/01/31 12:23:36 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (nb >= 0 && nb <= 9)
			ft_putchar_fd(nb + 48, fd);
		else if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(nb * -1, fd);
		}
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbr_fd(nb % 10, fd);
		}
	}
}

//int main()
//{
//    ft_putnbr_fd(42, 1);
//}