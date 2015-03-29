/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 21:41:33 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/29 22:55:41 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

void	draw_rectangle(t_env *e, t_coord coord, int height, int width)
{
	t_coord	position;

	position.y = coord.y;
	while (position.y < coord.y + width)
	{
		position.x = coord.x;
		while (position.x < coord.x + height)
		{
			put_pixel(e, position, REC_COLOR);
			position.x++;
		}
		position.y++;
	}
}
