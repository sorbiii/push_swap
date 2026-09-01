/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:02:58 by nadamczy          #+#    #+#             */
/*   Updated: 2025/01/06 12:16:55 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H   
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <ctype.h>
# include <stdint.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_argument_to_print(va_list args, char *str);
int		ft_print_char(va_list args);
int		ft_print_string(va_list args);
int		ft_print_pointer(va_list args);
int		ft_print_int(va_list args);
int		ft_print_unsigned_int(va_list args);
int		ft_print_low_hex(va_list args);
int		ft_print_upp_hex(va_list args);

int		ft_print_s(char *str);
int		ft_value(int num);
int		ft_calc_digits_hex(unsigned int n);
int		ft_calc_udigits(unsigned int n);
char	*ft_utoa(unsigned int n);
int		ft_calc_digits(int i);
#endif
