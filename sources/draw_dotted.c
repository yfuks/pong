/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_dotted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 23:19:28 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/29 23:28:15 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

void		draw_dotted(t_env *e)
{
	t_coord		position;

	position.x = W_WIDTH / 2 - 3;
	position.y = 0;
	while (position.y < W_HEIGHT)
	{
		draw_rectangle(e, position, 3, 3);
		position.y += 6;
	}
}
