/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:42:21 by mgrimes           #+#    #+#             */
/*   Updated: 2017/01/12 17:42:24 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"

# define WINWIDTH 1200
# define WINHEIGHT 1200
# define STCOL 0x0050006F
# define ENCOL 0x0000AF00
# define PI 3.14159

typedef	struct	s_point
{
	float		x;
	float		y;
}				t_point;

typedef	struct	s_window
{
	void		*mlx;
	void		*win;
	void		*buf;
	float		zoom;
	t_point		center;
	int			rgb;
}				t_window;

t_point	c_mult(t_point a, t_point b);
t_point	c_plus(t_point a, t_point b);
float	modulus_squared(t_point a);
int		mouse_stuff(int button, int x, int y, void *param);
int		key_stuff(int keycode, void *param);
int		gradient(int startcolor, int endcolor, float i);

#endif
