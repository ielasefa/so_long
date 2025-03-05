/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:26:59 by iel-asef          #+#    #+#             */
/*   Updated: 2024/11/17 18:18:55 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr_fb(char *s)
{
	int	j;

	j = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[j] != '\0')
	{
		ft_putchar_fb(s[j]);
		j++;
	}
	return (ft_strlen(s));
}
