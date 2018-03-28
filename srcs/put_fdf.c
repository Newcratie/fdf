/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:59:56 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/20 16:38:26 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static void			put_grid_horizon(t_mlx *map, t_grid *grid)
{
	int		x;
	int		y;
	t_line ln;

	x = grid->cur_x;
	y = grid->cur_y;
	while (x < grid->x - 1)
	{
		ln.xa = (x - y) * DIS + PAD;
		ln.ya = (x + y) * DIS + PAD;
		ln.xb = (x - y + 1) * DIS + PAD;
		ln.yb = (x + y + 1) * DIS + PAD;
		ln.color = rand();
		put_line(&ln,  map, put_pixel);
		x++;
	}
}

static void			put_grid_vertical(t_mlx *map, t_grid *grid)
{
	int		x;
	int		y;
	t_line ln;

	x = grid->cur_x;
	y = grid->cur_y;
	while (y < grid->y - 1)
	{
		ln.xa = (x - y ) * DIS + PAD;
		ln.ya = (x + y + 1 ) * DIS + PAD;
		ln.xb = (x - y + 1) * DIS + PAD;
		ln.yb = (y + x) * DIS + PAD;
		ln.color = rand();
		put_line(&ln,  map, put_pixel);
		y++;
	}
}

void			put_fdf(t_mlx *map, t_grid *grid)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
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
