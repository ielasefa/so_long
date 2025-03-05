/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:04:01 by iel-asef          #+#    #+#             */
/*   Updated: 2024/11/17 18:36:49 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_n(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_putnbr_fb(int n)
{
	int	count;

	count = len_n(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fb('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fb(n / 10);
		ft_putchar_fb(n % 10 + '0');
	}
	else
		ft_putchar_fb(n % 10 + '0');
	return (count);
}
