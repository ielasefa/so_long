/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:36:24 by iel-asef          #+#    #+#             */
/*   Updated: 2024/11/17 18:18:06 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_n(unsigned int n)

{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_putnbr_ungned_fb(unsigned int nb)

{
	int	count;

	count = len_n(nb);
	if (nb > 9)
	{
		ft_putnbr_ungned_fb(nb / 10);
		ft_putchar_fb(nb % 10 + '0');
	}
	else
		ft_putchar_fb(nb % 10 + '0');
	return (count);
}
