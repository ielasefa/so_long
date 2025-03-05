/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:10:09 by iel-asef          #+#    #+#             */
/*   Updated: 2024/11/17 18:56:21 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_add_fb(void *ptr)
{
	int				len;
	unsigned long	n;

	n = (unsigned long)ptr;
	len = 0;
	if (n == 0)
	{
		ft_putstr_fb("0x0");
		return (3);
	}
	ft_putstr_fb("0x");
	len += ft_printf_hex_fb(n, 'x') + 2;
	return (len);
}
