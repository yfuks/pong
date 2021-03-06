/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 04:04:52 by spariaud          #+#    #+#             */
/*   Updated: 2015/03/31 19:31:37 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

static void physics_next(t_env *e)
{
	if (e->ball.new_center.x + 10 > (W_WIDTH - 15))
	{
		if (e->ball.new_center.y > e->coord_player_2.y - 10 &&
			e->ball.new_center.y < e->coord_player_2.y + ((W_HEIGHT / 10) / 2))
		{
			e->ball.vitesse.x = -e->ball.vitesse.x;
			e->ball.vitesse.y = -rand() % 6;
		}
		else if (e->ball.new_center.y > e->coord_player_2.y &&
				 e->ball.new_center.y < e->coord_player_2.y + (W_HEIGHT / 10) + 10)
		{
			e->ball.vitesse.x = -e->ball.vitesse.x;
			e->ball.vitesse.y = rand() % 6;
		}
		else
		{
			init_ball(e);
			update_score_player_1(e);
			return ;
		}
	}
}

void	physics(t_env *e)
{
	if (e->ball.new_center.x < 15)
	{
		if (e->ball.new_center.y > e->coord_player_1.y - 10 &&
			e->ball.new_center.y < e->coord_player_1.y + ((W_HEIGHT / 10) / 2))
		{
			e->ball.vitesse.x = -e->ball.vitesse.x;
			e->ball.vitesse.y = -rand() % 6;
		}
		else if (e->ball.new_center.y > e->coord_player_1.y &&
				 e->ball.new_center.y < e->coord_player_1.y + ((W_HEIGHT / 10) + 10))
		{
			e->ball.vitesse.x = -e->ball.vitesse.x;
			e->ball.vitesse.y = rand() % 6;
		}
		else
		{
			update_score_player_2(e);
			init_ball(e);
			return ;
		}
	}
	physics_next(e);
}

void	move_ball(t_env *e)
{
	e->ball.old_center.x = e->ball.new_center.x;
	e->ball.old_center.y = e->ball.new_center.y;
	e->ball.new_center.x += e->ball.vitesse.x;
	e->ball.new_center.y += e->ball.vitesse.y;
	if (e->ball.new_center.y - 5 <= 51)
		e->ball.vitesse.y = -e->ball.vitesse.y;
	if (e->ball.new_center.y + 10 >= W_HEIGHT)
		e->ball.vitesse.y = -e->ball.vitesse.y;
}

void	init_ball(t_env *e)
{
	e->ball.old_center.x = (W_WIDTH / 2);
	e->ball.old_center.y = (W_HEIGHT / 2);
	e->ball.new_center.x = e->ball.old_center.x;
	e->ball.new_center.y = e->ball.old_center.y;
	e->ball.vitesse.x = 1;
	e->ball.vitesse.y = rand() % 1;
	if (rand() % 2 == 0)
	{
		e->ball.vitesse.x = -e->ball.vitesse.x;
		e->ball.vitesse.y = -e->ball.vitesse.y;
	}
}
