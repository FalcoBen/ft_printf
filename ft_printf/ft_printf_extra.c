/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenalla <fbenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:45:23 by fbenalla          #+#    #+#             */
/*   Updated: 2024/11/21 23:22:57 by fbenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_uhexa(unsigned int nb)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoabase(nb, 16, 1);
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

int	ft_put_ptr(void *ptr)
{
	char	*buffer;
	int		len;

	len = 0;
	if (ptr == NULL)
	{
		len += write(1, "0x0", 3);
		if (len == -1)
			return (-1);
		return (len);
	}
	buffer = ft_itoabase((unsigned long long)ptr, 16, 0);
	if (!buffer)
		return (-1);
	len += write(1, "0x", 2);
	if (len == -1)
	{
		free(buffer);
		return (-1);
	}
	len += write(1, buffer, ft_strlen(buffer));
	if (len == -1)
		return (-1);
	free(buffer);
	return (len);
}
