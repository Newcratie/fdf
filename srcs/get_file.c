/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:36:47 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/12 19:19:26 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char			**get_file(char *file)
{
	int		i;
	int		fd;
	char	*readed;
	char	**tab;
	char	**new;

	if (-1 == (fd = open(file, O_RDONLY)))
		return (destroy_fdf_ptr("usage: fdf [filename]\n"));
	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * 1)))
		return (destroy_fdf_ptr("Malloc Fail (get_file)\n"));
	while (0 < (get_next_line(fd, &readed)))
	{
		i++;
		if (!(new = dupli_tab(tab, readed, i)))
			return (0);
		free(tab);
		tab = new;
	}
	if (i == 0)
		return (destroy_fdf_ptr("Invalid fdf\n"));
	return (tab);
}

char			**dupli_tab(char **tab, char *s, int len)
{
	char	**new;
	int		i;

	i = 0;
	if (!(new = (char **)malloc(sizeof(char *) * (len + 1))))
		return (destroy_fdf_ptr("Malloc Fail (get_file->duplitab)\n"));
	while (i < len - 1)
	{
		new[i] = tab[i];
		i++;
	}
	new[i] = s;
	new[i + 1] = 0;
	return (new);
}
