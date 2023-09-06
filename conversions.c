/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 23:21:49 by kshore            #+#    #+#             */
/*   Updated: 2023/09/07 03:11:48 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*hex;
	int		i;
	int		neg;

	if (value == 0)
		return (ft_strdup("0"));
	neg = (value < 0);
	if (neg)
		value *= -1;
	str = malloc(sizeof(char) * 33);
	if (!str)
		return (NULL);
	hex = "0123456789abcdef";
	i = 0;
	while (value)
	{
		str[i++] = hex[value % base];
		value /= base;
	}
	if (neg)
		str[i++] = '-';
	str[i] = '\0';
	return (strrev(str));
}

char	*get_mem_addr(void *val)
{
	char	*str;
	char	*hex;
	char	*tmp;

	str = ft_strdup("0x");
	hex = ft_itoa_base((int)(intptr_t)val, 16);
	tmp = str;
	str = ft_strjoin(str, hex);
	free(tmp);
	free(hex);
	return (str);
}

char	*full_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

char	*arg_to_str(va_list arg, char type)
{
	char	*str;

	if (type == 's')
		str = ft_strdup(va_arg(arg, char *));
	else if (type == 'd' || type == 'i')
		str = ft_itoa(va_arg(arg, int));
	else if (type == 'c')
		str = ft_strdup((char []){va_arg(arg, int), '\0'});
	else if (type == 'p')
		str = get_mem_addr(va_arg(arg, void *));
	else if (type == 'u')
		str = ft_itoa_base(va_arg(arg, unsigned int), 10);
	else if (type == 'x')
		str = ft_itoa_base(va_arg(arg, unsigned int), 16);
	else if (type == 'X')
		str = full_upper(ft_itoa_base(va_arg(arg, unsigned int), 16));
	else
		str = ft_strdup("");
	return (str);
}
