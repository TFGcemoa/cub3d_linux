/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:12:14 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/02 15:33:04 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"
#include "../../includes/keys.h"
#include "../../includes/cub3d.h"

int	moveplayer(t_map *map)
{
	double	movespeed;
	double	rotspeed;
	int		r;

	movespeed = 0.03;
	rotspeed = 0.02;
	r = 0;
	if (map->key.keyz == 1)
		move_front(map, movespeed);
	if (map->key.keys == 1)
		move_back(map, movespeed);
	if (map->key.keyq == 1)
		move_left(map, movespeed);
	if (map->key.keyd == 1)
		move_right(map, movespeed);
	if (map->key.keyfd == 1)
		move_cam_right(map, rotspeed);
	if (map->key.keyfg == 1)
		move_cam_left(map, rotspeed);
	if (map->key.keyz == 1 || map->key.keys == 1 || map->key.keyq == 1 ||
		map->key.keyd == 1 || map->key.keyfd == 1 || map->key.keyfg == 1)
		r = raycasting(map);
	return (r);
}

int	exit_hook(t_map *map)
{
	mlx_clear_window(map->win->mlx, map->win->win);
	mlx_destroy_window(map->win->mlx, map->win->win);
	free_all(map);
	exit(0);
	return (0);
}

int	key_press_hook(int key, t_map *map)
{
	if (key == KEY_Z)
		map->key.keyz = 1;
	if (key == KEY_S)
		map->key.keys = 1;
	if (key == KEY_Q)
		map->key.keyq = 1;
	if (key == KEY_D)
		map->key.keyd = 1;
	if (key == KEY_RIGHT)
		map->key.keyfd = 1;
	if (key == KEY_LEFT)
		map->key.keyfg = 1;
	if (key == KEY_ESCAPE)
		exit_hook(map);
	return (1);
}

int	key_release_hook(int key, t_map *map)
{
	if (key == KEY_Z)
		map->key.keyz = 0;
	if (key == KEY_S)
		map->key.keys = 0;
	if (key == KEY_Q)
		map->key.keyq = 0;
	if (key == KEY_D)
		map->key.keyd = 0;
	if (key == KEY_RIGHT)
		map->key.keyfd = 0;
	if (key == KEY_LEFT)
		map->key.keyfg = 0;
	return (1);
}
