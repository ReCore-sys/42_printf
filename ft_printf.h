/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 03:27:04 by kshore            #+#    #+#             */
/*   Updated: 2023/09/26 03:31:53 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"

char	*ft_itoa_base(long value, int base);
char	*itoa_hex_unsigned(size_t val);
char	*get_mem_addr(void *val);
char	*dupe_or_null(char *str);
char	*arg_to_str(va_list arg, char type, int *counter);
int		print_segment(va_list arg, char seg_type, int *counter);
int		putstr_returnsize(char *str);
int		ft_printf(const char *format, ...);
int		count_char(char *str, char c);
char	*full_upper(char *str);
