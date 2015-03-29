/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 21:21:26 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/29 21:25:26 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

int		main(void)
{
	t_env e;

	if ((e.mlx = mlx_init()))
	{
		if ((e.win = mlx_new_window(e.mlx, W_HEIGHT, W_WIDTH, W_TITLE)))
		{
			mlx_hook(e.win, 3, 3, key_hook, &e);
			mlx_expose_hook(e.win, expose_hook, &e);
			mlx_loop(e.mlx);
		}
	}
	return (0);
}
