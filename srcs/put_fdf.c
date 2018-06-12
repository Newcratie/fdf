/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:59:53 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/12 21:24:01 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			put_grid_horizon(t_mlx *map, t_grid *grid)
{
	int		x;
	int		y;
	t_line	ln;

	x = grid->cur_x;
	y = grid->cur_y;
	while (x < grid->x - 1)
	{
		ln.xa = ((x - y) * DIS) + PAD;
		ln.ya = ((x + y) * DIS_Y) - (grid->tab[y][x] * EXT) + PAD_Y;
		ln.xb = ((x - y + 1) * DIS) + PAD;
		ln.yb = ((x + y + 1) * DIS_Y) - (grid->tab[y][x + 1] * EXT) + PAD_Y;
		ln.color = COLOR_LINE;
		put_line(&ln, map, put_pixel);
		x++;
	}
}

static void			put_grid_vertical(t_mlx *map, t_grid *grid)
{
	int		x;
	int		y;
	t_line	ln;

	x = grid->cur_x;
	y = grid->cur_y;
	while (y < grid->y - 1)
	{
		ln.xa = ((x - y) * DIS) - DIS + PAD;
		ln.ya = ((x + y + 1) * DIS_Y) - (grid->tab[y + 1][x] * EXT) + PAD_Y;
		ln.xb = ((x - y + 1) * DIS) - DIS + PAD;
		ln.yb = ((y + x) * DIS_Y) - (grid->tab[y][x] * EXT) + PAD_Y;
		ln.color = COLOR_LINE;
		put_line(&ln, map, put_pixel);
		y++;
	}
}

void				put_fdf(t_mlx *map, t_grid *grid)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	grid->zoom = X / (hypot(grid->x, grid->y) * 8);
	while (y < grid->y)
	{
		put_grid_horizon(map, grid);
		grid->cur_y += 1;
		y++;
	}
	grid->cur_y = 0;
	x = 0;
	while (x < grid->x)
	{
		put_grid_vertical(map, grid);
		grid->cur_x += 1;
		x++;
	}
}
