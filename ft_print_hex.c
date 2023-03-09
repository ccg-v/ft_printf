/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:42:55 by ccarrace          #+#    #+#             */
/*   Updated: 2022/08/23 21:58:08 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int n)
{
	int	length;

	if (n == 0)
		length = 1;
	else
		length = 0;
	while (n != 0)
	{
		n /= 16;
		length++;
	}
	return (length);
}

static int	ft_hex_letter(unsigned int n, const char type)
{
	if (type == 'x')
	{
		if (ft_putchar(n - 10 + 'a') == -1)
			return (-1);
	}
	if (type == 'X')
	{
		if (ft_putchar(n - 10 + 'A') == -1)
			return (-1);
	}
	return (0);
}

int	ft_puthex(unsigned int n, const char type)
{
	if (n == 0)
	{
		if ((write(1, "0", 1)) == -1)
			return (-1);
	}
	else
	{
		if (n >= 16)
		{
			if ((ft_puthex(n / 16, type) == -1)
				|| (ft_puthex(n % 16, type) == -1))
				return (-1);
		}
		else if (n <= 9)
		{
			if (ft_putchar(n + '0') == -1)
				return (-1);
		}
		else
		{
			if (ft_hex_letter(n, type) == -1)
				return (-1);
		}
	}
	return (ft_hex_len(n));
}
