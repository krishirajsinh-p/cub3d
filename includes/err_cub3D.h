/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_cub3D.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:30:20 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/24 03:35:55 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_CUB3D_H
# define ERR_CUB3D_H

# define ALLOC "Error: Memory allocation failure\n"
# define ARG "cub3D: Illegal cub3D command\nusage:\t./cub3D <path to map>\n"
# define EXT "Error: Map file should have .cub extension\n"
# define KEY "Error: Keys in the map are not as expected\n"
# define RGB "Error: RGB values should be in the range [0,255]\n"
# define O_MAP "Error: Map has an opening\n"
# define INV_CHAR "Error: Map has invalid character\n"
# define ONE_PLYR "Error: There has to be exactly one player in the map\n"

#endif
