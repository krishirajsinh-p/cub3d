/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:12:51 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/12 20:06:03 by kpuwar           ###   ########.fr       */
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
	t_string		*raw;
	t_string		texture[4];
	unsigned short	floor[3];
	unsigned short	ceil[3];
	t_string		*map;
}	t_map_data;

void	ft_error(t_string error_message);
void	parser(t_string file, t_map_data *map_data);

#endif
