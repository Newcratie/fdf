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
	if (map->sz * (map->y + 1) > map->sz * y + (x * 4) + 3)
	{
		map->img[map->sz * y + (x * 4)] = color;
		map->img[map->sz * y + (x * 4) + 1] = color >> 8;
		map->img[map->sz * y + (x * 4) + 2] = color >> 16;
		map->img[map->sz * y + (x * 4) + 3] = 0;
	}
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

void		put_line(t_line *ln, t_mlx *map, void (*f)(t_mlx *, int, int, int))
{
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = ln->xb - ln->xa;
	dy = ln->yb - ln->ya;

	if(dx < 0) dx = -dx;
	if(dy < 0) dy = -dy;
	incx = 1;
	if(ln->xb < ln->xa) incx = -1;
	incy = 1;
	if(ln->yb < ln->ya) incy = -1;
	x=ln->xa;
	y=ln->ya;

	if(dx > dy)
	{
		f(map, x, y, ln->color);
		e = 2*dy - dx;
		inc1 = 2*( dy -dx);
		inc2 = 2*dy;
		for(i = 0; i < dx; i++)
		{
			if(e >= 0)
			{
				y += incy;
				e += inc1;
			}
			else e += inc2;
			x += incx;
			f(map, x, y, ln->color);
		}
	}
	else
	{
		f(map, x, y, ln->color);
		e = 2*dx - dy;
		inc1 = 2*( dx - dy);
		inc2 = 2*dx;
		for(i = 0; i < dy; i++)
		{
			if(e >= 0)
			{
				x += incx;
				e += inc1;
			}
			else e += inc2;
			y += incy;
			f(map, x, y, ln->color);
		}
	}
}


