/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:43:23 by kshore            #+#    #+#             */
/*   Updated: 2023/09/26 03:26:09 by kshore           ###   ########.fr       */
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
