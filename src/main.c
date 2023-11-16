/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:25:56 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/16 14:09:45 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
	when called for the first time with struct address
	static map_data_ptr will point at struct. Rest
	of the times when function is called with any arg
	it will check if pointer is NULL(to avoid free error)
	if not then it frees the memory
*/
static void	ft_free(t_map_data *map_data)
{
	static t_map_data	*map_data_ptr;
	t_ushort			i;

	if (map_data_ptr == NULL)
		map_data_ptr = map_data;
	else
	{
		if (map_data_ptr->raw)
			ft_free_split(map_data_ptr->raw);
		if (map_data_ptr->map)
			ft_free_split(map_data_ptr->map);
		i = -1;
		while (++i < 4)
			if (map_data_ptr->texture[i])
				free(map_data_ptr->texture[i]);
	}
}

/*
	free up the memory, put message on stderr and exit with failure
*/
void	ft_error(t_string error_message)
{
	ft_free(NULL);
	ft_putstr_fd(error_message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	parser(t_string file, t_map_data *map_data)
{
	get_raw(file, map_data);
	check_keys(map_data, (char [6][4]){"NO ", "SO ", "EA ", "WE ", "C ", "F "});
	get_textures(map_data, (char [4][4]){"NO ", "SO ", "EA ", "WE "});
	get_colors(map_data);
	check_rgb_values(map_data);
	get_map(map_data, get_start_and_end(map_data), get_start_and_end(map_data));
	check_openings(map_data);
	get_player(map_data);
}

int	main(int argc, char const *argv[])
{
	t_map_data	map_data;

	ft_bzero(&map_data, sizeof(t_map_data));
	ft_free(&map_data);
	if (argc != 2)
		ft_error(ARG);
	parser((t_string)argv[1], &map_data);
	ft_free(NULL);
	return (EXIT_SUCCESS);
}

// for (int i = 0; i < 4; i++)
// 	printf("%d\t\t%s\n",i+1,map_data->texture[i]);
// printf("\nC\t\t");
// for (int i = 0; i < 3; i++)
// 	printf("%d,",map_data->ceil[i]);
// printf("\nF\t\t");
// for (int i = 0; i < 3; i++)
// 	printf("%d,",map_data->floor[i]);
// printf("\n\n");
// for (int i = 0; i < map_data->height; i++)
// 	printf("%i\t\t%s\n", i, map_data->map[i]);
// printf("\nPlayer's (X,Y)\t(%d, %d) dir %c\n", map_data->player.pos[X],\
 map_data->player.pos[Y], map_data->player.dir);