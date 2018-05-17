/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:22:42 by abbenham          #+#    #+#             */
/*   Updated: 2018/05/17 17:34:59 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_fdf(int key, t_mlx *map)
{
	if (key == 53)
	{
		free(map->grid->tab);
		//free(map->grid);
		//free(map);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_image(map->mlx_ptr, map->img_ptr);
		exit(0);
	}
	return (0);
}

int		fdf(char *file)
{
	t_grid	grid;
	t_mlx	map;

	map.grid = &grid;
	if (!(get_grid(&grid, &map, get_file(&grid, &map, file))))
		return (0);
	map_init(&map);
	put_fdf(&map, &grid);
	mlx_key_hook(map.win_ptr, exit_fdf, (void*)&map);
	render_map(&map);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fdf(av[1]);
	else
		return (destroy_fdf_int("usage: fdf [filename]\n"));
}
