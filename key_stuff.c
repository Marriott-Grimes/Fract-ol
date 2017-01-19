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

int	mouse_stuff(int button, int x, int y, void *param)
{
	t_window	*win_ptr;
	t_point		c;

	(void)button;
	win_ptr = (t_window *)param;
	mlx_clear_window(win_ptr->mlx, win_ptr->win);
	c = (t_point){4.0 * (float)x / (float)WINWIDTH - 2.0,
				-4.0 * (float)y / (float)WINHEIGHT + 2.0};
	win_ptr->zoom *= 0.9;
	display_julia(c, win_ptr);
	return (0);
}
