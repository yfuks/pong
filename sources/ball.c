/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 04:04:52 by spariaud          #+#    #+#             */
/*   Updated: 2015/03/30 04:44:33 by spariaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

void	move_ball(t_env *e)
{
	e->ball.old_center.x = e->ball.new_center.x;
	e->ball.old_center.y = e->ball.new_center.y;
	e->ball.new_center.x += e->ball.vitesse.x;
	e->ball.new_center.y += e->ball.vitesse.y;
	//usleep(1000);
	//draw_all(e);
}
