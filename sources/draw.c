/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 21:30:41 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/30 04:21:11 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

static void	get_data_img(t_env *e)
{
	if (!(e->data = mlx_get_data_addr
		  (e->img, &e->bpp, &e->sizeline, &e->endian)))
		exit(-1);
}

void	draw_all(t_env *e)
{
	if (!(e->img = mlx_new_image(e->mlx, W_WIDTH, W_HEIGHT)))
		exit(-1);
	get_data_img(e);
	draw_rectangle(e, e->coord_player_1, REC_HEIGHT, W_HEIGHT / 10);
	draw_rectangle(e, e->coord_player_2, REC_HEIGHT, W_HEIGHT / 10);
	draw_rectangle(e, e->coord_score_bar, W_WIDTH, 1);
	draw_dotted(e);
	//if (e->update_score)
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	draw_scores(e);
	mlx_destroy_image(e->mlx, e->img);
}
