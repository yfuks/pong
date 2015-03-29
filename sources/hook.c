/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 21:26:25 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/29 23:46:28 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

int		expose_hook(t_env *e)
{
	draw_all(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_UP && e->coord_player_1.y + W_HEIGHT / 10 < W_HEIGHT)
		e->coord_player_1.y--;
	else if (keycode == KEY_DOWN && e->coord_player_1.y > 0)
		e->coord_player_1.y++;
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		draw_all(e);
	return (0);
}
