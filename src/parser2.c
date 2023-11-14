/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:32:38 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/14 08:04:25 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
	gives the index for the start and end line of the map.
*/
short	get_start_and_end(t_map_data *map_data)
{
	static t_ushort	i;
	t_ushort		j;
	bool			has_one;

	has_one = false;
	while (map_data->raw[i])
	{
		j = 0;
		while (map_data->raw[i][j] == ' ' || map_data->raw[i][j] == '1')
		{
			if (has_one == false && map_data->raw[i][j] == '1')
				has_one = true;
			j++;
		}
		if (has_one && map_data->raw[i][j] == '\0')
			return (i++);
		i++;
	}
	return (-1);
}

/*
	check for the openings in the map, map should be closed.
*/
void	check_openings(t_map_data *map_data)
{
	short	i[2];
	char	*line;
	bool	has_one;

	i[0] = -1;
	while (++i[0] < map_data->map_size)
	{
		line = ft_strtrim(map_data->map[i[0]], " ");
		has_one = line[0] == '1' && line[ft_strlen(line) - 1] == '1';
		free(line);
		if (has_one == false)
			ft_error(O_MAP);
	}
	i[0] = 0;
	while (++i[0] < map_data->map_size - 1)
	{
		i[1] = 0;
		while (++i[1] < (short)ft_strlen(map_data->map[i[0]]) - 1)
			if (map_data->map[i[0]][i[1]] == '0')
				if (map_data->map[i[0] - 1][i[1]] == ' ' \
				|| map_data->map[i[0]][i[1] - 1] == ' ' \
				|| map_data->map[i[0] + 1][i[1]] == ' ' \
				|| map_data->map[i[0]][i[1] + 1] == ' ')
					ft_error(O_MAP);
	}
}

/*
	sets map from the raw map data.
	!! NOTE: all the pointers of map are just pointing
				to the same memory as raw map data.
*/
void	get_map(t_map_data *map_data, short start, short end)
{
	t_ushort	i;

	if (start == -1 || end == -1)
		ft_error(O_MAP);
	map_data->map_size = (end - start) + 1;
	map_data->map = ft_calloc(map_data->map_size + 1, sizeof(t_string));
	if (map_data->map == NULL)
		ft_error(ALLOC);
	i = 0;
	while (i < map_data->map_size)
	{
		map_data->map[i] = map_data->raw[start + i];
		i++;
	}
}

/*
	sets the player data, it's position and it's direction.
	also checks if there is exactly on player in the map.
	it also checks if there isn't any useless char in the map.
*/
void	get_player(t_map_data *map_data)
{
	short		i;
	short		j;

	i = -1;
	while (++i < map_data->map_size)
	{
		j = -1;
		while (map_data->map[i][++j])
		{
			if (map_data->map[i][j] == 'N' || map_data->map[i][j] == 'S' || \
			map_data->map[i][j] == 'E' || map_data->map[i][j] == 'W')
			{
				map_data->player.pos[X] = i;
				map_data->player.pos[Y] = j;
				map_data->player.dir = map_data->map[i][j];
				map_data->player.count++;
			}
			else if (map_data->map[i][j] != '0' && map_data->map[i][j] != '1' \
			&& map_data->map[i][j] != ' ')
				ft_error(INV_CHAR);
		}
	}
	if (map_data->player.count != 1)
		ft_error(ONE_PLYR);
}

	// for (size_t i = 0; map_data->map[i]; i++)
	// 	printf("%lu\t|\t[%s]\n", i + 1, map_data->map[i]);