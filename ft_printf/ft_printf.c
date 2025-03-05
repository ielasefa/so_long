/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:31:26 by iel-asef          #+#    #+#             */
/*   Updated: 2024/11/17 21:30:21 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_fb(const char format, va_list args)

{
	int	len;

	len = 0;
	if (format == 'd' || format == 'i')
		len += ft_putnbr_fb(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr_fb(va_arg(args, char *));
	else if (format == 'c')
		len += ft_putchar_fb(va_arg(args, int));
	else if (format == 'X' || format == 'x')
		len += ft_printf_hex_fb(va_arg(args, unsigned int), format);
	else if (format == 'p')
		len += ft_printf_add_fb(va_arg(args, void *));
	else if (format == 'u')
		len += ft_putnbr_ungned_fb(va_arg(args, unsigned int));
	else
		len += ft_putchar_fb(format);
	return (len);
}

int	ft_printf(const char *format, ...)

{
	int		len;
	int		i;
	va_list	args;

	len = 0;
	i = 0;
	if (!format || write(1, 0, 0) == -1)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				len += print_fb(format[i + 1], args);
			i++;
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
