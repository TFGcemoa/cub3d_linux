/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:32:17 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/07 21:44:57 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int		free_path(t_map *map)
{
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->ea)
		free(map->ea);
	if (map->we)
		free(map->we);
	if (map->s)
		free(map->s);
	if (map->error)
		free(map->error);
	map->no = NULL;
	map->so = NULL;
	map->ea = NULL;
	map->we = NULL;
	map->s = NULL;
	map->error = NULL;
	return (-1);
}

int		free_map(t_map *map)
{
	int size;
	int	i;

	size = map->numl + 1;
	i = 0;
	if (!map->map)
	{
		map->error = ft_strjoins1(map->error, "Mauvaise carte\n");
		return (-1);
	}
	while (i < size)
	{
		if (map->map[i])
			free(map->map[i]);
		map->map[i] = NULL;
		i++;
	}
	if (map->map)
		free(map->map);
	map->map = NULL;
	map->error = ft_strjoins1(map->error, "Mauvaise carte\n");
	return (-1);
}

void	free_all2(t_map *map)
{
	if (map->draw)
		free(map->draw);
	map->draw = NULL;
	if (map->slist)
		free(map->slist);
	map->slist = NULL;
	if (map->win->mlx)
		free(map->win->mlx);
	map->win->mlx = NULL;
	if (map->win)
		free(map->win);
	map->win = NULL;
}

int		free_all(t_map *map)
{
	mlx_destroy_image(map->win->mlx, map->draw->img);
	mlx_destroy_image(map->win->mlx, map->text_no->img);
	mlx_destroy_image(map->win->mlx, map->text_so->img);
	mlx_destroy_image(map->win->mlx, map->text_ea->img);
	mlx_destroy_image(map->win->mlx, map->text_we->img);
	mlx_destroy_image(map->win->mlx, map->text_s->img);
	if (map->text_no)
		free(map->text_no);
	map->text_no = NULL;
	if (map->text_so)
		free(map->text_so);
	map->text_so = NULL;
	if (map->text_ea)
		free(map->text_ea);
	map->text_ea = NULL;
	if (map->text_we)
		free(map->text_we);
	map->text_we = NULL;
	if (map->text_s)
		free(map->text_s);
	map->text_s = NULL;
	free_path(map);
	free_map_end(map);
	free_all2(map);
	return (-1);
}

int		free_opencub(t_map *map)
{
	free_path(map);
	free_map(map);
	return (-2);
}
