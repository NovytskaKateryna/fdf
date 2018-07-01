/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 16:10:51 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/07 11:04:48 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

int		hook_rotation(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
		mlx->angle[0] += 0.09;
	if (keycode == 1)
		mlx->angle[0] -= 0.09;
	if (keycode == 2)
		mlx->angle[1] += 0.09;
	if (keycode == 0)
		mlx->angle[1] -= 0.09;
	if (keycode == 7)
		mlx->angle[2] -= 0.09;
	if (keycode == 8)
		mlx->angle[2] += 0.09;
	if (keycode == 31 && mlx->speed < 0.1)
		mlx->speed += 0.01;
	if (keycode == 35 && mlx->speed > 0.01)
		mlx->speed -= 0.01;
	return (0);
}

int		hook_bottom_color(int keycode, t_mlx *mlx)
{
	int	r;
	int	g;
	int	b;

	r = ((mlx->color[0] >> 16) & 0xFF);
	g = ((mlx->color[0] >> 8) & 0xFF);
	b = (mlx->color[0] & 0xFF);
	if (keycode == 15 && r < 253)
		r += 3;
	if (keycode == 5 && g < 253)
		g += 3;
	if (keycode == 11 && b < 253)
		b += 3;
	if (keycode == 17 && r > 1)
		r -= 3;
	if (keycode == 4 && g > 1)
		g -= 3;
	if (keycode == 45 && b > 2)
		b -= 3;
	mlx->color[0] = (r << 16 | g << 8 | b);
	if (keycode == 29)
		mlx->color[0] = BOTTOM;
	return (0);
}

int		hook_top_color(int keycode, t_mlx *mlx)
{
	int	r;
	int	g;
	int	b;

	r = ((mlx->color[2] >> 16) & 0xFF);
	g = ((mlx->color[2] >> 8) & 0xFF);
	b = (mlx->color[2] & 0xFF);
	if (keycode == 15 && r < 253)
		r += 3;
	if (keycode == 5 && g < 253)
		g += 3;
	if (keycode == 11 && b < 253)
		b += 3;
	if (keycode == 17 && r > 1)
		r -= 3;
	if (keycode == 4 && g > 1)
		g -= 3;
	if (keycode == 45 && b > 2)
		b -= 3;
	mlx->color[2] = (r << 16 | g << 8 | b);
	if (keycode == 29)
		mlx->color[2] = TOP;
	return (0);
}

int		hook_depth(int keycode, t_mlx *mlx)
{
	int	sub;
	int	n;

	n = -1;
	while (++n < mlx->points)
	{
		if (mlx->dots[n].z != 0)
		{
			sub = 1;
			while ((mlx->dots[n].z % sub) == 0)
				sub++;
			if (keycode == 69)
				mlx->dots[n].z += sub;
			if (keycode == 78)
				mlx->dots[n].z -= sub;
			if (mlx->dots[n].z < 0 && mlx->speed > 0)
				mlx->speed *= -1;
		}
	}
	return (0);
}

int		key_events(int keycode, t_mlx *mlx)
{
	hook_rotation(keycode, mlx);
	hook_top_color(keycode, mlx);
	hook_bottom_color(keycode, mlx);
	hook_depth(keycode, mlx);
	if (keycode == 53)
		program_exit(mlx);
	if (keycode == 67)
		initial_drawing(mlx);
	if (keycode == 126)
		mlx->transl[1] -= 10;
	if (keycode == 125)
		mlx->transl[1] += 10;
	if (keycode == 123)
		mlx->transl[0] -= 10;
	if (keycode == 124)
		mlx->transl[0] += 10;
	if (keycode == 18)
		win_reopen(mlx, 50);
	if (keycode == 19)
		win_reopen(mlx, -50);
	draw(mlx);
	return (0);
}
