/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenalla <fbenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:35:20 by fbenalla          #+#    #+#             */
/*   Updated: 2024/11/28 17:50:49 by fbenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_specifier(char specifier, va_list args);
int		ft_putchar(char c);
int		ft_put_str(char *str);
int		ft_put_unsigned(unsigned int nb);
int		ft_put_ptr(void *ptr);
int		ft_put_decimal(int nb);
int		ft_put_uhexa(unsigned int nb);
int		ft_put_lhexa(unsigned int nb);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int nb);
char	*ft_itoabase(unsigned long long nb, int base, int letter);
char	*ft_strdup(const char *s1);

#endif