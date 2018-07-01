/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:16:38 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/05 16:43:13 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double	**rotation_matrix(double a, double b, double c)
{
	double	**matrix;
	int		n;

	n = -1;
	matrix = (double**)malloc(sizeof(double*) * 3);
	while (++n < 3)
		matrix[n] = (double*)malloc(sizeof(double) * 3);
	matrix[0][0] = 0.5 * (cos(b + c) + cos(b - c));
	matrix[0][1] = 0.5 * (sin(b - c) - sin(b + c));
	matrix[0][2] = sin(b);
	matrix[1][0] = 0.25 * (cos(a - b + c) - cos(a + b + c) -
			cos(a + b - c) + cos(a - b - c) + 2 * sin(a + c) - 2 * sin(a - c));
	matrix[1][1] = 0.25 * (2 * cos(a + c) + 2 * cos(a - c) +
		sin(a + b + c) - sin(-a + b + c) - sin(a - b + c) - sin(a + b - c));
	matrix[1][2] = 0.5 * (-sin(a + b) - sin(a - b));
	matrix[2][0] = 0.25 * (-2 * cos(a + c) + 2 * cos(a - c) - sin(a + b + c) -
		sin(-a + b + c) - sin(a + b - c) - sin(-a + b - c));
	matrix[2][1] = 0.25 * (-cos(a + b + c) - cos(-a + b + c) + cos(a - b + c) +
		cos(a + b - c) + 2 * sin(a + c) + 2 * sin(a - c));
	matrix[2][2] = 0.5 * (cos(a + b) + cos(a - b));
	return (matrix);
}

t_cords	*point_color(t_cords *n_p, t_cords *p, t_mlx *mlx)
{
	int	n;

	n = -1;
	while (++n < mlx->points)
	{
		n_p[n].color = p[n].color;
		if (p[n].color == 0)
		{
			if (p[n].z < 0)
				n_p[n].color = mlx->color[0];
			if (p[n].z == 0)
				n_p[n].color = mlx->color[1];
			if (p[n].z > 0)
				n_p[n].color = mlx->color[2];
		}
	}
	return (n_p);
}

t_cords	*rotation(t_cords *p, t_mlx *mlx)
{
	int		n;
	double	**m;
	t_cords	*n_p;

	n = -1;
	m = rotation_matrix(mlx->angle[0], mlx->angle[1], mlx->angle[2]);
	n_p = (t_cords*)malloc(sizeof(t_cords) * mlx->points);
	while (++n < mlx->points)
	{
		n_p[n].x = (p[n].x * m[0][0] + p[n].y * m[1][0] +
				p[n].z * m[2][0]) * mlx->scale;
		n_p[n].y = (p[n].x * m[0][1] + p[n].y * m[1][1] +
				p[n].z * m[2][1]) * mlx->scale;
		n_p[n].z = (p[n].x * m[0][2] + p[n].y * m[1][2] +
				p[n].z * m[2][2]) * mlx->scale;
	}
	n_p = point_color(n_p, p, mlx);
	n = -1;
	while (++n < 3)
		ft_memdel((void*)&m[n]);
	free(m);
	return (n_p);
}
