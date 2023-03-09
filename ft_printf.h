/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:24:45 by ccarrace          #+#    #+#             */
/*   Updated: 2022/08/02 22:13:14 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_nbr_len(int n);
int	ft_putnbr(int n);
int	ft_putuint(unsigned int n);
int	ft_puthex(unsigned int n, const char type);
int	ft_ptr_wrapper(unsigned long n);
int	ft_printf(const char *str, ...);

#endif
