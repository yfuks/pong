/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 21:21:26 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/29 23:46:04 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

static void	init_player(t_env *e)
{
	e->coord_player_1.x = 5;
	e->coord_player_1.y = W_HEIGHT / 2 - ((W_HEIGHT / 10) / 2);
	e->coord_player_2.x = W_WIDTH - REC_HEIGHT - 5;
	e->coord_player_2.y = W_HEIGHT / 2 - ((W_HEIGHT / 10) / 2);
}

int		main(void)
{
	t_env 		e;

	if ((e.mlx = mlx_init()))
	{
		if ((e.win = mlx_new_window(e.mlx, W_WIDTH, W_HEIGHT, W_TITLE)))
		{
			init_player(&e);
			mlx_hook(e.win, 3, 2, key_hook, &e);
			mlx_expose_hook(e.win, expose_hook, &e);
			mlx_loop(e.mlx);
		}
	}
	return (0);
}
