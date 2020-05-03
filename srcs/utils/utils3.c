/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:51:38 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/01 00:15:51 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

void	setcorrpitch(char *corrpitch)
{
	corrpitch[0] = 0;
	corrpitch[1] = 3;
	corrpitch[2] = 2;
	corrpitch[3] = 1;
}

void	ft_bzero_sc(void *s, size_t n)
{
	size_t		i;

	i = 0;
	while (n--)
		((unsigned char *)s)[i++] = 0;
}

void	*ft_calloc_sc(size_t count, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(count * size)))
		return (NULL);
	ft_bzero_sc(ptr, count * size);
	return (ptr);
}

void	set_res(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_get_screen_size(map->win->mlx, &x, &y);
	if (map->rx > x)
		map->rx = x;
	if (map->ry > y)
		map->ry = y;
}

int		free_null(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (-1);
}
