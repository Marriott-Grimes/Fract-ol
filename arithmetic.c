/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:42:51 by mgrimes           #+#    #+#             */
/*   Updated: 2017/01/12 16:42:55 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	c_mult(t_point a, t_point b)
{
	t_point	ans;

	ans.x = a.x * b.x - a.y * b.y;
	ans.y = a.x * b.y + a.y * b.x;
	return (ans);
}

t_point	c_plus(t_point a, t_point b)
{
	t_point	ans;

	ans.x = a.x + b.x;
	ans.y = a.y + b.y;
	return (ans);
}

t_point	c_neg(t_point a)
{
	t_point	ans;

	ans.x = -a.x;
	ans.y = -a.y;
	return (ans);
}

float	modulus_squared(t_point a)
{
	return (a.x * a.x + a.y * a.y);
}
