/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:22:42 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/20 13:14:42 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_mlx	map;
	t_grid	grid;

	if (ac == 2)
	{
		if (!(get_grid(&grid, &map, get_file(&grid, &map, av[1]))))
			return (0);
		map_init(&map);
		put_grid(&map, &grid);
		render_map(&map);
	}
	else
		return (destroy_fdf_int("usage: fdf [filename]\n"));
}
