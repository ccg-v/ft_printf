/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:23:46 by ccarrace          #+#    #+#             */
/*   Updated: 2022/08/23 21:58:43 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		n /= 16;
		length++;
	}
	return (length);
}

static int	ft_putptr(unsigned long n)
{
	if (n >= 16)
	{
		ft_putptr(n / 16);
		ft_putptr(n % 16);
	}
	else
	{
		if (n <= 9)
		{
			if (ft_putchar(n + '0') == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(n - 10 + 'a') == -1)
				return (-1);
		}
	}
	return (0);
}

int	ft_ptr_wrapper(unsigned long n)
{
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (n == 0)
		return (write(1, "0", 1) + 2);
	else
		ft_putptr(n);
	return (ft_ptr_len(n) + 2);
}
