/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 09:27:47 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/15 14:22:53 by abbenham         ###   ########.fr       */
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

	if (len != get_tablen(s))
		return (destroy_fdf_ptr("BULLishhh\n"));
	i = 0;
	intab = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		intab[i] = ft_atoi(s[i]);
		i++;
	}
	return (intab);
}

int			get_grid(t_grid *grid, t_mlx *map, char **tab)
{
	int		i;
	char 	**tmp;

	i = 0;
	if (!tab)
		return (0);
	grid->tab = (int **)malloc(sizeof(int *) * (grid->y + 1));
	grid->x = get_tablen(ft_strsplit(tab[0], ' '));
	grid->tab[grid->y] = 0;
	while (i < grid->y)
	{
		if (!(grid->tab[i] = atoi_tab(ft_strsplit(tab[i] , ' '), grid->x)))
			return (0);
		i++;
	}
	i = 0;
	while (grid->tab[0][i])
		i++;
	map->x = grid->x * ZOOM + PAD * 2;
	map->y = grid->y * ZOOM + PAD * 2;
	return (1);
}
