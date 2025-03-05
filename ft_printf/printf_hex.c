/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:06:04 by iel-asef          #+#    #+#             */
/*   Updated: 2024/11/17 18:50:03 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex_fb(unsigned long n, char c)
{
	int		len_nbr;
	char	*base;

	len_nbr = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n == 0)
	{
		len_nbr += ft_putchar_fb('0');
		return (len_nbr);
	}
	if (n >= 16)
		len_nbr += ft_printf_hex_fb(n / 16, c);
	len_nbr += ft_putchar_fb(base[n % 16]);
	return (len_nbr);
}
