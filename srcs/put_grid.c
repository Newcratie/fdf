/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:59:56 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/15 15:57:03 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void			put_grid(t_mlx *map, t_grid *grid)
{
	t_line ln;

	x = 0;
	y = 0;
	while ()
	{
		ln.xa = x * DIS + PAD;
		ln.xb = (x + 1) * DIS + PAD;
		ln.ya = y * DIS + PAD;
		ln.yb = y * DIS + PAD;
		ln.color = COLOR_LINE;
		put_line(&ln,  map, put_pixel);
		x++;
	}
}
