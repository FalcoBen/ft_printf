/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenalla <fbenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:33:34 by fbenalla          #+#    #+#             */
/*   Updated: 2024/11/21 23:23:25 by fbenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned	int	ft_lenght(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		count = 1;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned int nb)
{
	unsigned int	a;
	char			*str;
	int				len;

	a = nb;
	len = ft_lenght(a);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
