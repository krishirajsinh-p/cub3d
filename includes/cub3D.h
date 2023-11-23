/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:12:51 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/23 21:32:20 by kpuwar           ###   ########.fr       */
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

# define FOV 0.66

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
	t_vector	vectors[3];
}	t_map_data;

//main.c
void	ft_free(t_map_data *map_data);
void	ft_error(t_string error_message);
void	parser(t_string file, t_map_data *map_data);

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
void	get_player(t_map_data *map_data);

#endif
