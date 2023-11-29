/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:13:50 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/29 03:29:39 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	paint_floor_ceil(t_game_data *game_data)
{
	short		*ceil;
	short		*floor;
	mlx_image_t	*img;
	t_ushort	x;
	t_ushort	y;

	ceil = game_data->map_data.ceil;
	floor = game_data->map_data.floor;
	img = game_data->img;
	x = -1;
	while (++x < img->width)
	{
		y = 0;
		while (y < img->height / 2)
			mlx_put_pixel(img, x, y++, ft_color(ceil[R], ceil[G], ceil[B]));
		while (y < img->height)
			mlx_put_pixel(img, x, y++, ft_color(floor[R], floor[G], floor[B]));
	}
}

void	check_input(t_game_data *game_data)
{
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game_data->mlx);
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_RIGHT))
		rotate(game_data->vectors, 1);
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_LEFT))
		rotate(game_data->vectors, -1);
	move(game_data, game_data->map_data.map);
}

void	raycasting(void *param)
{
	t_game_data	*game_data;

	game_data = (t_game_data *)param;
	paint_floor_ceil(game_data);
	//raycasting loop here
	check_input(game_data);
}
