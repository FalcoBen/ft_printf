/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenalla <fbenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:57:39 by fbenalla          #+#    #+#             */
/*   Updated: 2024/11/28 17:54:01 by fbenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_length(int n)
{
	int	counter;

	counter = 0;
	if (n < 0)
		counter = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	char	*start;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = (ft_length(n));
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	start = str;
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (start);
}
