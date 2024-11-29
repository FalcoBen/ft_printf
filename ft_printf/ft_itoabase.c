/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenalla <fbenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:45:11 by fbenalla          #+#    #+#             */
/*   Updated: 2024/11/21 22:41:57 by fbenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned	int	ft_lenght(unsigned long long nb, int base)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		count++;
	}
	return (count);
}

char	*ft_itoabase(unsigned long long nb, int base, int letter)
{
	char	*str;
	char	*hex;
	int		len ;

	if (letter)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	len = ft_lenght(nb, 16);
	str = malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = hex[nb % base];
		nb /= base;
	}
	return (str);
}
