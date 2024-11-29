/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenalla <fbenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 03:05:30 by fbenalla          #+#    #+#             */
/*   Updated: 2024/11/20 19:12:46 by fbenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	char	*first;

	first = dst;
	while (*src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (first);
}

char	*ft_strdup(const char *s1)
{
	size_t	l;
	char	*dest;

	l = ft_strlen(s1) + 1;
	dest = (char *)malloc(l);
	if (!dest)
		return (NULL);
	ft_strcpy(dest, s1);
	return (dest);
}
