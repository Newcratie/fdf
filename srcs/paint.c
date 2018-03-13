/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 00:36:16 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/13 16:27:18 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

char	*white(char *img, int sz, int x, int y)
{
	int		line;
	int		i;
	(void)x;

	i = 0;
	line = 0;
	while (i < sz * y)
	{
		img[i] = (char)255;
		img[i + 1] = (char)255;
		img[i + 2] = (char)255;
		i += 4;
		line++;
	}
	return (img);
}

char	*gradient(char *img, int sz, int x, int y)
{
	char	r;
	char	g;
	char 	b;
	int		line;
	int		i;
	(void)x;

	i = 0;
	r = 0;
	g = 0;
	b = 0;
	line = 0;
	while (i < sz * y)
	{
		if (line == sz && r != (char)255)
		{
			r += 1;
			g += 1;
			b += 1;
			line = 0;
		}
		img[i] = r;
		img[i + 1] = g;
		img[i + 2] = b;
		i += 4;
		line++;
	}
	return (img);
}
