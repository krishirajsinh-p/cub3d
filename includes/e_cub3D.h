/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_cub3D.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:30:23 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/24 03:35:50 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_CUB3D_H
# define E_CUB3D_H

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

enum e_axis
{
	X = 0,
	Y = 1
};

enum e_vectors
{
	POS = 0,
	DIR = 1,
	CAM = 2
};

enum e_screen_dimensions
{
	S_WIDTH = 1920,
	S_HEIGHT = 1080
};

#endif
