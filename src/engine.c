/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:13:50 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/30 03:03:26 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	set_ray2(t_ray *r, t_vector *vec)
{
	if (r->dir[X] < 0)
	{
		r->step[X] = -1;
		r->s_dist[X] = (vec[POS].x - r->pos[X]) * r->d_dist[X];
		r->hit_side[X] = WE;
	}
	else
	{
		r->step[X] = 1;
		r->s_dist[X] = (r->pos[X] + 1.0 - vec[POS].x) * r->d_dist[X];
		r->hit_side[X] = EA;
	}
	if (r->dir[Y] < 0)
	{
		r->step[Y] = -1;
		r->s_dist[Y] = (vec[POS].y - r->pos[Y]) * r->d_dist[Y];
		r->hit_side[Y] = NO;
	}
	else
	{
		r->step[Y] = 1;
		r->s_dist[Y] = (r->pos[Y] + 1.0 - vec[POS].y) * r->d_dist[Y];
		r->hit_side[Y] = SO;
	}
}

void	set_ray(t_ray *r, short x, t_vector *vec, mlx_image_t *img)
{
	r->cam_x = (2 * x / (double)img->width - 1);
	r->dir[X] = vec[DIR].x + (vec[CAM].x * r->cam_x);
	r->dir[Y] = vec[DIR].y + (vec[CAM].y * r->cam_x);
	if (r->dir[X])
		r->d_dist[X] = fabs(1 / r->dir[X]);
	else
		r->d_dist[X] = INFINITY;
	if (r->dir[Y])
		r->d_dist[Y] = fabs(1 / r->dir[Y]);
	else
		r->d_dist[Y] = INFINITY;
	r->pos[X] = vec[POS].x;
	r->pos[Y] = vec[POS].y;
	set_ray2(r, vec);
}

void	cast_ray(t_ray *r, t_string *map)
{
	while (true)
	{
		if (r->s_dist[X] < r->s_dist[Y])
		{
			r->s_dist[X] += r->d_dist[X];
			r->pos[X] += r->step[X];
			r->hit_axis = X;
		}
		else
		{
			r->s_dist[Y] += r->d_dist[Y];
			r->pos[Y] += r->step[Y];
			r->hit_axis = Y;
		}
		if (map[r->pos[Y]][r->pos[X]] == '1')
			break ;
	}
	if (r->hit_axis == X)
		r->wall_dist = r->s_dist[X] - r->d_dist[X];
	else
		r->wall_dist = r->s_dist[Y] - r->d_dist[Y];
	if (r->hit_axis == X)
		r->wall_hit = r->hit_side[X];
	else
		r->wall_hit = r->hit_side[Y];
}
