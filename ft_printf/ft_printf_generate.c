/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_generate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenalla <fbenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:35:03 by fbenalla          #+#    #+#             */
/*   Updated: 2024/11/21 23:23:11 by fbenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	result;

	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	return (1);
}

int	ft_put_str(char *str)
{
	int	result;

	if (!str)
		str = "(null)";
	result = write(1, str, ft_strlen(str));
	if (result == -1)
		return (-1);
	return (ft_strlen(str));
}

int	ft_put_decimal(int nb)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa(nb);
	if (!str)
		return (-1);
	len += write(1, str, ft_strlen(str));
	if (len == -1)
	{
		free(str);
		return (-1);
	}
	free (str);
	return (len);
}

int	ft_put_unsigned(unsigned int nb)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_uitoa(nb);
	if (!str)
	{
		return (-1);
	}
	len += write(1, str, ft_strlen(str));
	if (len == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}

int	ft_put_lhexa(unsigned int nb)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoabase(nb, 16, 0);
	if (!str)
		return (-1);
	len += write(1, str, ft_strlen(str));
	if (len == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}
