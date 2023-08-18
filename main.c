/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:23:06 by kshore            #+#    #+#             */
/*   Updated: 2023/08/19 00:49:14 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("Testing: %s | %p | %d\n", "p", 7, 69);
	printf("Testing: %s | %p | %d\n", "p", (void *)7, 69);
	return (0);
}
