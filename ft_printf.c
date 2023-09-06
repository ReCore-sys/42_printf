/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:26:08 by kshore            #+#    #+#             */
/*   Updated: 2023/09/07 03:29:28 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int	print_segment(va_list arg, char seg_type)
{
	char	*str;
	int		size;

	str = arg_to_str(arg, seg_type);
	ft_putstr_fd(str, 1);
	size = ft_strlen(str);
	free(str);
	return (size);
}

int	putstr_returnsize(char *str)
{
	ft_putstr_fd(str, 1);
	if (str[0] == '%')
		return (1);
	return (ft_strlen(str) - 1);
}

// A wrapper around putstr so we can return 0 and save lines in ft_printf
int	putstrreturn(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		size;

	va_start(args, format);
	i = 0;
	size = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i++ + 1] == '%')
			{
				size += putstr_returnsize("%");
				i++;
			}
			else
				size += print_segment(args, format[i++]);
		}
		else
			size += putstr_returnsize((char *)&format[i++]);
	}
	return (size);
}

#if do_exe

int	main(void)
{
	ft_printf("%c", '0');
	return (0);
}

#endif