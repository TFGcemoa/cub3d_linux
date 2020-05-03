/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:14:15 by nhochstr          #+#    #+#             */
/*   Updated: 2020/04/19 20:50:33 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

void	move_cam_left(t_map *map, double rotspeed)
{
	double	olddirx;
	double	oldplanex;

	olddirx = map->dirx;
	oldplanex = map->plax;
	map->dirx = map->dirx * cos(rotspeed) - map->diry * sin(rotspeed);
	map->diry = olddirx * sin(rotspeed) + map->diry * cos(rotspeed);
	map->plax = map->plax * cos(rotspeed) - map->play * sin(rotspeed);
	map->play = oldplanex * sin(rotspeed) + map->play * cos(rotspeed);
}

void	move_cam_right(t_map *map, double rotspeed)
{
	double	olddirx;
	double	oldplanex;

	olddirx = map->dirx;
	oldplanex = map->plax;
	map->dirx = map->dirx * cos(-rotspeed) - map->diry * sin(-rotspeed);
	map->diry = olddirx * sin(-rotspeed) + map->diry * cos(-rotspeed);
	map->plax = map->plax * cos(-rotspeed) - map->play * sin(-rotspeed);
	map->play = oldplanex * sin(-rotspeed) + map->play * cos(-rotspeed);
}
