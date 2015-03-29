/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 21:43:21 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/29 23:11:00 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

void	put_pixel(t_env *e, t_coord coord, int coloration)
{
	int		r;
	int		g;
	int		b;

	r = (coloration & 0xFF0000) >> 16;
	g = (coloration & 0xFF00) >> 8;
	b = (coloration & 0xFF);
	if (coord.y < W_HEIGHT && coord.x < W_WIDTH)
	{
		e->data[(coord.y * e->sizeline) + ((e->bpp / 8) * coord.x) + 2] = r;
		e->data[(coord.y * e->sizeline) + ((e->bpp / 8) * coord.x) + 1] = g;
		e->data[(coord.y * e->sizeline) + ((e->bpp / 8) * coord.x)] = b;
	}
}
