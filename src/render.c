/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 01:24:29 by kpuwar            #+#    #+#             */
/*   Updated: 2023/11/30 03:00:27 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int32_t	ft_color(int32_t r, int32_t g, int32_t b)
{
	return (r << 24 | g << 16 | b << 8 | 0x000000FF);
}

void	paint_floor_ceil(t_game_data *game_data)
{
	short		*ceil;
	short		*floor;
	mlx_image_t	*img;
	t_ushort	x;
	t_ushort	y;

	ceil = game_data->map_data.ceil;
	floor = game_data->map_data.floor;
	img = game_data->img;
	x = -1;
	while (++x < img->width)
	{
		y = 0;
		while (y < img->height / 2)
			mlx_put_pixel(img, x, y++, ft_color(ceil[R], ceil[G], ceil[B]));
		while (y < img->height)
			mlx_put_pixel(img, x, y++, ft_color(floor[R], floor[G], floor[B]));
	}
}

static void	set_struct(t_texture *t, t_ray *r, t_vector *vec, t_game_data *g)
{
	t->line_height = (g->img->height) / r->wall_dist;
	t->start = (g->img->height / 2) - (t->line_height / 2);
	t->end = (g->img->height / 2) + (t->line_height / 2);
	if (t->start < 0)
		t->start = 0;
	if (t->end >= (int)(g->img->height))
		t->end = g->img->height - 1;
	if (r->hit_axis == X)
		t->wall_x = vec[POS].y + (r->wall_dist * r->dir[Y]);
	else
		t->wall_x = vec[POS].x + (r->wall_dist * r->dir[X]);
	t->wall_x -= floor(t->wall_x);
	t->pxl[X] = t->wall_x * g->walls[r->wall_hit]->width;
	if ((r->hit_axis == X && r->dir[X] > 0) \
	|| (r->hit_axis == Y && r->dir[Y] < 0))
		t->pxl[X] = g->walls[r->wall_hit]->width - t->pxl[X] - 1;
	t->step = (double)(g->walls[r->wall_hit]->height) / t->line_height;
	t->pos = (t->start - (g->img->height / 2) + (t->line_height / 2)) * t->step;
}

void	paint_walls(t_ray *r, short x, t_vector *vec, t_game_data *g)
{
	t_texture		t;
	int32_t			pxl;
	mlx_texture_t	*wall;

	wall = g->walls[r->wall_hit];
	set_struct(&t, r, vec, g);
	while (t.start < t.end)
	{
		t.pxl[Y] = t.pos;
		pxl = (t.pxl[Y] * wall->width + t.pxl[X]) * 4;
		mlx_put_pixel(g->img, x, t.start, ft_color(wall->pixels[pxl + R], \
		wall->pixels[pxl + G], wall->pixels[pxl + B]));
		t.pos += t.step;
		t.start++;
	}
}
