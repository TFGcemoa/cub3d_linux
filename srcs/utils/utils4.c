/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:37:09 by nhochstr          #+#    #+#             */
/*   Updated: 2020/04/30 18:43:47 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int		initdraw(t_draw **draw)
{
	if (!(*draw = malloc(sizeof(t_draw))))
		return (-1);
	(*draw)->drws = 0;
	(*draw)->drwe = 0;
	(*draw)->linh = 0;
	return (0);
}
