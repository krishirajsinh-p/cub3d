/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:25:56 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/14 07:49:08 by kpuwar           ###   ########.fr       */
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
			free(map_data_ptr->map);
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
// for (size_t i = 0; map_data->raw[i]; i++)
// 	printf("%lu\t|\t%s\n", i+1, map_data->raw[i]);

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
