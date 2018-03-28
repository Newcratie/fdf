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

int		fdf(char *file)
{
	t_mlx	map;
	t_grid	grid;

	if (!(get_grid(&grid, &map, get_file(&grid, &map, file))))
		return (0);
	map_init(&map);
	put_fdf(&map, &grid);
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
