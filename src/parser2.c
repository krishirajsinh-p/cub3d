/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:32:38 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/30 15:15:49 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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

void	check_openings(t_map_data *map_data)
{
	short	i[2];
	char	*line;
	bool	has_one;

	i[0] = -1;
	while (++i[0] < map_data->height)
	{
		line = ft_strtrim(map_data->map[i[0]], " ");
		has_one = line[0] == '1' && line[ft_strlen(line) - 1] == '1';
		free(line);
		if (has_one == false)
			ft_error(O_MAP);
	}
	i[0] = 0;
	while (++i[0] < map_data->height - 1)
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

void	get_map(t_map_data *map_data, short start, short end)
{
	short	i;

	if (start == -1 || end == -1)
		ft_error(O_MAP);
	map_data->height = (end - start) + 1;
	map_data->map = ft_calloc(map_data->height + 1, sizeof(t_string));
	if (map_data->map == NULL)
		ft_error(ALLOC);
	map_data->width = 0;
	i = -1;
	while (++i < map_data->height)
		if (ft_strlen(map_data->raw[start + i]) > map_data->width)
			map_data->width = ft_strlen(map_data->raw[start + i]);
	i = -1;
	while (++i < map_data->height)
	{
		map_data->map[i] = malloc((map_data->width + 1) * sizeof(char));
		if (map_data->map[i] == NULL)
			ft_error(ALLOC);
		ft_memset(map_data->map[i], ' ', map_data->width);
		map_data->map[i][map_data->width] = '\0';
		ft_memcpy(map_data->map[i], map_data->raw[start + i], \
		ft_strlen(map_data->raw[start + i]));
	}
}

static void	set_vectors(char dir, t_game_data *game_data)
{
	if (dir == 'N')
	{
		game_data->vectors[DIR] = (t_vector){0, -1};
		game_data->vectors[CAM] = (t_vector){FOV, 0};
	}
	else if (dir == 'S')
	{
		game_data->vectors[DIR] = (t_vector){0, 1};
		game_data->vectors[CAM] = (t_vector){FOV * -1, 0};
	}
	else if (dir == 'E')
	{
		game_data->vectors[DIR] = (t_vector){-1, 0};
		game_data->vectors[CAM] = (t_vector){0, FOV * -1};
	}
	else
	{
		game_data->vectors[DIR] = (t_vector){1, 0};
		game_data->vectors[CAM] = (t_vector){0, FOV};
	}
}

void	get_player(t_map_data *map_data, t_game_data *game_data)
{
	t_ushort	x;
	t_ushort	y;

	y = 0;
	while (++y < map_data->height)
	{
		x = 0;
		while (map_data->map[y][++x])
		{
			if (map_data->map[y][x] == 'N' || map_data->map[y][x] == 'S' || \
			map_data->map[y][x] == 'E' || map_data->map[y][x] == 'W')
			{
				if (game_data->vectors[POS].x != 0 \
				&& game_data->vectors[POS].y != 0)
					ft_error(ONE_PLYR);
				game_data->vectors[POS].x = (double)x + 0.5;
				game_data->vectors[POS].y = (double)y + 0.5;
				set_vectors(map_data->map[y][x], game_data);
				map_data->map[y][x] = '0';
			}
			else if (map_data->map[y][x] != '0' && map_data->map[y][x] != '1' \
			&& map_data->map[y][x] != ' ')
				ft_error(INV_CHAR);
		}
	}
}
