/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 23:21:49 by kshore            #+#    #+#             */
/*   Updated: 2023/09/26 03:51:10 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdint.h>

char	*ft_itoa_base(long value, int base)
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

char	*itoa_hex_unsigned(unsigned long val)
{
	char	*str;
	char	*hex;
	char	*tmp;

	if (!val)
		return (ft_strdup("0"));
	str = ft_strdup("");
	while (val)
	{
		hex = ft_strdup((char [2]){"0123456789abcdef"[val % 16], '\0'});
		tmp = str;
		str = ft_strjoin(hex, str);
		free(tmp);
		free(hex);
		val /= 16;
	}
	return (str);
}

char	*get_mem_addr(void *val)
{
	char	*str;
	char	*hex;
	char	*tmp;

	if (!val)
		return (ft_strdup("0x0"));
	str = ft_strdup("0x");
	hex = itoa_hex_unsigned((unsigned long)val);
	tmp = str;
	str = ft_strjoin(str, hex);
	free(tmp);
	free(hex);
	return (str);
}

char	*dupe_or_null(char *str)
{
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

char	*arg_to_str(va_list arg, char type, int *counter)
{
	char	*str;

	str = "";
	if (type == '%')
		str = ft_strdup("%");
	else if (type == 's')
		str = dupe_or_null(va_arg(arg, char *));
	else if (type == 'd' || type == 'i')
		str = ft_itoa(va_arg(arg, unsigned int));
	else if (type == 'c')
	{
		str = ft_strdup((char [2]){va_arg(arg, unsigned int), '\0'});
		if (!str[0])
			*counter += 1;
		comment("This is a nasty hack but im not doing a full rewrite at 4am");
	}
	else if (type == 'p')
		str = get_mem_addr(va_arg(arg, void *));
	else if (type == 'u')
		str = ft_itoa_base(va_arg(arg, unsigned int), 10);
	else if (type == 'x')
		str = ft_itoa_base(va_arg(arg, unsigned int), 16);
	else if (type == 'X')
		str = full_upper(ft_itoa_base(va_arg(arg, unsigned int), 16));
	return (str);
}
