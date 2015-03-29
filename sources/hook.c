/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 21:26:25 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/29 21:49:12 by yfuks            ###   ########.fr       */
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
	(void)e;
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
