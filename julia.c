/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 21:20:06 by mgrimes           #+#    #+#             */
/*   Updated: 2017/01/12 21:20:08 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float		iterate_map(t_point seed, t_point c, int max_iterates)
{
	int i;

	i = 0;
	while (modulus_squared(seed) < 8 && i < max_iterates)
	{
		seed = c_plus(c_mult(seed, seed), c);
		i++;
	}
	return ((float)i / (float)max_iterates);
}

void	display_julia(t_point c, void *mlx, void *win)
{
	int		x;
	int		y;
	t_point	seed;
	int		max_iterates;


	max_iterates = 100;
	x = 0;
	while (x < WINWIDTH)
	{
		y = 0;
		while (y < WINHEIGHT)
		{
			seed = (t_point){4.0 * (float)x / (float)WINWIDTH - 2.0,
							-4.0 * (float)y / (float)WINHEIGHT + 2.0};
			mlx_pixel_put(mlx, win, x, y, gradient(STCOL, ENCOL,
							iterate_map(seed, c, max_iterates)));
			y++;
		}
		x++;
	}
}
