/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 21:05:10 by yfuks             #+#    #+#             */
/*   Updated: 2015/03/31 19:34:46 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONG_H
# define PONG_H
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# define W_HEIGHT	600
# define W_WIDTH	1000
# define W_TITLE	"Pong 42"

# define KEY_ESC	53
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_W		13
# define KEY_S		1

# define REC_WIDTH	10
# define REC_COLOR	0xFFFFFF

# define SCORE_WIN	10

typedef struct		s_coord
{
	unsigned int	x;
	unsigned int	y;
}					t_coord;

typedef	struct		s_ball
{
	t_coord			old_center;
	t_coord			new_center;
	t_coord			vitesse;
}					t_ball;

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
	int				score_player_1;
	int				score_player_2;
	int				is_victory;
	t_coord			coord_player_1;
	t_coord			coord_player_2;
	int				player_1_mouv_up;
	int				player_1_mouv_down;
	int				player_2_mouv_up;
	int				player_2_mouv_down;
	t_ball			ball;
	t_coord			coord_score_bar;
	clock_t			clock1;
	clock_t			clock2;
	clock_t			clock3;
}					t_env;

void				put_pixel(t_env *e, t_coord coord, int coloration);
void				draw_scores(t_env *e);
void				draw_rectangle(t_env *e, t_coord coord,
								int height, int width);
void				draw_number(t_env *e, t_coord coord, unsigned int number,
								int size);
void				draw_all(t_env *e);
void				init_ball(t_env *e);
void				draw_dotted(t_env *e);
void				move_ball(t_env *e);
void				physics(t_env *e);
void				update_score_player_1(t_env *e);
void				update_score_player_2(t_env *e);
char				*ft_itoa(int n);
int					expose_hook(t_env *e);
int					key_press(int keycode, t_env *e);
int					key_release(int keycode, t_env *e);
int					loop_hook(t_env *e);
#endif
