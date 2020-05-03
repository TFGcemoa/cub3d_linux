/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:21:29 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/02 20:15:21 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

void	setwalldraw(t_map *map)
{
	map->draw->linh = (int)(map->ry / map->str.dist);
	map->draw->drws = -map->draw->linh / 2 + map->ry / 2;
	if (map->draw->drws < 0)
		map->draw->drws = 0;
	map->draw->drwe = map->draw->linh / 2 + map->ry / 2;
	if (map->draw->drwe >= map->ry)
		map->draw->drwe = map->ry - 1;
}

void	setratiopixel(t_map *map)
{
	if (map->str.side == 0 || map->str.side == 2)
		map->str.wallx = map->str.posy + map->str.dist * map->str.rayy;
	else
		map->str.wallx = map->str.posx + map->str.dist * map->str.rayx;
	map->str.wallx -= (int)map->str.wallx;
}

void	setbg(t_map *map)
{
	int skysize;
	int y;
	int x;

	skysize = map->ry / 2;
	x = 0;
	while (x < map->rx)
	{
		y = 0;
		while (y < map->ry)
		{
			map->draw->buff = map->draw->data + (y * map->draw->sizel) +
			(x * (map->draw->bpp / 8));
			if (y < skysize)
				*(unsigned int*)map->draw->buff = map->c;
			else
				*(unsigned int*)map->draw->buff = map->f;
			y++;
		}
		x++;
	}
}

char	*set_color(t_map *map, t_text *t)
{
	char	*color;

	if (map->str.step == -1)
	{
		map->str.step = 1.0 * t->y / map->draw->linh;
		map->str.texpos = (map->draw->drws - map->ry / 2 + map->draw->linh / 2)
		* map->str.step;
		map->str.texx = (int)(map->str.wallx * (double)t->x);
		if ((map->str.side == 0 || map->str.side == 2) && map->str.rayx > 0)
			map->str.texx = t->x - map->str.texx - 1;
		if ((map->str.side == 1) && map->str.rayy < 0)
			map->str.texx = t->x - map->str.texx - 1;
	}
	map->str.texy = (int)map->str.texpos;
	color = t->data + (map->str.texy * t->sizel + map->str.texx * (t->bpp / 8));
	return (color);
}

void	drawwall(t_map *map, int x)
{
	int		y;
	char	*color;

	map->str.step = -1;
	y = map->draw->drws - 1;
	while (++y < map->draw->drwe)
	{
		if (map->str.side == 0)
			color = set_color(map, map->text_so);
		else if (map->str.side == 1)
			color = set_color(map, map->text_ea);
		else if (map->str.side == 2)
			color = set_color(map, map->text_no);
		else
			color = set_color(map, map->text_we);
		map->draw->buff = map->draw->data + (y * map->draw->sizel) +
		(x * (map->draw->bpp / 8));
		*(unsigned int*)map->draw->buff = *(unsigned int*)color;
		map->str.texpos += map->str.step;
	}
}
