/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:18:32 by iel-asef          #+#    #+#             */
/*   Updated: 2025/02/13 19:18:34 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	ft_strncmp(const char *s1, const char *s2, size_t n)

{
	size_t i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (!s)
		return (NULL);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i--;
	}
	return (NULL);
}

int	close_window(t_vars *game)
{
	ft_exit(game);
	return (0);
}

void	free_animation(t_vars *game)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (game->animation[i])
			mlx_destroy_image(game->mlx, game->animation[i]);
		i++;
	}
}

static int	len_itoi(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		count;
	char	*dst;

	nb = n;
	count = len_itoi(nb);
	dst = (char *)malloc(sizeof(char) * count + 1);
	if (!dst)
		return (NULL);
	dst[count] = '\0';
	if (nb == 0)
		dst[0] = '0';
	if (nb < 0)
	{
		dst[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		dst[--count] = ((nb % 10) + '0');
		nb /= 10;
	}
	return (dst);
}
