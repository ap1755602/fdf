#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		zoom;
	int		color;
	int		**z_matrix;
	float	angle;
}	t_fdf;

typedef struct s_coords
{
	float		x0;
	float		y0;
	float		x1;
	float		y1;
	int			z0;
	int			z1;
}	t_coords;

int		main(int argc, char **argv);
void	read_file(char *file_name, t_fdf *data);
void	terminate(char const *s);
void	draw_line(t_coords coords, t_fdf *data);
void	draw(t_fdf *data);
float	maxfloat(float a, float b);
float	modfloat(float i);

#endif
