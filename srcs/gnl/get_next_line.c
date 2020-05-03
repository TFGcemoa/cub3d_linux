/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:25:33 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/01 00:23:45 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fr_freeptr(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	ft_bzero(void *s, size_t n)
{
	size_t		i;

	i = 0;
	while (n--)
		((unsigned char *)s)[i++] = 0;
}

int		ft_resetbuffer(char **buff, int endline, int fd, char **line)
{
	int reset;

	reset = 0;
	if (!(*buff)[0] || endline >= 2)
	{
		ft_bzero(*buff, BUFFER_SIZE);
		if (fd < 0 || line == NULL || read(fd, *buff, BUFFER_SIZE) < 0)
			return (-1);
		(*buff)[BUFFER_SIZE] = '\0';
		reset = 1;
		if (endline == 2)
			reset = 2;
	}
	return (reset);
}

int		ft_returnfreebuff(int endline, char **buff)
{
	if (endline == 4)
	{
		if (*buff)
		{
			free(*buff);
			*buff = NULL;
		}
		return (0);
	}
	if (*buff)
	{
		free(*buff);
		*buff = NULL;
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char	*buff = NULL;
	int			endline;
	int			reset;

	if (BUFFER_SIZE < 1 || fd < 0 || line == NULL)
		return (-1);
	endline = 0;
	if (!buff)
	{
		if (!(buff = malloc((BUFFER_SIZE + 1) * sizeof(char))))
			return (-1);
		ft_bzero(buff, BUFFER_SIZE);
	}
	while (endline != 1)
	{
		if ((reset = ft_resetbuffer(&buff, endline, fd, line)) == -1)
			return (-1);
		endline = ft_get_line(buff, line, reset);
		if (endline == 4)
			return (ft_returnfreebuff(endline, &buff));
	}
	if (endline == 0)
		return (ft_returnfreebuff(endline, &buff));
	return (1);
}
