#include "fdf.h"

static void	height_weight(t_fdf *data, char *file_name)
{
	// Файл должен содержать минимум одну строку и в строке он должен содержать минимум
	// одно число
	int		fd;
	char	*line;
	int		i;

	data->height = 0;
	data->width = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (get_next_line(fd, &line) < 0)
		terminate ("Error file reading");
	data->height++;
	data->width = count_words(line, ' ');
	if (!data->width)
		terminate ("Error file reading");
	free(line);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		i = count_words(line, ' ');
		if (!i)
			terminate ("Error file reading");
		data->height++;
		free (line);
	}
	close (fd);
	i = count_words(line, ' ');
	if (i)
		data->height++;
	free (line);
	line = NULL;
	printf ("%d\n", data->height);
	printf ("%d\n", data->width);
}

static void	fill_matrix(int *z_line, char *line)
{
	char **nums;
	int	i;
	i = 0;
	nums = ft_split(line, ' ');
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free (nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	height_weight(data, file_name);
//=============================
	// data->height = 2;
	// data->width = 2;

	printf ("ps\n");
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height));
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	fill_matrix(data->z_matrix[i], line);
	free(line);
	close(fd);
}
