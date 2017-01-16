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

int main()
{

	t_window	window_ptr;

	window_ptr.mlx = mlx_init();
	window_ptr.win = mlx_new_window(mlx, WINWIDTH, WINHEIGHT, "fract_lol");
	window_ptr.buf = mlx_new_image (window_ptr.mlx, WINWIDTH, WINHEIGHT);
	mlx_key_hook(win, key_stuff, &window_ptr);
	mlx_mouse_hook(win, mouse_stuff, &window_ptr);
	mlx_loop(mlx);
	return (0);
}
