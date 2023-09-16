/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:26:08 by kshore            #+#    #+#             */
/*   Updated: 2023/09/16 13:33:32 by kshore           ###   ########.fr       */
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
	return (ft_strlen(str));
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
			size += print_segment(args, format[++i]);
		else
		{
			ft_putchar_fd(format[i], 1);
			size++;
		}
		i++;
	}
	return (size);
}

#if do_exe

int	main(void)
{
	printf("Intended:\n");
	printf("%p", "");
	printf("\nActual:\n");
	ft_printf("%p", "");
	return (0);
}

#endif