/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenalla <fbenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 05:24:04 by fbenalla          #+#    #+#             */
/*   Updated: 2024/11/28 17:42:51 by fbenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_write(int fd, const void *buffer, size_t len)
{
	int	result;

	result = write(fd, buffer, len);
	if (result == -1)
		return (-1);
	return (result);
}

int	ft_specifier(char specifier, va_list args)
{
	int	result;

	if (specifier == 'c')
		result = (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		result = (ft_put_str(va_arg(args, char *)));
	else if (specifier == 'p')
		result = (ft_put_ptr(va_arg(args, void *)));
	else if (specifier == 'i' || specifier == 'd')
		result = (ft_put_decimal(va_arg(args, int)));
	else if (specifier == 'u')
		result = (ft_put_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		result = (ft_put_lhexa(va_arg(args, unsigned int)));
	else if (specifier == 'X')
		result = (ft_put_uhexa(va_arg(args, unsigned int)));
	else if (specifier == '%')
		result = (write(1, "%", 1));
	else
		return (0);
	if (result < 0)
		return (-1);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		result;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			break ;
		if (format[i] == '%' && format[i + 1])
			result = ft_specifier(format[++i], args);
		else
			result = check_write(1, &format[i], 1);
		if (result == -1)
			return (va_end(args), -1);
		count += result;
		i++;
	}
	va_end(args);
	return (count);
}
