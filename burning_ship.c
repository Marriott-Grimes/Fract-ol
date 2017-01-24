/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 22:17:38 by mgrimes           #+#    #+#             */
/*   Updated: 2017/01/20 22:17:40 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	iterate_burning_ship(t_point init_val, t_point c, int max_iterates)
{
	int		i;
	t_point	absed;

	i = 0;
	while (modulus_squared(init_val) < 8 && i < max_iterates)
	{
		absed = (t_point){fabsf(init_val.x), fabsf(init_val.y)};
		init_val = c_plus(c_mult(absed, absed), c);
		i++;
	}
	return ((float)i / (float)max_iterates);
}

void	display_burning_ship(t_window *win_ptr)
{
	int		x;
	int		y;
	t_point init_val;
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
			init_val = scale_pt_to_window(x, y, win_ptr);
			image[x + y * WINWIDTH] =
			gradient(STCOL, ENCOL, iterate_burning_ship((t_point)
			{fabsf(init_val.x), fabsf(init_val.y)}, init_val, max_iterates));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(win_ptr->mlx, win_ptr->win, win_ptr->buf, 0, 0);
}
