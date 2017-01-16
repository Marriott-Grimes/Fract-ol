/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:25:04 by mgrimes           #+#    #+#             */
/*   Updated: 2017/01/04 14:25:06 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		gradient(int startcolor, int endcolor, float i)
{
	int alp;
	int red;
	int grn;
	int blu;

	alp = (int)((startcolor & 0xFF000000) * i +
		(endcolor & 0xFF000000) * (1.0 - i)) & 0xFF000000;
	red = (int)((startcolor & 0x00FF0000) * i +
		(endcolor & 0x00FF0000) * (1.0 - i)) & 0x00FF0000;
	blu = (int)((startcolor & 0x0000FF00) * i +
		(endcolor & 0x0000FF00) * (1.0 - i)) & 0x0000FF00;
	grn = (int)((startcolor & 0x000000FF) * i +
		(endcolor & 0x000000FF) * (1.0 - i)) & 0x000000FF;
	return (alp + red + blu + grn);
}
