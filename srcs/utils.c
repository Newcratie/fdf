/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:14:48 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/12 21:21:23 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		init(t_mlx *map, t_grid *grid)
{
	grid->x = 0;
	grid->y = 0;
	return (1);
}

int		test(t_mlx *map, t_grid *grid)
{
	if (grid->x < 2 || grid->y < 2)
		return (destroy_fdf_int("Invalid fdf\n"));
	return (1);
}
