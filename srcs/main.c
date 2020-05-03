/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:00:32 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/02 20:17:01 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/struct.h"

int	main(int argc, char const *argv[])
{
	t_map	map;

	if (argc < 2)
	{
		write(1, "Error\nPas d'arguments\n", 22);
		return (0);
	}
	if (parsing((char *)argv[1], &map) == -1)
		return (0);
	if (init_struc(&map) != 0)
		return (free_all(&map));
	map.win->mlx = mlx_init();
	map.draw->img = mlx_new_image(map.win->mlx, map.rx, map.ry);
	set_texture(&map);
	if (argc >= 3 && (isscreenshot(&map, (char *)argv[2], "--save")) == 1)
		return (0);
	map.win->win = mlx_new_window(map.win->mlx, map.rx, map.ry, "Cube3D");
	raycasting(&map);
	mlx_expose_hook(map.win->win, raycasting, &map);
	mlx_loop_hook(map.win->mlx, moveplayer, &map);
	mlx_hook(map.win->win, 2, 1, key_press_hook, &map);
	mlx_hook(map.win->win, 3, 2, key_release_hook, &map);
	mlx_hook(map.win->win, 33, 0, exit_hook, &map);
	mlx_loop(map.win->mlx);
	return (0);
}
