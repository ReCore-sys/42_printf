/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:43:23 by kshore            #+#    #+#             */
/*   Updated: 2023/09/07 02:26:48 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void	**list_to_array(t_list *list)
{
	void	**array;
	int		i;

	array = malloc(sizeof(void *) * (ft_lstsize(list) + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (list)
	{
		array[i] = list->content;
		list = list->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}

t_list	*array_to_list(void **array)
{
	t_list	*list;
	int		i;

	list = NULL;
	i = 0;
	while (array[i])
	{
		ft_lstadd_back(&list, ft_lstnew(array[i]));
		i++;
	}
	return (list);
}

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
