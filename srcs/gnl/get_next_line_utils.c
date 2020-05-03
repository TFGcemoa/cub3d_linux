/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:25:15 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/01 00:23:04 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

unsigned long	ft_len(char *str, int line)
{
	unsigned long	i;

	i = 0;
	if (line == 0)
	{
		while (*str != '\0')
		{
			i++;
			str = str + 1;
		}
	}
	else
	{
		while (*str != '\0' && *str != '\n')
		{
			i++;
			str = str + 1;
		}
		if (*str == '\n')
			i++;
	}
	return (i);
}

char			*ft_del_return_line(char *str)
{
	char	*ptr;
	int		leng;
	int		i;

	i = 0;
	leng = ft_len(str, 0);
	if (!(ptr = malloc((leng) * sizeof(char))))
		return (NULL);
	while (str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	free(str);
	return (ptr);
}

char			*ft_join(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = 0;
	if (!(ptr = malloc(((ft_len(s1, 0) + ft_len(s2, 1)) + 1) * sizeof(char))))
		return (NULL);
	while (s1[++i] != '\0')
		ptr[i] = s1[i];
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
	{
		ptr[i + j] = '\n';
		j++;
	}
	ptr[i + j] = '\0';
	free(s1);
	return (ptr);
}

char			*ft_strdup(char *s)
{
	char	*ptr;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(ptr = malloc(ft_len(s, 1) * sizeof(char) + 1)))
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		ptr[i] = '\n';
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int				ft_get_line(char *buff, char **line, int reset)
{
	static char	*save = NULL;
	int			i;

	i = 0;
	if (reset > 0 && save)
	{
		free(save);
		save = NULL;
	}
	if (buff[0] == '\0' && !save)
	{
		*line = (reset == 2) ? *line : ft_strdup("\0");
		fr_freeptr(&save);
		return (4);
	}
	while (save && save[i] == buff[i] && buff[i] != '\0')
		i++;
	if (buff[i] == 0 && save[i] == 0)
		return (3);
	*line = (reset == 2) ? ft_join(*line, buff + i) : ft_strdup(buff + i);
	save = (save) ? ft_join(save, buff + i) : ft_strdup(buff + i);
	if ((*line)[ft_len(*line, 0) - 1] != '\n')
		return (2);
	*line = ft_del_return_line(*line);
	return (1);
}
