/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:36:28 by kshore            #+#    #+#             */
/*   Updated: 2023/09/07 03:24:05 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include <stdarg.h>
#include <stdbool.h>

char	*ft_itoa_base(int value, int base);
char	*get_mem_addr(void *val);
char	*full_upper(char *str);
char	*arg_to_str(va_list arg, char type);
t_list	*args_to_list(va_list *args, int arg_count, bool offset);
int		print_segment(va_list arg, char seg_type);
int		ft_printf(const char *format, ...);
void	**list_to_array(t_list *list);
t_list	*array_to_list(void **array);
int		count_char(char *str, char c);
void	pretty_print_list(t_list *list);
void	multifree(void *obj1, void *obj2, void *obj3);
int		putstrreturn(char *str);
