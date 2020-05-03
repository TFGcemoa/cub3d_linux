/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:16:55 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/02 20:16:32 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

void	setdist(t_map *map)
{
	double	calc;

	calc = 0;
	if (map->str.side == 0 || map->str.side == 2)
	{
		calc = map->str.mapx - map->str.posx + (1 - map->str.stpx) / 2;
		map->str.dist = calc / map->str.rayx;
	}
	else
	{
		calc = (map->str.mapy - map->str.posy + (1 - map->str.stpy) / 2);
		map->str.dist = calc / map->str.rayy;
	}
}

void	checkhit(t_map *map)
{
	while (map->str.hit == 0)
	{
		if (map->str.sdix < map->str.sdiy)
		{
			if (map->str.rayx >= 0)
				map->str.side = 0;
			else
				map->str.side = 2;
			map->str.sdix += map->str.delx;
			map->str.mapx += map->str.stpx;
		}
		else if (map->str.sdix >= map->str.sdiy)
		{
			if (map->str.rayy >= 0)
				map->str.side = 1;
			else
				map->str.side = 3;
			map->str.sdiy += map->str.dely;
			map->str.mapy += map->str.stpy;
		}
		if (map->map[map->str.mapx][map->str.mapy] == '1')
			map->str.hit = 1;
	}
}

void	setraymapdel(t_map *map, int x)
{
	double	camx;

	camx = 2 * x / (double)map->rx - 1;
	map->str.rayx = map->dirx + map->plax * camx;
	map->str.rayy = map->diry + map->play * camx;
	map->str.mapx = (int)map->str.posx;
	map->str.mapy = (int)map->str.posy;
	map->str.delx = fabs(1 / map->str.rayx);
	map->str.dely = fabs(1 / map->str.rayy);
	map->str.hit = 0;
}

void	setstpsdi(t_map *map)
{
	if (map->str.rayx < 0)
	{
		map->str.stpx = -1;
		map->str.sdix = (map->str.posx - map->str.mapx) * map->str.delx;
	}
	else
	{
		map->str.stpx = 1;
		map->str.sdix = (map->str.mapx + 1.0 - map->str.posx) * map->str.delx;
	}
	if (map->str.rayy < 0)
	{
		map->str.stpy = -1;
		map->str.sdiy = (map->str.posy - map->str.mapy) * map->str.dely;
	}
	else
	{
		map->str.stpy = 1;
		map->str.sdiy = (map->str.mapy + 1.0 - map->str.posy) * map->str.dely;
	}
}

int		raycasting(t_map *map)
{
	int		x;
	double	zbuffer[map->rx];

	x = 0;
	while (x < map->rx)
	{
		setraymapdel(map, x);
		setstpsdi(map);
		checkhit(map);
		setdist(map);
		setwalldraw(map);
		setratiopixel(map);
		if (x == 0)
			setbg(map);
		drawwall(map, x);
		zbuffer[x] = map->str.dist;
		x++;
	}
	if (map->numsprite > 0)
		preparesprite(map, zbuffer);
	if (map->sc == 1)
		return (screenshot(map));
	mlx_put_image_to_window(map->win->mlx, map->win->win, map->draw->img, 0, 0);
	mlx_do_sync(map->win->mlx);
	return (0);
}
