/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:54:21 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/05 13:00:11 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			record_coords(char *line, int n_line, t_cords *point, int n)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i])
	{
		if (ft_isalpha(*split[i]))
		{
			ft_putendl("Map has incorrect symbol.");
			exit(0);
		}
		point[n].x = i;
		point[n].y = n_line;
		point[n].z = ft_atoi(split[i]);
		point[n].color = ft_atoi_hex(split[i]);
		ft_strdel(&split[i]);
		n++;
		i++;
	}
	free(split);
	split = NULL;
	return (n);
}

t_cords		*read_file(char *av, int size)
{
	int		n_line;
	int		n;
	int		fd;
	char	*line;
	t_cords	*point;

	n_line = 0;
	n = 0;
	fd = open(av, O_RDONLY);
	point = (t_cords*)malloc(sizeof(t_cords) * size);
	while (get_next_line(fd, &line))
	{
		n = record_coords(line, n_line, point, n);
		free(line);
		n_line++;
	}
	close(fd);
	return (point);
}

int			count_params(const int fd, t_mlx *mlx)
{
	char	*line;
	int		i;
	char	**split_for_count;

	mlx->points = 0;
	mlx->map_height = 0;
	mlx->map_width = 0;
	while (get_next_line(fd, &line))
	{
		split_for_count = ft_strsplit(line, ' ');
		i = -1;
		while (split_for_count[++i])
			ft_strdel(&split_for_count[i]);
		if (mlx->map_width == 0)
			mlx->map_width = i;
		else if (i != mlx->map_width)
			return (0);
		free(split_for_count);
		free(line);
		mlx->points = mlx->points + i;
		mlx->map_height++;
	}
	close(fd);
	return (1);
}
