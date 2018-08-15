/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:22:42 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/12 21:24:06 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_fdf(int key, t_mlx *map)
{
	if (key == 53)
	{
		free(map->grid->tab);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_image(map->mlx_ptr, map->img_ptr);
		exit(0);
	}
	return (0);
}

int		parse_fdf(t_grid *grid, t_mlx *map, char *file)
{
	char	**tab;

	if (!(tab = get_file(file)))
		return (0);
	if (!get_fdf(grid, map, tab))
		return (0);
	ft_printf("===== Grid int =======\n");
	for (int y = 0; y < grid->y; y++)
	{
		for (int x = 0; grid->x > x; x++)
			ft_printf("%d ", grid->tab[y][x]);
		ft_printf("\n");
	}
	if (!test(map, grid))
		return (0);
	ft_printf("======================\n");
	free_tab((void**)tab);
	return (1);
}

int		display_fdf(t_grid *grid, t_mlx *map)
{
	if (!map_init(map))
		return (0);
	put_fdf(map, grid);
	mlx_key_hook(map->win_ptr, exit_fdf, (void*)map);
	render_map(map);
	return (1);
}

int		fdf(char *file)
{
	t_grid	grid;
	t_mlx	map;

	init(&map, &grid);
	map.grid = &grid;
	if (!parse_fdf(&grid, &map, file))
		return (0);
	if (!display_fdf(&grid, &map))
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fdf(av[1]);
	else
		return (destroy_fdf_int("usage: fdf [filename]\n"));
}
