/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:27:38 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/15 07:12:16 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(t_mlx *map, int x, int y, int color)
{
	map->img[map->sz * y + (x * 4)] = color;
	map->img[map->sz * y + (x * 4) + 1] = color >> 8;
	map->img[map->sz * y + (x * 4) + 2] = color >> 16;
	map->img[map->sz * y + (x * 4) + 3] = 0;
}
static void		put_vertical(t_line *ln, t_mlx *map, void (*f)(t_mlx *, int, int, int))
{
	int	lx;
	int	ly;
	int	x;
	int	y;
	int	cumul;

	x = ln->xa;
	y = ln->ya;
	lx = ln->xb - ln->xa;
	ly = ln->yb - ln->ya;
	f(map, x, y, ln->color);
	cumul = lx / 2;
	y = ln->ya + 1;
	while (y < ln->yb)
	{
		cumul += lx;
		if (cumul >= ly)
		{
			cumul -= ly;
			x += 1;
		}
		f(map, x, y++, ln->color);
	}
}

static void		put_horizontal(t_line *ln, t_mlx *map, void (*f)(t_mlx *, int, int, int))
{
	int	lx;
	int	ly;
	int	x;
	int	y;
	int	cumul;

	x = ln->xa;
	y = ln->ya;
	lx = ln->xb - ln->xa;
	ly = ln->yb - ln->ya;
	f(map, x, y, ln->color);
	cumul = lx / 2;
	x = ln->xa + 1;
	while (x < ln->xb)
	{
		cumul += ly;
		if (cumul >= lx)
		{
			cumul -= lx;
			y += 1;
		}
		f(map, x++, y, ln->color);
	}
}

void		put_line(t_line *ln, t_mlx *map, void (*f)(t_mlx *, int, int, int))
{
	int	lx;
	int	ly;

	lx = ln->xb - ln->xa;
	ly = ln->yb - ln->ya;
	if (lx > ly)
		put_horizontal(ln, map, f);
	else
		put_vertical(ln, map, f);
}

