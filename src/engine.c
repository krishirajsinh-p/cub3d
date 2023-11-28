/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:13:50 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/28 05:35:29 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	paint_floor_ceil(t_game_data *game)
{
	short		*ceil;
	short		*floor;
	mlx_image_t	*img;
	t_ushort	x;
	t_ushort	y;

	ceil = game->map_data.ceil;
	floor = game->map_data.floor;
	img = game->img;
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

void	raycasting(void *param)
{
	t_game_data	*game;

	game = (t_game_data *)param;
	paint_floor_ceil(game);
}
