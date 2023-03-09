/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:55:00 by ccarrace          #+#    #+#             */
/*   Updated: 2022/08/23 21:59:05 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_uint_len(unsigned int n)
{
	int	length;

	if (n == 0)
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

int	ft_putuint(unsigned int n)
{
	if (n >= 10)
		if (ft_putuint(n / 10) == -1)
			return (-1);
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (ft_uint_len(n));
}
