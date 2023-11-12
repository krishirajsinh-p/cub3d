/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:12:51 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/12 22:53:02 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define ARG "cub3D: illegal cub3D command\nusage:\t./cub3D <path to map>\n"
# define EXT "Error: map file should have .cub extension\n"
# define KEY "Error: keys in the map are not as expected\n"
# define RGB "Error: RGB values should be in the range [0,255]\n"

# define ALLOC "Error: Memory allocation failure\n"
# define O_MAP "Error: map has open boundary\n"
# define NO_PLYR "Error: no player in the map\n"
# define MULT_PLYR "Error: multiple players in the map\n"

typedef unsigned short	t_ushort;

enum e_key
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	C = 4,
	F = 5
};

enum e_rgb
{
	R = 0,
	G = 1,
	B = 2
};

typedef struct s_map_data
{
	t_string	*raw;
	t_string	texture[4];
	t_ushort	floor[3];
	t_ushort	ceil[3];
	t_string	*map;
}	t_map_data;

//main.c
void	ft_error(t_string error_message);
void	parser(t_string file, t_map_data *map_data);

//parser.c
void	get_raw(t_string file, t_map_data *map_data);
void	check_keys(t_map_data *map_data, char keys[6][3]);
void	get_textures(t_map_data *map_data, char text_key[4][3]);
void	get_colors(t_map_data *map_data);
void	check_rgb_values(t_map_data *map_data);

//parser2.c
int		get_start_and_end(t_map_data *map_data);

#endif
