/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:29:46 by frodney           #+#    #+#             */
/*   Updated: 2021/08/01 22:44:51 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	height_weight(t_format *data, char *file_name)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_name, O_RDONLY, 0);
	if (get_next_line(fd, &line) < 0)
		terminate ("Error file reading");
	data->height++;
	data->width = count_words(line, ' ');
	if (!data->width)
		terminate ("Error file reading");
	free(line);
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
}

static void	fill_z_map(int *z_line, char *line)
{
	char	**nums;
	int		i;

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

void	read_map(char *file_name, t_format *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	data->height = 0;
	data->width = 0;
	height_weight(data, file_name);
	data->z_map = (int **)malloc(sizeof(int *) * (data->height));
	while (i <= data->height)
		data->z_map[i++] = (int *)malloc(sizeof(int) * (data->width));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_z_map(data->z_map[i], line);
		free(line);
		i++;
	}
	fill_z_map(data->z_map[i], line);
	free(line);
	close(fd);
}
