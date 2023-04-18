/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egervais <egervais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:28:47 by egervais          #+#    #+#             */
/*   Updated: 2023/02/05 15:00:32 by egervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# define ERROR -1

int	ft_pstr(char *s);
int	ft_ppercent(void);
int	ft_printf(const char *str, ...);
int	ft_formats(va_list args, const char format);
int	ft_pptr(unsigned long long ptr);
int	ft_pchar(int c);
int	ft_strlen(const char *str);
int	ft_int(int nb);
int	ft_punsigned(unsigned int a);
int	ft_hexa(uintptr_t num, const char format);

#endif
