/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 03:31:05 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/25 01:07:35 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
	game_data->mlx = mlx_init(1920, 1080, "cub3D - kpuwar & ihama", 1);
	if (game_data->mlx == NULL)
		ft_error("mlx");
	game_data->img = mlx_new_image(game_data->mlx, 1920, 1080);
	if (game_data->img == NULL)
		ft_error("mlx");
	if (mlx_image_to_window(game_data->mlx, game_data->img, 0, 0) == -1)
		ft_error("mlx");
}

void	ft_close(void *param)
{
	t_game_data	*game_data;

	game_data = (t_game_data *)param;
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game_data->mlx);
}

void	ft_resize(void *param)
{
	static int32_t	*s_width;
	static int32_t	*s_height;
	t_game_data		*game_data;

	game_data = (t_game_data *)param;
	mlx_get_monitor_size(0, s_width, s_height);
	if (s_width != game_data->s_width && s_height != game_data->s_height)
	{
		game_data->s_width = s_width;
		game_data->s_height = s_height;
		if (mlx_resize_image(game_data->img, s_width, s_height) == false)
			ft_error("mlx");
	}
}
