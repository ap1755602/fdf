/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:29:41 by frodney           #+#    #+#             */
/*   Updated: 2021/08/02 14:04:05 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	isometric(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	format_line(t_coords *coords, t_format *fdf)
{
	if (coords->z0 || coords->z1)
		fdf->color = 0xe80c0c;
	else
		fdf->color = 0xffffff;
	coords->x0 *= fdf->zoom;
	coords->y0 *= fdf->zoom;
	coords->x1 *= fdf->zoom;
	coords->y1 *= fdf->zoom;
	isometric (&coords->x0, &coords->y0, coords->z0, fdf->angle);
	isometric (&coords->x1, &coords->y1, coords->z1, fdf->angle);
	coords->x0 += fdf->move_x;
	coords->y0 += fdf->move_y;
	coords->x1 += fdf->move_x;
	coords->y1 += fdf->move_y;
}

void	draw_line(t_coords coords, t_format *fdf)
{
	float	x_step;
	float	y_step;
	float	max;

	coords.z0 = fdf->z_map[(int)coords.y0][(int)coords.x0];
	coords.z1 = fdf->z_map[(int)coords.y1][(int)coords.x1];
	coords.z0 *= fdf->relief;
	coords.z1 *= fdf->relief;
	format_line(&coords, fdf);
	x_step = coords.x1 - coords.x0;
	y_step = coords.y1 - coords.y0;
	max = maxfloat(modfloat(x_step), modfloat(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(coords.x0 - coords.x1) || (int)(coords.y0 - coords.y1))
	{
		mlx_pixel_put(fdf->mlx, fdf->window,
			coords.x0, coords.y0, fdf->color);
		coords.x0 += x_step;
		coords.y0 += y_step;
	}
}

void	draw(t_format *fdf)
{
	t_coords	coords;

	coords.y0 = 0;
	while (coords.y0 < fdf->height)
	{
		coords.x0 = 0;
		while (coords.x0 < fdf->width)
		{
			coords.y1 = coords.y0;
			coords.x1 = coords.x0;
			if (coords.x0 < fdf->width - 1)
			{
				coords.x1++;
				draw_line(coords, fdf);
				coords.x1--;
			}
			if (coords.y0 < fdf->height - 1)
			{
				coords.y1++;
				draw_line(coords, fdf);
			}
			coords.x0++;
		}
		coords.y0++;
	}
}
