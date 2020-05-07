/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 22:17:23 by ahallain          #+#    #+#             */
/*   Updated: 2020/05/07 21:31:23 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUNTIME_H
# define RUNTIME_H

# ifndef FOV
#  define FOV 70
# endif

# ifndef FORWARD
#  define FORWARD 119
# endif

# ifndef BACKWARD
#  define BACKWARD 115
# endif

# ifndef TURN_LEFT
#  define TURN_LEFT 97
# endif

# ifndef TURN_RIGHT
#  define TURN_RIGHT 100
# endif

# include "../main/cub3d.h"
# include <mlx.h>

typedef struct	s_position
{
	float	x;
	float	y;
}				t_position;

typedef struct	s_player
{
	float		degree;
	t_position	position;
	bool		initiate;
}				t_player;

typedef struct	s_input
{
	bool	forward;
	bool	backward;
	bool	turn_left;
	bool	turn_right;
	bool	rotate_left;
	bool	rotate_right;
}				t_input;

typedef struct	s_mlx
{
	t_settings	settings;
	t_player	player;
	t_input		input;
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
}				t_mlx;

typedef struct	s_ajust
{
	t_position	position;
	t_position	direction;
	float		degree;
}				t_ajust;

typedef struct	s_ray
{
	t_position	position;
	t_position	direction;
	t_position	side;
	t_position	delta;
	t_position	step;
}				t_ray;

void			ft_detect(t_mlx *mlx);
void			ft_update_key(int code, int value, t_mlx *mlx);
int				ft_update(t_mlx *mlx);
t_ajust			ft_ajust(t_player player);
float			ft_distance(float cameraX, t_ajust ajust, char **map);

#endif