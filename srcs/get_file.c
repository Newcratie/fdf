/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:36:47 by abbenham          #+#    #+#             */
/*   Updated: 2018/05/10 17:05:54 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		parsing_fdf(t_grid *grid, t_mlx *map, char **tab)
{
	int		len;
	int		y;

	y = 0;
	len = ft_strlen(tab[y]);
	while (tab[y])
	{
		if (len != ft_strlen(tab[y]))
			return (destroy_fdf_int("Found wrong line length. Exiting.\n"));
		y++;
	}
	grid->y = y;
	return (1);
}

char			**get_file(t_grid *grid, t_mlx *map, char *file)
{
	int		i;
	int		fd;
	char	*readed;
	char	**tab;

	if (-1 == (fd = open(file, O_RDONLY)))
		return (destroy_fdf_ptr("usage: fdf [filename]\n"));
	i = 0;
	while (0 < (get_next_line(fd, &readed)))
	{
		i++;
		tab = dupli_tab(tab, readed, i);
	}
	i = 0;
	if (!parsing_fdf(grid, map, tab))
		return (NULL);
	return (tab);
}

char			**dupli_tab(char **tab, char *s, int len)
{
	char	**new;
	int		i;

	i = 0;
	new = (char **)malloc(sizeof(char *) * (len + 1));
	while (i < len - 1)
	{
		new[i] = tab[i];
		i++;
	}
	new[i] = s;
	return (new);
}
