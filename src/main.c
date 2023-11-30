/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:25:56 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/30 03:04:33 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
	when called for the first time with struct address
	static ptr will point at s_game_data struct. Rest
	of the times when function is called with any arg
	it will check if pointer is NULL(to avoid free error)
	if not then it frees the memory
*/
static void	ft_free(t_game_data *game_data)
{
	static t_game_data	*ptr;
	short				i;

	if (ptr == NULL)
		ptr = game_data;
	else
	{
		if (ptr->map_data.raw)
			ft_free_split(ptr->map_data.raw);
		if (ptr->map_data.map)
			ft_free_split(ptr->map_data.map);
		i = -1;
		while (++i < 4)
			if (ptr->map_data.texture[i])
				free(ptr->map_data.texture[i]);
		i = -1;
		while (++i < 4)
			if (ptr->walls[i])
				mlx_delete_texture(ptr->walls[i]);
		if (ptr->mlx)
			mlx_terminate(ptr->mlx);
	}
}

/*
	free up the memory, put message on stderr and exit with failure
*/
void	ft_error(t_string error_message)
{
	if (ft_strncmp("mlx", error_message, 3) == 0)
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	else
		ft_putstr_fd(error_message, STDERR_FILENO);
	ft_free(NULL);
	exit(EXIT_FAILURE);
}

static void	parser(t_string file, t_game_data *game_data)
{
	t_map_data	*map_data;

	map_data = &game_data->map_data;
	get_raw(file, map_data);
	check_keys(map_data, (char [6][4]){"NO ", "SO ", "EA ", "WE ", "C ", "F "});
	get_textures(map_data, (char [4][4]){"NO ", "SO ", "EA ", "WE "});
	get_colors(map_data);
	check_rgb_values(map_data);
	get_map(map_data, get_start_and_end(map_data), get_start_and_end(map_data));
	check_openings(map_data);
	get_player(map_data, game_data);
}

static void	engine(void *param)
{
	t_game_data	*game_data;
	short		x;
	t_ray		ray;

	game_data = (t_game_data *)param;
	paint_floor_ceil(game_data);
	x = -1;
	while (++x < (short)game_data->img->width)
	{
		set_ray(&ray, x, game_data->vectors, game_data->img);
		cast_ray(&ray, game_data->map_data.map);
		paint_walls(&ray, x, game_data->vectors, game_data);
	}
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game_data->mlx);
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_RIGHT))
		rotate(game_data->vectors, 1);
	if (mlx_is_key_down(game_data->mlx, MLX_KEY_LEFT))
		rotate(game_data->vectors, -1);
	move(game_data, game_data->map_data.map, game_data->vectors);
}

int	main(int argc, char const *argv[])
{
	t_game_data	game_data;

	ft_bzero(&game_data, sizeof(t_game_data));
	ft_free(&game_data);
	if (argc != 2)
		ft_error(ARG);
	parser((t_string)argv[1], &game_data);
	set_mlx_elements(&game_data);
	if (mlx_loop_hook(game_data.mlx, engine, &game_data) == false)
		ft_error("mlx");
	mlx_loop(game_data.mlx);
	ft_free(NULL);
	return (EXIT_SUCCESS);
}

// for (int i = 0; i < 4; i++)
// 	printf("%d\t\t%s\n",i+1,map_data.texture[i]);
// printf("\nC\t\t");
// for (int i = 0; i < 3; i++)
// 	printf("%d,",map_data.ceil[i]);
// printf("\nF\t\t");
// for (int i = 0; i < 3; i++)
// 	printf("%d,",map_data.floor[i]);
// printf("\n\n");
// for (int i = 0; i < map_data.height; i++)
// 	printf("%i\t\t%s\n", i, map_data.map[i]);
// printf("\nPlayer's (X,Y)\t(%f, %f) dir %c\n", map_data.player.pos[X],\
//  map_data.player.pos[Y], map_data.player.dir);