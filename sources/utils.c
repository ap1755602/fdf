/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:49:47 by frodney           #+#    #+#             */
/*   Updated: 2021/08/02 14:33:09 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	terminate(char const *s)
{
	ft_putendl_fd(s, 1);
	exit(1);
}

float	maxfloat(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	modfloat(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

int	input_deals(int key, t_format *fdf)
{
	if (key == 126 || key == 13)
		fdf->move_y -= 10;
	if (key == 125 || key == 1)
		fdf->move_y += 10;
	if (key == 123 || key == 0)
		fdf->move_x -= 10;
	if (key == 124 || key == 2)
		fdf->move_x += 10;
	if (key == 53)
		exit(1);
	if (key == 6)
		fdf->zoom += 10;
	if (key == 7)
		fdf->zoom -= 10;
	if (key == 116)
		fdf->relief += 0.2;
	if (key == 121)
		fdf->relief -= 0.2;
	if (key == 115)
		fdf->angle += 0.1;
	if (key == 119)
		fdf->angle += 0.1;
	mlx_clear_window(fdf->mlx, fdf->window);
	draw(fdf);
	return (0);
}
