/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:44:18 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/08 16:32:39 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

char	*colorrgb_to_hexa(int nbr)
{
	char	*color;
	int		k;
	int		res;

	k = 1;
	if (!(color = ft_calloc(sizeof(char), 3)))
		return (NULL);
	while (k >= 0 && nbr >= 16)
	{
		res = nbr % 16;
		nbr = nbr / 16;
		if (res <= 9)
			color[k--] = res + 48;
		else
			color[k--] = res + 55;
	}
	if (nbr <= 9 && nbr > 0 && nbr < 16 && k >= 0)
		color[k--] = nbr + 48;
	else if (nbr > 0 && nbr < 16 && k >= 0)
		color[k--] = nbr + 55;
	while (k >= 0)
		color[k--] = '0';
	return (color);
}

int		rgbhex_to_int(char *hex)
{
	int leng;
	int total;
	int i;

	leng = ft_strlen(hex) - 1;
	total = 0;
	i = 1;
	if (leng != 5)
		return (-1);
	while (leng >= 0)
	{
		if (hex[leng] >= '0' && hex[leng] <= '9')
			total = total + (hex[leng] - 48) * i;
		else if (hex[leng] >= 'A' && hex[leng] <= 'F')
			total = total + (hex[leng] - 55) * i;
		else
			return (-1);
		leng--;
		i = i * 16;
	}
	return (total);
}

int		rgb_to_int(int r, int g, int b)
{
	char	*hexr;
	char	*hexg;
	char	*hexb;
	char	*hex;
	int		dec;

	hexr = colorrgb_to_hexa(r);
	hexg = colorrgb_to_hexa(g);
	hexb = colorrgb_to_hexa(b);
	if (!hexr || !hexg || !hexb)
	{
		freergb(&hexr, &hexg, &hexb);
		return (-1);
	}
	if (!(hex = ft_strdup(hexr)))
		return (-1);
	hex = ft_strjoins1(hex, hexg);
	hex = ft_strjoins1(hex, hexb);
	freergb(&hexr, &hexg, &hexb);
	if (!hex)
		return (-1);
	dec = rgbhex_to_int(hex);
	free(hex);
	return (dec);
}

int		go_to_next_rgb(char *line, int i)
{
	while (ft_isdigit(line[i]) == 1 && line[i] != 0)
		i++;
	while (ft_isspace(line[i]) == 1 && line[i] != 0)
		i++;
	if (line[i] == ',' && line[i] != 0)
		i++;
	else
		return (-1);
	while (ft_isspace(line[i]) == 1 && line[i] != 0)
		i++;
	return (i);
}

int		getrgb(char *line, int i)
{
	int rgb[3];

	rgb[1] = -1;
	rgb[2] = -1;
	rgb[0] = ft_atoi(line + i);
	if ((i = go_to_next_rgb(line, i)) == -1)
		return (-1);
	if (ft_isdigit(line[i]) == 1)
		rgb[1] = (ft_isdigit(line[i]) == 1) ? ft_atoi(line + i) : rgb[1];
	if ((i = go_to_next_rgb(line, i)) == -1)
		return (-1);
	if (ft_isdigit(line[i]) == 1)
		rgb[2] = ft_atoi(line + i);
	if (ft_verif_rgb(rgb[0], rgb[1], rgb[2]) == -1)
		return (-1);
	while (ft_isdigit(line[i]) == 1 && line[i] != 0)
		i++;
	while (ft_isspace(line[i]) == 1 && line[i] != 0)
		i++;
	if (line[i] != '\0')
		return (-1);
	return (rgb_to_int(rgb[0], rgb[1], rgb[2]));
}
