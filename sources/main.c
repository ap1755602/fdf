/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:29:32 by frodney           #+#    #+#             */
/*   Updated: 2021/08/01 22:44:50 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key)
{
	printf("%d", key);
	return (0);
}

int	main(int argc, char **argv)
{
	t_format	*fdf;

	if (argc != 2 || (argv[1] == NULL))
		terminate ("usage: ./fdf source_file\n");
	fdf = (t_format *)malloc(sizeof (t_format));
	read_map (argv[1], fdf);
	fdf->zoom = 50;
	fdf->angle = 0.8;
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, 1920, 1080, "FDF");
	draw(fdf);
	mlx_key_hook(fdf->window, deal_key, NULL);
	mlx_loop(fdf->mlx);
	return (0);
}
