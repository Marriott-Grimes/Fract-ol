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
#include <stdio.h>

float		iterate_map(t_point init_val, t_point c, int max_iterates)
{
	int i;

	i = 0;
	while (modulus_squared(init_val) < 4 && i < max_iterates)
	{
		init_val = c_plus(c_mult(init_val, init_val), c);
		i++;
	}
	return ((float)i / (float)max_iterates);
}

int		pixel_to_buffer(int x, int y, t_point c, int max_iterates, t_window *win_ptr)
{
	float	z;
	t_point mid;
	t_point init_val;

	z = win_ptr->zoom;
	mid = win_ptr->center;
	init_val = (t_point){(4.0 * (float)x / (float)win_ptr->wwd - 2.0) * z + mid.x,
					(-4.0 * (float)y / (float)win_ptr->wht + 2.0) * z + mid.y};
	return (gradient(STCOL, ENCOL, iterate_map(init_val, c, max_iterates)));
}

void	display_julia(t_point c, t_window *win_ptr)
{
	int		x;
	int		y;
	int		max_iterates;
	int		*image;

	max_iterates = 100;
	image = (int *)mlx_get_data_addr(win_ptr->buf, &(win_ptr->bpp),
									&(win_ptr->bytewd), &(win_ptr->endian));
	y = 0;
	while (y < WINHEIGHT)
	{
		x = 0;
		while (x < WINWIDTH)
		{
			image[x + y * WINWIDTH] = pixel_to_buffer(x, y, c, max_iterates, win_ptr);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(win_ptr->mlx, win_ptr->win, win_ptr->buf, 0, 0);
}
