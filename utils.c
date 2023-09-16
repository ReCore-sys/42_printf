/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:43:23 by kshore            #+#    #+#             */
/*   Updated: 2023/09/16 12:14:24 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int	count_char(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
		{
			i++;
			if (*(str + 1) == c)
				str++;
		}
		str++;
	}
	return (i);
}

void	pretty_print_list(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		printf("%d: %s\n", i, (char *)list->content);
		list = list->next;
		i++;
	}
}

void	multifree(void *obj1, void *obj2, void *obj3)
{
	free(obj1);
	free(obj2);
	free(obj3);
}
