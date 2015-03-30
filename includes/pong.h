/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 21:05:10 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/30 02:04:27 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONG_H
# define PONG_H
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

# define W_HEIGHT	600		// hauteur
# define W_WIDTH	1000	// largeur
# define W_TITLE	"Pong 42"

# define KEY_ESC	53
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_W		13
# define KEY_S		1

# define REC_HEIGHT	10
# define REC_COLOR	0xFFFFFF

typedef struct		s_coord
{
	unsigned int	x;
	unsigned int	y;
}					t_coord;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				nb_line;
	int				sizeline;
	int				endian;
	int				bpp;
	t_coord			coord_player_1;
	t_coord			coord_player_2;
	int				player_1_mouv_up;
	int				player_1_mouv_down;
	int				player_2_mouv_up;
	int				player_2_mouv_down;
	t_coord			ball;
}					t_env;

void				put_pixel(t_env *e, t_coord coord, int coloration);
void				draw_rectangle(t_env *e, t_coord coord,
								int height, int width);
void				draw_number(t_env *e, t_coord coord, unsigned int number,
								int size);
void				draw_all(t_env *e);
void				draw_dotted(t_env *e);
int					expose_hook(t_env *e);
int					key_press(int keycode, t_env *e);
int					key_release(int keycode, t_env *e);
int					loop_hook(t_env *e);
#endif
