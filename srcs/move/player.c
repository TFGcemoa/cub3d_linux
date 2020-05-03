/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:13:13 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/02 15:29:14 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

void	move_front(t_map *map, double ms)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = map->str.posx + map->dirx * ms;
	new_pos_y = map->str.posy + map->diry * ms;
	if (map->map[(int)new_pos_x][(int)map->str.posy] != '1')
		map->str.posx = new_pos_x;
	if (map->map[(int)map->str.posx][(int)new_pos_y] != '1')
		map->str.posy = new_pos_y;
}

void	move_back(t_map *map, double ms)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = map->str.posx - map->dirx * ms;
	new_pos_y = map->str.posy - map->diry * ms;
	if (map->map[(int)new_pos_x][((int)map->str.posy)] != '1')
		map->str.posx = new_pos_x;
	if (map->map[(int)map->str.posx][(int)new_pos_y] != '1')
		map->str.posy = new_pos_y;
}

void	move_right(t_map *map, double ms)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = map->str.posx + map->plax * ms;
	new_pos_y = map->str.posy + map->play * ms;
	if (map->map[(int)new_pos_x][(int)map->str.posy] != '1')
		map->str.posx = new_pos_x;
	if (map->map[(int)map->str.posx][(int)new_pos_y] != '1')
		map->str.posy = new_pos_y;
}

void	move_left(t_map *map, double ms)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = map->str.posx - map->plax * ms;
	new_pos_y = map->str.posy - map->play * ms;
	if (map->map[(int)new_pos_x][(int)map->str.posy] != '1')
		map->str.posx = new_pos_x;
	if (map->map[(int)map->str.posx][(int)new_pos_y] != '1')
		map->str.posy = new_pos_y;
}
