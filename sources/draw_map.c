/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:29:41 by frodney           #+#    #+#             */
/*   Updated: 2021/08/01 22:45:29 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	isometric(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	format_line(t_coords *coords, t_format *data)
{
	if (coords->z0 || coords->z1)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
	coords->x0 *= data->zoom;
	coords->y0 *= data->zoom;
	coords->x1 *= data->zoom;
	coords->y1 *= data->zoom;
	isometric (&coords->x0, &coords->y0, coords->z0, data->angle);
	isometric (&coords->x1, &coords->y1, coords->z1, data->angle);
	coords->x0 += 600;
	coords->y0 += 150;
	coords->x1 += 600;
	coords->y1 += 150;
}

void	draw_line(t_coords coords, t_format *data)
{
	float	x_step;
	float	y_step;
	float	max;

	coords.z0 = data->z_map[(int)coords.y0][(int)coords.x0];
	coords.z1 = data->z_map[(int)coords.y1][(int)coords.x1];
	format_line(&coords, data);
	x_step = coords.x1 - coords.x0;
	y_step = coords.y1 - coords.y0;
	max = maxfloat(modfloat(x_step), modfloat(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(coords.x0 - coords.x1) || (int)(coords.y0 - coords.y1))
	{
		mlx_pixel_put(data->mlx, data->win,
			coords.x0, coords.y0, data->color);
		coords.x0 += x_step;
		coords.y0 += y_step;
	}
}

void	draw(t_format *data)
{
	t_coords	coords;

	coords.y0 = 0;
	while (coords.y0 < data->height)
	{
		coords.x0 = 0;
		while (coords.x0 < data->width)
		{
			coords.y1 = coords.y0;
			coords.x1 = coords.x0;
			if (coords.x0 < data->width - 1)
			{
				coords.x1++;
				draw_line(coords, data);
				coords.x1--;
			}
			if (coords.y0 < data->height - 1)
			{
				coords.y1++;
				draw_line(coords, data);
			}
			coords.x0++;
		}
		coords.y0++;
	}
}
