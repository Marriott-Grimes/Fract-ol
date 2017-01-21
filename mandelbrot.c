/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:18:49 by mgrimes           #+#    #+#             */
/*   Updated: 2017/01/19 15:18:51 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_mandelbrot(t_window *win_ptr)
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
			gradient(STCOL, ENCOL, iterate_map(init_val, init_val, max_iterates));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(win_ptr->mlx, win_ptr->win, win_ptr->buf, 0, 0);
}
