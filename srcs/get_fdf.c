/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 09:27:47 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/12 19:54:55 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			get_tablen(char **s)
{
	int		tablen;

	tablen = 0;
	while (s[tablen])
	{
		tablen++;
	}
	return (tablen);
}

static int			*atoi_tab(char **s, int len)
{
	int		*intab;
	int		tablen;
	int		i;

	i = 0;
	if (len != get_tablen(s))
		return (destroy_fdf_ptr("Invalid fdf\n"));
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

static void			init_data(t_grid *grid, t_mlx *map)
{
	map->y = Y;
	map->x = X;
	grid->cur_x = 0;
	grid->cur_y = 0;
}

int					get_fdf(t_grid *grid, t_mlx *map, char **tab)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!tab[0])
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
