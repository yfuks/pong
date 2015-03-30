/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scores.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 00:49:47 by spariaud          #+#    #+#             */
/*   Updated: 2015/03/30 14:41:36 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

void	update_score_player_2(t_env *e)
{
	e->score_player_2++;
	if (e->score_player_2 >= SCORE_WIN)
		e->is_victory = 2;
}

void	update_score_player_1(t_env *e)
{
	e->score_player_1++;
	if (e->score_player_1 >= SCORE_WIN)
		e->is_victory = 1;
}

void	draw_scores(t_env *e)
{
	t_coord		pos;

	pos.x = W_WIDTH / 4;
	pos.y = 25;
	mlx_string_put(e->mlx, e->win, pos.x - 33, pos.y - 23, 0xFFFFFF,
				   "Player 1");
	mlx_string_put(e->mlx, e->win, pos.x, pos.y, 0xFFFFFF,
				   ft_itoa(e->score_player_1));
	pos.x = (W_WIDTH / 2) + (W_WIDTH / 4);
	mlx_string_put(e->mlx, e->win, pos.x - 33, pos.y - 23, 0xFFFFFF, 
				   "Player 2");
	mlx_string_put(e->mlx, e->win, pos.x, pos.y, 0xFFFFFF,
				   ft_itoa(e->score_player_2));
}
