/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 21:26:25 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/30 02:33:31 by yfuks            ###   ########.fr       */
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
	if (e->player_1_mouv_up == 1 && (int)e->coord_player_1.y - 1 > 0)
		e->coord_player_1.y--;
	else if (e->player_1_mouv_down == 1 && (int)e->coord_player_1.y + 1
			+ W_HEIGHT / 10 < W_HEIGHT)
		e->coord_player_1.y++;
	if (e->player_2_mouv_up == 1 && (int)e->coord_player_2.y - 1 > 0)
		e->coord_player_2.y--;
	else if (e->player_2_mouv_down == 1 && (int)e->coord_player_2.y + 1
			+ W_HEIGHT / 10 < W_HEIGHT)
		e->coord_player_2.y++;
	if (e->player_1_mouv_up == 1 || e->player_1_mouv_down == 1
		|| e->player_2_mouv_up == 1 || e->player_2_mouv_down == 1)
		draw_all(e);
	usleep(1000);
	return (0);
}
