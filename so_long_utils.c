#include "so_long.h"

void ft_exit(t_vars *game)
{
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    
    ft_free_map(game);
    
    exit(0);
}

void ft_free_map(t_vars *game)
{
    int i = 0;
    
    if (game->map)
    {
        while (game->map[i])
        {
            free(game->map[i]);
            i++;
        }
        free(game->map);
    }
}

int close_window(t_vars *game)
{
    ft_exit(game);
    return (0);
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