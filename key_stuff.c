/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:05:13 by mgrimes           #+#    #+#             */
/*   Updated: 2017/01/03 12:05:15 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_stuff(int keycode, void *param)
{
	t_window *win_ptr;

	win_ptr = (t_window *)param;

	if (keycode == 53)
		exit(0);
	// mlx_clear_window(win_ptr->mlx, win_ptr->win);
	return (0);
}

int	mouse_stuff_julia(int button, int x, int y, void *param)
{
	t_window		*win_ptr;
	static t_point	c = (t_point){0,0};

	win_ptr = (t_window *)param;
	mlx_clear_window(win_ptr->mlx, win_ptr->win);
	if (button == 1 && win_ptr->zoom == 1.0)
		c = scale_pt_to_window(x, y, win_ptr);
	else
		win_ptr->center = scale_pt_to_window(x, y, win_ptr);
	win_ptr->zoom *= 0.875;
	display_julia(c, win_ptr);
	return (0);
}

int	mouse_stuff_mandelbrot(int button, int x, int y, void *param)
{
	t_window		*win_ptr;

	(void)button;
	win_ptr = (t_window *)param;
	mlx_clear_window(win_ptr->mlx, win_ptr->win);
	win_ptr->center = scale_pt_to_window(x, y, win_ptr);
	win_ptr->zoom *= 0.875;
	display_mandelbrot(win_ptr);
	return (0);
}

int	mouse_stuff_burning_ship(int button, int x, int y, void *param)
{
	t_window		*win_ptr;

	(void)button;
	win_ptr = (t_window *)param;
	mlx_clear_window(win_ptr->mlx, win_ptr->win);
	win_ptr->center = scale_pt_to_window(x, y, win_ptr);
	win_ptr->zoom *= 0.875;
	display_burning_ship(win_ptr);
	return (0);
}
