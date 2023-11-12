/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:25:56 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/12 20:29:14 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_free(t_map_data *map_data)
{
	static t_map_data	*map_data_ptr;
	unsigned short		i;

	if (map_data_ptr == NULL)
		map_data_ptr = map_data;
	else
	{
		i = -1;
		if (map_data_ptr->raw)
			ft_free_split(map_data_ptr->raw);
		if (map_data_ptr->map)
			ft_free_split(map_data_ptr->map);
		i = 0;
		while (++i < 4)
			if (map_data_ptr->texture[i])
				free(&map_data_ptr[i]);
	}
}

void	ft_error(t_string error_message)
{
	ft_free(NULL);
	ft_putstr_fd(error_message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int argc, char const *argv[])
{
	t_map_data	map_data;

	if (argc != 2)
		ft_error(ARG);
	ft_bzero(&map_data, sizeof(t_map_data));
	ft_free(&map_data);
	parser((t_string)argv[1], &map_data);
	return (EXIT_SUCCESS);
}
