/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:47:29 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/07 12:54:28 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_errors(int ac, char **av, int message)
{
	int	fd;

	if (ac != 2)
	{
		ft_putendl("Usage: ./fdf <file_name>");
		exit(0);
	}
	else if (message == 1)
	{
		ft_putendl("Map is incorrect.");
		exit(0);
	}
	else if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("File does not exist.");
		exit(0);
	}
	else if (read(fd, NULL, 0) == -1)
	{
		ft_putendl("Usage: ./fdf <file_name>");
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		n;
	int		fd;

	n = -1;
	ft_errors(argc, argv, 0);
	fd = open(argv[1], O_RDONLY);
	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->line = (t_ln*)malloc(sizeof(t_ln));
	if (count_params(fd, mlx) == 0)
		ft_errors(argc, argv, 1);
	if (mlx->points == 0)
	{
		ft_putendl("File is empty.");
		exit(0);
	}
	mlx->dots = read_file(argv[1], mlx->points);
	while (++n < mlx->points)
	{
		mlx->dots[n].x = mlx->dots[n].x - mlx->map_width / 2;
		mlx->dots[n].y = mlx->map_height / 2 - mlx->dots[n].y;
	}
	make_wireframe(mlx);
	return (0);
}
