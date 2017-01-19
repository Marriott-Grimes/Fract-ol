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

t_window struct_init(void)
{
	t_window	wndow;

	wndow.mlx = mlx_init();
	wndow.win = mlx_new_window(wndow.mlx, WINWIDTH, WINHEIGHT, "fract_lol");
	wndow.buf = mlx_new_image(wndow.mlx, WINWIDTH, WINHEIGHT);
	wndow.center = (t_point){0, 0};
	wndow.zoom = 1.0;
	wndow.wwd = WINWIDTH;
	wndow.wht = WINHEIGHT;
	wndow.bpp = 32;
	wndow.endian = 0;
	wndow.bytewd = 4 * WINWIDTH;
	return (wndow);
}

int main()
{
	t_window	wndow;

	wndow = struct_init();
	mlx_key_hook(wndow.win, key_stuff, &wndow);
	mlx_mouse_hook(wndow.win, mouse_stuff, &wndow);
	mlx_loop(wndow.mlx);
	return (0);
}
