/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:25:56 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/13 04:07:44 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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

void	ft_error(t_string error_message)
{
	ft_free(NULL);
	ft_putstr_fd(error_message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	parser(t_string file, t_map_data *map_data)
{
	get_raw(file, map_data);
	check_keys(map_data, (char [6][3]){"NO", "SO", "EA", "WE", "C ", "F "});
	get_textures(map_data, (char [4][3]){"NO", "SO", "EA", "WE"});
	get_colors(map_data);
	check_rgb_values(map_data);
}
// for (size_t i = 0; map_data->raw[i]; i++)
// 	printf("%lu\t|\t%s\n", i+1, map_data->raw[i]);

int	main(int argc, char const *argv[])
{
	t_map_data	map_data;

	if (argc != 2)
		ft_error(ARG);
	ft_bzero(&map_data, sizeof(t_map_data));
	ft_free(&map_data);
	parser((t_string)argv[1], &map_data);
	ft_free(NULL);
	return (EXIT_SUCCESS);
}
