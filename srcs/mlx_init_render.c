/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:04:26 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/12 21:14:45 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_init(t_mlx *x)
{
	if (!(x->mlx_ptr = mlx_init()))
		return(destroy_fdf_int("Init ml fail\n"));
	x->win_ptr = mlx_new_window(x->mlx_ptr, x->x, x->y, "title");
	x->img_ptr = mlx_new_image(x->mlx_ptr, x->x, x->y);
	x->img = mlx_get_data_addr(x->img_ptr, &x->bpp, &x->sz, &x->endian);
	screen(x, COLOR_SCREEN);
	return (1);
}

void		render_map(t_mlx *map)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	mlx_loop(map->mlx_ptr);
}
