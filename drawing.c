/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:04:23 by mgrimes           #+#    #+#             */
/*   Updated: 2017/01/19 15:04:32 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point		scale_pt_to_window(int x, int y, t_window *win_ptr)
{
	t_point ans;
	t_point mid;
	float	z;

	z = win_ptr->zoom;
	mid = win_ptr->center;
	ans = (t_point){(4.0 * (float)x / (float)win_ptr->wwd - 2.0) * z + mid.x,
					(-4.0 * (float)y / (float)win_ptr->wht + 2.0) * z + mid.y};
	return (ans);
}

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
