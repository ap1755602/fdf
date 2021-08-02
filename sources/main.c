/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:29:32 by frodney           #+#    #+#             */
/*   Updated: 2021/08/02 17:19:58 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_format	*fdf;

	if (argc != 2 || (argv[1] == NULL))
		terminate ("usage: ./fdf source_file\n");
	fdf = (t_format *)malloc(sizeof (t_format));
	read_map (argv[1], fdf);
	fdf->zoom = 10;
	fdf->angle = 0.5;
	fdf->move_x = 600;
	fdf->move_y = 150;
	fdf->relief = 1;
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, 1920, 1080, "FDF");
	draw(fdf);
	mlx_key_hook(fdf->window, input_deals, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
