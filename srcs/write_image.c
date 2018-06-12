/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:27:38 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/12 21:23:51 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(t_mlx *map, int x, int y, int color)
{
	if (map->sz * (map->y + 0) > map->sz * y + (x * 4) + 3)
	{
		map->img[map->sz * y + (x * 4)] = color;
		map->img[map->sz * y + (x * 4) + 1] = color >> 8;
		map->img[map->sz * y + (x * 4) + 2] = color >> 16;
		map->img[map->sz * y + (x * 4) + 3] = 0;
	}
}

void		put_line_horizontal(t_line *ln, t_mlx *map,
		void (*f)(t_mlx *, int, int, int))
{
	f(map, ln->x, ln->y, ln->color);
	ln->e = 2 * ln->dy - ln->dx;
	ln->inc1 = 2 * (ln->dy - ln->dx);
	ln->inc2 = 2 * ln->dy;
	ln->i = 0;
	while (ln->i < ln->dx)
	{
		if (ln->e >= 0)
		{
			ln->y += ln->incy;
			ln->e += ln->inc1;
		}
		else
			ln->e += ln->inc2;
		ln->x += ln->incx;
		f(map, ln->x, ln->y, ln->color);
		ln->i++;
	}
}

void		put_line_vertical(t_line *ln, t_mlx *map,
		void (*f)(t_mlx *, int, int, int))
{
	f(map, ln->x, ln->y, ln->color);
	ln->e = 2 * ln->dx - ln->dy;
	ln->inc1 = 2 * (ln->dx - ln->dy);
	ln->inc2 = 2 * ln->dx;
	ln->i = 0;
	while (ln->i < ln->dy)
	{
		if (ln->e >= 0)
		{
			ln->x += ln->incx;
			ln->e += ln->inc1;
		}
		else
			ln->e += ln->inc2;
		ln->y += ln->incy;
		f(map, ln->x, ln->y, ln->color);
		ln->i++;
	}
}

void		put_line(t_line *ln, t_mlx *map,
		void (*f)(t_mlx *, int, int, int))
{
	ln->dx = ln->xb - ln->xa;
	ln->dy = ln->yb - ln->ya;
	if (ln->dx < 0)
		ln->dx = -ln->dx;
	if (ln->dy < 0)
		ln->dy = -ln->dy;
	ln->incx = 1;
	if (ln->xb < ln->xa)
		ln->incx = -1;
	ln->incy = 1;
	if (ln->yb < ln->ya)
		ln->incy = -1;
	ln->x = ln->xa;
	ln->y = ln->ya;
	if (ln->dx > ln->dy)
		put_line_horizontal(ln, map, f);
	else
		put_line_vertical(ln, map, f);
}
