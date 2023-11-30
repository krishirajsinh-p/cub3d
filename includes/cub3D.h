/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:12:51 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/30 03:22:47 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "e_cub3D.h"
# include "err_cub3D.h"
# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define FOV 0.66
# define ROT 0.02
# define MV 0.02

typedef unsigned short	t_ushort;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_map_data
{
	t_string	*raw;
	t_string	texture[4];
	short		floor[3];
	short		ceil[3];
	t_string	*map;
	t_ushort	height;
	t_ushort	width;
}	t_map_data;

typedef struct s_game_data
{
	t_vector		vectors[3];
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*walls[4];
	t_map_data		map_data;
}	t_game_data;

typedef struct s_ray
{
	double	cam_x;
	double	dir[2];
	double	d_dist[2];
	int		pos[2];
	double	s_dist[2];
	int		step[2];
	int		hit_side[2];
	int		hit_axis;
	double	wall_dist;
	int		wall_hit;
}	t_ray;

typedef struct s_texture
{
	int		line_height;
	int		start;
	int		end;
	double	wall_x;
	double	step;
	int		pxl[2];
	double	pos;
}	t_texture;

//main.c
void	ft_error(t_string error_message);

//parser.c
void	get_raw(t_string file, t_map_data *map_data);
void	check_keys(t_map_data *map_data, char keys[6][4]);
void	get_textures(t_map_data *map_data, char text_key[4][4]);
void	get_colors(t_map_data *map_data);
void	check_rgb_values(t_map_data *map_data);

//parser2.c
short	get_start_and_end(t_map_data *map_data);
void	get_map(t_map_data *map_data, short start, short end);
void	check_openings(t_map_data *map_data);
void	get_player(t_map_data *map_data, t_game_data *game_data);

//mlx.c
void	set_mlx_elements(t_game_data *game_data);

//controller.c
void	move(t_game_data *game_data, t_string *map, t_vector *vec);
void	rotate(t_vector	*vectors, short sign);

//engine.c
void	set_ray(t_ray *r, short x, t_vector *vec, mlx_image_t *img);
void	cast_ray(t_ray *r, t_string *map);

//render.c
void	paint_floor_ceil(t_game_data *game);
void	paint_walls(t_ray *r, short x, t_vector *vec, t_game_data *g);

#endif
