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
# include <unistd.h>
# include "mlx.h"

# define WINWIDTH 600
# define WINHEIGHT 600
# define STCOL 0x0010008F
# define ENCOL 0x00009F00
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
	int			wwd;
	int			wht;
	int			bpp;
	int			bytewd;
	int			endian;
}				t_window;

void	ft_putstr(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putchar(const char c);
t_point	c_mult(t_point a, t_point b);
t_point	c_plus(t_point a, t_point b);
float	modulus_squared(t_point a);
int		mouse_stuff_julia(int button, int x, int y, void *param);
int		mouse_stuff_mandelbrot(int button, int x, int y, void *param);
int		mouse_stuff_burning_ship(int button, int x, int y, void *param);
int		key_stuff(int keycode, void *param);
int		gradient(int startcolor, int endcolor, float i);
void	display_julia(t_point c, t_window *win_ptr);
void	display_mandelbrot(t_window *win_ptr);
t_point	scale_pt_to_window(int x, int y, t_window *win_ptr);
float	iterate_map(t_point init_val, t_point c, int max_iterates);
void	display_burning_ship(t_window *win_ptr);

#endif
