/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:57:05 by iel-asef          #+#    #+#             */
/*   Updated: 2024/11/22 16:35:31 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_fb(char c);
int	ft_putstr_fb(char *s);
int	ft_putnbr_fb(int n);
int	ft_printf_add_fb(void *ptr);
int	ft_printf_hex_fb(unsigned long n, char c);
int	ft_putnbr_ungned_fb(unsigned int nb);
#endif
