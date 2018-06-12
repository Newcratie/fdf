/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 09:27:47 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/12 16:36:44 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_tablen(char **s)
{
	int		tablen;

	tablen = 0;
	while (s[tablen])
		tablen++;
	return (tablen);
}

int			*atoi_tab(char **s, int len)
{
	int		*intab;
	int		tablen;
	int		i;

	i = 0;
	if (len != get_tablen(s))
		return (destroy_fdf_ptr("get fdf"));
	if (!(intab = (int *)malloc(sizeof(int) * len)))
		return (destroy_fdf_ptr("Malloc fail: atoi_tab\n"));
	while (i < len)
	{
		intab[i] = ft_atoi(s[i]);
		i++;
	}
	intab[i] = 0;
	free_tab((void**)s);
	return (intab);
}

void	init_data(t_grid *grid, t_mlx *map)
{
	map->x = (grid->x - 1) * DIS + PAD * 2;
	map->y = (grid->y - 1) * DIS + PAD * 2;
	grid->cur_x = 0;
	grid->cur_y = 0;
}

int			get_fdf(t_grid *grid, t_mlx *map, char **tab)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!tab)
		return (0);
	while (tab[grid->y])
		grid->y++;
	grid->tab = (int **)malloc(sizeof(int *) * (grid->y + 1));
	tmp = ft_strsplit(tab[0], ' ');
	grid->x = get_tablen(tmp);
	free_tab((void**)tmp);
	grid->tab[grid->y] = 0;
	while (i < grid->y)
	{
		if (!(grid->tab[i] = atoi_tab(ft_strsplit(tab[i], ' '), grid->x)))
			return (0);
		i++;
	}
	init_data(grid, map);
	return (1);
}
