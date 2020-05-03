/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:25:43 by nhochstr          #+#    #+#             */
/*   Updated: 2020/04/30 21:01:24 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

void	sortsprites(int *order, double *dist, int amount)
{
	int			i;
	int			j;
	double		sprites[amount];

	i = -1;
	while (++i < amount)
		sprites[i] = dist[i];
	ft_sort_int_tab(sprites, amount);
	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount)
		{
			if (dist[j] == sprites[i])
			{
				order[i] = j;
				j = amount;
			}
			j++;
		}
		i++;
	}
}

void	classsprite(t_map *map, int *o, double *d)
{
	double	a;
	double	b;
	int		i;

	i = 0;
	while (i < map->numsprite)
	{
		o[i] = i;
		a = (map->str.posx - map->slist[i].x) *
		(map->str.posx - map->slist[i].x);
		b = (map->str.posy - map->slist[i].y) *
		(map->str.posy - map->slist[i].y);
		d[i++] = (a + b);
	}
}

void	castsprite(t_map *map, double *zbuffer)
{
	int			spriteorder[map->numsprite];
	double		spritedistance[map->numsprite];
	int			i;
	t_paramspt	spt;

	classsprite(map, spriteorder, spritedistance);
	sortsprites(spriteorder, spritedistance, map->numsprite);
	i = 0;
	while (i < map->numsprite)
	{
		spt.sptx = map->slist[spriteorder[i]].x - map->str.posx;
		spt.spty = map->slist[spriteorder[i]].y - map->str.posy;
		calculsprite(map, &spt);
		drawsprite(map, &spt, zbuffer);
		i++;
	}
}

int		set_sprites(t_map *map)
{
	int	i;
	int j;
	int num;

	i = 0;
	num = 0;
	if (!(map->slist = malloc(sizeof(t_sprite) * map->numsprite + 1)))
		return (-1);
	while (num < map->numsprite && map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '2')
			{
				map->slist[num].x = i + 0.5;
				map->slist[num].y = j + 0.5;
				num++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		preparesprite(t_map *map, double *zbuffer)
{
	if (map->numsprite <= 0)
		return (0);
	castsprite(map, zbuffer);
	return (0);
}
