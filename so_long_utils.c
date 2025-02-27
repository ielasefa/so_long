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

// void ft_exit(t_vars *game)
// {
//     if (game->img_player)
//         mlx_destroy_image(game->mlx, game->img_player);
//     if (game->img_l3zwa)
//         mlx_destroy_image(game->mlx, game->img_l3zwa);
//     if (game->img_hait)
//         mlx_destroy_image(game->mlx, game->img_hait);
//     if (game->img_ard)
//         mlx_destroy_image(game->mlx, game->img_ard);
//     if (game->img_home)
//         mlx_destroy_image(game->mlx, game->img_home);
//     if (game->img_coin)
//         mlx_destroy_image(game->mlx, game->img_coin);

//     free_animation(game);
//     ft_free_map(game);
// 	if (game->win)
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 	}
// 	if (game->mlx)
// 	{
// 		mlx_destroy_display(game->mlx);
// 		free(game->mlx);
// 	}
//     exit(0);
// }

// void	ft_free_map(t_vars *game)
// {
// 	int	i;

// 	i = 0;
// 	if (game->map)
// 	{
// 		while (game->map[i])
// 		{
// 			free(game->map[i]);
// 			i++;
// 		}
// 		free(game->map);
// 	}
// }

int	close_window(t_vars *game)
{
	ft_exit(game);
	return (0);
}

// void free_animation(t_vars *game)
// {
//     int i = 0;
//     while (i < 7)
//     {
//         if (game->animation[i])
//             mlx_destroy_image(game->mlx, game->animation[i]);
//         i++;
//     }
// }

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
