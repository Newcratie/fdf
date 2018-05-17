/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 08:27:06 by abbenham          #+#    #+#             */
/*   Updated: 2018/05/17 17:35:39 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		destroy_fdf_int(char *str)
{
	ft_printf(str);
	return (0);
}

void	*destroy_fdf_ptr(char *str)
{
	ft_printf(str);
	return (NULL);
}
