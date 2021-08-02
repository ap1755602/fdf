/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:50:16 by frodney           #+#    #+#             */
/*   Updated: 2021/08/02 14:24:57 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_format
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	int		zoom;
	int		color;
	int		**z_map;
	int		move_x;
	int		move_y;
	float	relief;
	float	angle;
}	t_format;

typedef struct s_coords
{
	int			z0;
	int			z1;
	float		x0;
	float		y0;
	float		x1;
	float		y1;
}	t_coords;

int		main(int argc, char **argv);
void	read_map(char *file_name, t_format *data);
void	terminate(char const *s);
void	draw_line(t_coords coords, t_format *data);
void	draw(t_format *data);
float	maxfloat(float a, float b);
float	modfloat(float i);
int		input_deals(int key, t_format *fdf);

#endif
