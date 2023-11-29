/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:04:19 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/29 03:02:32 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	move(t_game_data *game_data, t_string *map)
{
	double		w_x;
	double		w_y;
	t_vector	pos;

	pos = game_data->vectors[POS];
	w_x = pos.x * MOVESPEED;
	w_y = pos.y * MOVESPEED;
	// move2(vectors->player_position[Y] + (fact_x), vectors->player_position[X] - (fact_y), map, vectors);
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_D))
		if (map[(int)(pos.y + w_x)][(int)(pos.x - w_y)] != '1')
			game_data->vectors[POS] = {pos.x - w_y, pos.y + w_x};
	// move2(vectors->player_position[Y] - (fact_x), vectors->player_position[X] + (fact_y), map, vectors);
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_A))
		if (map[(int)(pos.y - w_x)][(int)(pos.x + w_y)] != '1')
				game_data->vectors[POS] = {pos.x + w_y, pos.y - w_x};
	// move2(vectors->player_position[Y] + (fact_y), vectors->player_position[X] + (fact_x), map, vectors);
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_W))
		if (map[(int)(pos.y + w_y)][(int)(pos.x + w_x)] != '1')
				game_data->vectors[POS] = {pos.x + w_x, pos.y + w_y};
	// move2(vectors->player_position[Y] - (fact_y), vectors->player_position[X] - (fact_x), map, vectors);
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_S))
		if (map[(int)(pos.y - w_y)][(int)(pos.x - w_x)] != '1')
				game_data->vectors[POS] = {pos.x - w_x, pos.y - w_y};

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
