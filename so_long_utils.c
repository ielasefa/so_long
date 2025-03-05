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

void	handle_player(t_vars *game, int *play, int x, int y)
{
	(*play)++;
	game->player_x = y;
	game->player_y = x;
}
