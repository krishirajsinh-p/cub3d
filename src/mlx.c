/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 03:31:05 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/28 04:14:44 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int32_t	ft_color(int32_t r, int32_t g, int32_t b)
{
	return (r << 24 | g << 16 | b << 8 | 0x000000FF);
}

void	set_mlx_elements(t_game_data *game_data)
{
	short	i;

	i = -1;
	while (++i < 4)
	{
		game_data->walls[i] = mlx_load_png(game_data->map_data->texture[i]);
		if (game_data->walls[i] == NULL)
			ft_error("mlx");
	}
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game_data->mlx = mlx_init(1920, 1080, "cub3D - kpuwar & ihama", true);
	if (game_data->mlx == NULL)
		ft_error("mlx");
	game_data->img = mlx_new_image(game_data->mlx, 1920, 1080);
	if (game_data->img == NULL)
		ft_error("mlx");
	if (mlx_image_to_window(game_data->mlx, game_data->img, 0, 0) == -1)
		ft_error("mlx");
}

void	check_input(void *param)
{
	t_game_data	*game_data;

	game_data = (t_game_data *)param;
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game_data->mlx);
}
