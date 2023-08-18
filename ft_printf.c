/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:26:08 by kshore            #+#    #+#             */
/*   Updated: 2023/08/19 01:04:59 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

t_list	*args_to_list(va_list *args, int arg_count, bool offset)
{
	t_list	*list;
	int		i;

	if (!offset)
	{
		list = ft_lstnew(NULL);
		ft_lstadd_back(&list, ft_lstnew(va_arg(*args, void *)));
	}
	else
		list = ft_lstnew(va_arg(*args, void *));
	i = 1;
	while (i < arg_count)
	{
		ft_lstadd_back(&list, ft_lstnew(va_arg(*args, void *)));
		i++;
	}
	return (list);
}

void	print_segment(void *arg, char *segment)
{
	char	*str;

	str = arg_to_str(arg, *segment);
	segment++;
	ft_putstr_fd(ft_strjoin(str, segment), 1);
	free(str);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_list	*arg_list;
	int		i;
	t_list	*split_string;

	va_start(args, format);
	if (count_char((char *)format, '%') == 0)
	{
		(ft_putstr_fd((char *)format, 1));
		return (0);
	}
	split_string = array_to_list((void **)ft_split(format, '%'));
	arg_list = args_to_list(&args, \
	count_char((char *)format, '%'), (format[0] == '%'));
	i = 0;
	if (!(format[0] == '%'))
		ft_putstr_fd(split_string->content, ++i);
	while (ft_get(*arg_list, i) && ft_get(*split_string, i))
	{
		print_segment(ft_get(*arg_list, i)->content, \
		ft_get(*split_string, i)->content);
		i++;
	}
	va_end(args);
	return (0);
}
