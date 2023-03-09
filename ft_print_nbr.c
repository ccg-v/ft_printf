/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:57:13 by ccarrace          #+#    #+#             */
/*   Updated: 2022/08/23 21:58:25 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len(int n)
{
	int	length;

	if (n <= 0)
		length = 1;
	else
		length = 0;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

int	ft_putnbr(int n)
{
	if (n == INT_MIN)
	{
		if (ft_putstr("-2147483648") == -1)
			return (-1);
		return (11);
	}
	else if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		ft_putnbr(-n);
	}
	else
	{
		if (n >= 10)
			if (ft_putnbr(n / 10) == -1)
				return (-1);
		if (ft_putchar(n % 10 + '0') == -1)
			return (-1);
	}
	return (ft_nbr_len(n));
}
