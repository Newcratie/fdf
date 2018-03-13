/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 00:36:51 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/13 16:36:00 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_mlx
{
	char	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		x;
	int		y;
	int		bpp;
	int		sz;
	int		endian;
}				t_mlx;

char	*gradient(char *img, int sz, int x, int y);
char	*white(char *img, int sz, int x, int y);
void	put_pixel(char **s, int sz, int x, int y);


#endif
