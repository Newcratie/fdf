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
		ln.xa = x * DIS + PAD;
		ln.xb = (x + 1) * DIS + PAD;
		ln.ya = y * DIS + PAD;
		ln.yb = y * DIS + PAD;
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
	/*
	while (x < grid->x - 1)
	{
		ln.xa = x * DIS + PAD;
		ln.xb = (x + 1) * DIS + PAD;
		ln.ya = y * DIS + PAD;
		ln.yb = y * DIS + PAD;
		ln.color = rand();
		put_line(&ln,  map, put_pixel);
		x++;
	}
	*/
}

void			put_grid(t_mlx *map, t_grid *grid)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < grid->y - 1)
	{
		put_grid_horizon(map, grid);
		grid->cur_y += 1;
		y++;
	}
	while (x < grid->x - 1)
	{
		put_grid_vertical(map, grid);
		grid->cur_x += 1;
		x++;
	}
}
