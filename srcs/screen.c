/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 00:36:16 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/12 19:21:32 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

char	*screen(t_mlx *map, int color)
{
	int		line;
	int		i;

	i = 0;
	line = 0;
	while (i < map->sz * map->y)
	{
		map->img[i] = color;
		map->img[i + 1] = color >> 8;
		map->img[i + 2] = color >> 16;
		i += 4;
		line++;
	}
	return (map->img);
}

char	*gradient(char *img, int sz, int x, int y)
{
	char	r;
	int		line;
	int		i;

	i = 0;
	r = 0;
	line = 0;
	while (i < sz * y)
	{
		if (line == sz && r != (char)255)
		{
			r += 1;
			line = 0;
		}
		img[i] = r;
		img[i + 1] = r;
		img[i + 2] = r;
		i += 4;
		line++;
	}
	return (img);
}
