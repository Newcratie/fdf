/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:22:42 by abbenham          #+#    #+#             */
/*   Updated: 2018/03/11 04:50:29 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenGL/gl.h>
#include "libft.h"
#include "ft_printf.h"
#include "mlx.h"
#include "fdf.h"

void	ground_init(t_mlx *x)
{
	x->x = 1600;
	x->y = 700;
	x->mlx_ptr = mlx_init();
	x->win_ptr = mlx_new_window(x->mlx_ptr, x->x, x->y, "title");
	x->img_ptr = mlx_new_image(x->mlx_ptr, x->x, x->y);
	x->img = mlx_get_data_addr(x->img_ptr, &x->bpp, &x->sz, &x->endian);
}

int		main(int ac, char **av)
{
	t_mlx	x;

	ground_init(&x);
	white(x.img, x.sz, x.x, x.y);
	mlx_put_image_to_window(x.mlx_ptr, x.win_ptr, x.img_ptr, 0, 0);
	//mlx_string_put(x.mlx_ptr, x.win_ptr, 10, 10, 255, ft_itoa(sz));
	mlx_loop(x.mlx_ptr);
	//ft_printf("test\n");
	return (0);
}
