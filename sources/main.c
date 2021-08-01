#include "fdf.h"

int	deal_key(int key)
{
	printf("%d", key);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2 || (argv[1] == NULL))
		terminate ("usage: ./fdf source_file\n");
	fdf = (t_fdf *)malloc(sizeof (t_fdf));
	read_file (argv[1], fdf);
	fdf->zoom = 50;
	fdf->angle = 0.8;
	printf("keke\n");
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "FDF");
	draw(fdf);
	mlx_key_hook(fdf->win, deal_key, NULL);
	mlx_loop(fdf->mlx);
	return (0);
}