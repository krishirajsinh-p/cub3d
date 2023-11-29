/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:04:19 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/29 22:22:20 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	move(t_game_data *game_data, t_string *map, t_vector *vec)
{
	double		w_x;
	double		w_y;

	w_x = vec[DIR].x * MV;
	w_y = vec[DIR].y * MV;
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_D))
		if (map[(int)(vec[POS].y + w_x)][(int)(vec[POS].x - w_y)] != '1')
			vec[POS] = (t_vector){vec[POS].x - w_y, vec[POS].y + w_x};
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_A))
		if (map[(int)(vec[POS].y - w_x)][(int)(vec[POS].x + w_y)] != '1')
			vec[POS] = (t_vector){vec[POS].x + w_y, vec[POS].y - w_x};
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_W))
		if (map[(int)(vec[POS].y + w_y)][(int)(vec[POS].x + w_x)] != '1')
			vec[POS] = (t_vector){vec[POS].x + w_x, vec[POS].y + w_y};
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_S))
		if (map[(int)(vec[POS].y - w_y)][(int)(vec[POS].x - w_x)] != '1')
			vec[POS] = (t_vector){vec[POS].x - w_x, vec[POS].y - w_y};
}

void	rotate(t_vector	*vectors, short sign)
{
	double	cosA;
	double	sinA;

	cosA = cos(sign * ROT);
	sinA = sin(sign * ROT);
	vectors[DIR].x = (vectors[DIR].x * cosA) - (vectors[DIR].y * sinA);
	vectors[DIR].y = (vectors[DIR].x * sinA) + (vectors[DIR].y * cosA);
	vectors[CAM].x = (vectors[CAM].x * cosA) - (vectors[CAM].y * sinA);
	vectors[CAM].y = (vectors[CAM].x * sinA) + (vectors[CAM].y * cosA);
}
