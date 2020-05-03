/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:40:56 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/02 18:19:24 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

void	init_s_str(t_map *map)
{
	map->str.posx = map->depx;
	map->str.posy = map->depy;
	map->str.rayx = 0;
	map->str.rayy = 0;
	map->str.sdix = 0;
	map->str.sdiy = 0;
	map->str.mapx = 0;
	map->str.mapy = 0;
	map->str.delx = 0;
	map->str.dely = 0;
	map->str.dist = 0;
	map->str.stpx = 0;
	map->str.stpy = 0;
	map->str.hit = 0;
	map->str.side = 0;
	map->str.texx = 0;
	map->str.texy = 0;
	map->str.step = 0;
	map->str.texpos = 0;
	map->str.wallx = 0;
}

void	init_s_key(t_map *map)
{
	map->key.keyz = 0;
	map->key.keys = 0;
	map->key.keyd = 0;
	map->key.keyq = 0;
	map->key.keyfd = 0;
	map->key.keyfg = 0;
}

int		init_s_draw(t_draw **draw)
{
	if (!(*draw = malloc(sizeof(t_draw))))
		return (1);
	(*draw)->drws = 0;
	(*draw)->drwe = 0;
	(*draw)->img = NULL;
	(*draw)->data = NULL;
	(*draw)->bpp = 0;
	(*draw)->sizel = 0;
	(*draw)->endian = 0;
	(*draw)->buff = NULL;
	(*draw)->linh = 0;
	return (0);
}

int		init_s_win(t_win **win)
{
	if (!(*win = malloc(sizeof(t_win))))
		return (1);
	(*win)->win = NULL;
	(*win)->mlx = NULL;
	return (0);
}

int		init_s_slist(t_map *map)
{
	int	i;
	int j;
	int num;

	i = 0;
	num = 0;
	if (!(map->slist = malloc(sizeof(t_sprite) * map->numsprite + 1)))
		return (1);
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
