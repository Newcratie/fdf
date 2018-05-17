/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 00:36:51 by abbenham          #+#    #+#             */
/*   Updated: 2018/05/10 15:36:02 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# define DIS 16
# define DIS_Y 9
# define ZOOM 20
# define PAD 180
# define EXT 2.3
# define COLOR_LINE 0xffffff
# define COLOR_SCREEN 0x0


typedef	struct	s_grid
{
	int		**tab;
	int		x;
	int		y;
	int		cur_x;
	int		cur_y;
}				t_grid;

typedef struct	s_line
{
	int		xa;
	int		xb;
	int		ya;
	int		yb;
	int		color;
	int		dx;
	int		dy;
	int		i;
	int		e;
	int		incx;
	int		incy;
	int		inc1;
	int		inc2;
	int		x;
	int		y;
}				t_line;

typedef struct	s_mlx
{
	char	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_grid	*grid;
	int	x;
	int	y;
	int	bpp;
	int	sz;
	int	endian;
}				t_mlx;

char		*gradient(char *img, int sz, int x, int y);
char		*screen(t_mlx *map, int color);
void		put_pixel(t_mlx *map, int x, int y, int color);
void		put_line(t_line *ln, t_mlx *map, void(*f)(t_mlx *,int, int, int));
void		put_fdf(t_mlx *map, t_grid *grid);

void		map_init(t_mlx *x);
void		render_map(t_mlx *map);

char		**get_file(t_grid *grid, t_mlx *map, char *file);
char 		**dupli_tab(char **tab, char *s, int len);

int		get_grid(t_grid *grid, t_mlx *map, char **tab);

int		destroy_fdf_int(char *str);
void		*destroy_fdf_ptr(char *str);

#endif
