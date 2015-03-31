/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 21:26:25 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/31 17:23:08 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

int		expose_hook(t_env *e)
{
	draw_all(e);
	return (0);
}

int		key_press(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_UP)
		e->player_1_mouv_up = 1;
	else if (keycode == KEY_DOWN)
		e->player_1_mouv_down = 1;
	else if (keycode == KEY_W)
		e->player_2_mouv_up = 1;
	else if (keycode == KEY_S)
		e->player_2_mouv_down = 1;
	return (0);
}

int		key_release(int keycode, t_env *e)
{
	if (keycode == KEY_UP)
		e->player_1_mouv_up = 0;
	else if (keycode == KEY_DOWN)
		e->player_1_mouv_down = 0;
	else if (keycode == KEY_W)
		e->player_2_mouv_up = 0;
	else if (keycode == KEY_S)
		e->player_2_mouv_down = 0;
	return (0);
}

int		loop_hook(t_env *e)
{
	clock_t		clock_tmp;

	clock_tmp = clock();
	if ((1000 * (clock_tmp - e->clock3)) / CLOCKS_PER_SEC > 1)
	{
		e->clock3 = clock();
		if (e->player_1_mouv_up == 1 && (int)e->coord_player_1.y - 56 > 0)
			e->coord_player_1.y -= 4;
		if (e->player_1_mouv_down == 1 && (int)e->coord_player_1.y + 5
			+ W_HEIGHT / 10 < W_HEIGHT)
			e->coord_player_1.y += 4;
		if (e->player_2_mouv_up == 1 && (int)e->coord_player_2.y - 56 > 0)
			e->coord_player_2.y -= 4;
		if (e->player_2_mouv_down == 1 && (int)e->coord_player_2.y + 5
			+ W_HEIGHT / 10 < W_HEIGHT)
			e->coord_player_2.y += 4;
		draw_all(e);
	}
	return (0);
}
