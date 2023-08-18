/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:36:28 by kshore            #+#    #+#             */
/*   Updated: 2023/08/19 01:41:00 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include <stdarg.h>
#include <stdbool.h>

char	*ft_itoa_base(int value, int base);
char	*get_mem_addr(void *val);
char	*full_upper(char *str);
char	*arg_to_str(void *arg, char type);
t_list	*args_to_list(va_list *args, int arg_count, bool offset);
void	print_segment(void *arg, char *segment);
int		ft_printf(const char *format, ...);
void	**list_to_array(t_list *list);
t_list	*array_to_list(void **array);
int		count_char(char *str, char c);
void	pretty_print_list(t_list *list);
