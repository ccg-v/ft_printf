/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:20:03 by ccarrace          #+#    #+#             */
/*   Updated: 2022/08/04 20:12:21 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type_conversion(va_list args, const char type)
{
	int	length;

	length = 0;
	if (type == '%')
		length += ft_putchar('%');
	if (type == 'c')
		length += ft_putchar(va_arg(args, int));
	if (type == 's')
		length += ft_putstr(va_arg(args, char *));
	if (type == 'd' || type == 'i')
		length += ft_putnbr(va_arg(args, int));
	if (type == 'u')
		length += ft_putuint(va_arg(args, unsigned int));
	if (type == 'x' || type == 'X')
		length += ft_puthex(va_arg(args, unsigned int), type);
	if (type == 'p')
		length += ft_ptr_wrapper(va_arg(args, unsigned long));
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	va_start (args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{	
			length += ft_type_conversion(args, str[++i]);
			if (length == -1)
				return (-1);
		}
		else
		{
			length += ft_putchar(str[i]);
			if (length == -1)
				return (-1);
		}
		i++;
	}
	va_end (args);
	return (length);
}
