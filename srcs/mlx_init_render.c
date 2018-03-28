/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:12:58 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/15 11:37:12 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		map_init(t_mlx *x)
{
	x->mlx_ptr = mlx_init();
	x->win_ptr = mlx_new_window(x->mlx_ptr, x->x, x->y, "title");
	x->img_ptr = mlx_new_image(x->mlx_ptr, x->x, x->y);
	x->img = mlx_get_data_addr(x->img_ptr, &x->bpp, &x->sz, &x->endian);
	screen(x, COLOR_SCREEN);
}


void		render_map(t_mlx *map)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 10, 255, ft_itoa(map->sz));
	mlx_loop(map->mlx_ptr);
}
