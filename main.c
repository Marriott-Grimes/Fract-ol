/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:56:27 by mgrimes           #+#    #+#             */
/*   Updated: 2017/01/15 15:56:29 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_window	struct_init(void)
{
	t_window	wndow;

	wndow.mlx = mlx_init();
	wndow.win = mlx_new_window(wndow.mlx, WINWIDTH, WINHEIGHT, "fract_lol");
	wndow.buf = mlx_new_image(wndow.mlx, WINWIDTH, WINHEIGHT);
	wndow.center = (t_point){0, 0};
	wndow.c = (t_point){0, 0};
	wndow.zoom = 1.0;
	wndow.wwd = WINWIDTH;
	wndow.wht = WINHEIGHT;
	wndow.bpp = 32;
	wndow.endian = 0;
	wndow.bytewd = 4 * WINWIDTH;
	return (wndow);
}

void		dem_lines_lol(t_window wndow, char **argv)
{
	if (argv[1][0] == 'j')
	{
		display_julia(wndow.c, &wndow);
		mlx_hook(wndow.win, 6, 1L << 6, motion_stuff, &wndow);
		mlx_key_hook(wndow.win, key_stuff, &wndow);
		mlx_mouse_hook(wndow.win, mouse_stuff_julia, &wndow);
		mlx_loop(wndow.mlx);
	}
	if (argv[1][0] == 'm')
	{
		display_mandelbrot(&wndow);
		mlx_key_hook(wndow.win, key_stuff, &wndow);
		mlx_mouse_hook(wndow.win, mouse_stuff_mandelbrot, &wndow);
		mlx_loop(wndow.mlx);
	}
	if (argv[1][0] == 'b')
	{
		display_burning_ship(&wndow);
		mlx_key_hook(wndow.win, key_stuff, &wndow);
		mlx_mouse_hook(wndow.win, mouse_stuff_burning_ship, &wndow);
		mlx_loop(wndow.mlx);
	}
}

int			main(int argc, char **argv)
{
	t_window	wndow;

	if (argc != 2)
	{
		ft_putstr(
		"USAGE: ./fractol [fractal name]\nmandelbrot, julia, burning ship\n");
		return (0);
	}
	wndow = struct_init();
	dem_lines_lol(wndow, argv);
	return (0);
}
