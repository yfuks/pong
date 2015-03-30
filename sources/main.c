/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 21:21:26 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/30 05:00:30 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

static void	init_player(t_env *e)
{
	e->coord_player_1.x = 5;
	e->coord_player_1.y = W_HEIGHT / 2 - ((W_HEIGHT / 10) / 2);
	e->player_1_mouv_up = 0;
	e->player_1_mouv_down = 0;
	e->coord_player_2.x = W_WIDTH - REC_HEIGHT - 5;
	e->coord_player_2.y = W_HEIGHT / 2 - ((W_HEIGHT / 10) / 2);
	e->player_2_mouv_up = 0;
	e->player_2_mouv_down = 0;
	e->coord_score_bar.x = 0;
	e->coord_score_bar.y = 50;
	e->score_player_1 = 0;
	e->score_player_2 = 0;
	e->img = NULL;
	e->clock = clock();
}

static void init_ball(t_env *e)
{
	e->ball.old_center.x = (W_WIDTH / 2);
	e->ball.old_center.y = (W_HEIGHT / 2);
	e->ball.new_center.x = e->ball.old_center.x;
	e->ball.new_center.y = e->ball.old_center.y;
	e->ball.vitesse.x = 2;
	e->ball.vitesse.y = rand() % 3;
	if (rand() % 2 == 0)
	{
		e->ball.vitesse.x = -e->ball.vitesse.x;
		e->ball.vitesse.y = -e->ball.vitesse.y;
	}
}

int		main(void)
{
	t_env 		e;

	if ((e.mlx = mlx_init()))
	{
		if ((e.win = mlx_new_window(e.mlx, W_WIDTH, W_HEIGHT, W_TITLE)))
		{
			init_player(&e);
			srand((int) time(NULL));
			init_ball(&e);
			mlx_do_key_autorepeatoff(e.mlx);
			mlx_hook(e.win, 2, (1L << 0) , key_press, &e);
			mlx_hook(e.win, 3, (1L << 1) , key_release, &e);
			mlx_expose_hook(e.win, expose_hook, &e);
			mlx_loop_hook(e.mlx, loop_hook, &e);
			mlx_loop(e.mlx);
		}
	}
	return (0);
}
