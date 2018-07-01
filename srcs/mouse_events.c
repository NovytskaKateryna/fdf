/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 11:20:18 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/07 11:09:48 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		mouse_off(int button, int x, int y, t_mlx *mlx)
{
	int i;
	int j;

	i = x;
	j = y;
	if (button == 1)
		mlx->mouse_click = 0;
	return (0);
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->mouse_click == 1 &&
			(x > 0 && x < mlx->w_width) && (y > 0 && y < mlx->w_height))
	{
		if (y > mlx->mouse[1])
			mlx->angle[0] -= mlx->speed;
		if (y < mlx->mouse[1])
			mlx->angle[0] += mlx->speed;
		if (x > mlx->mouse[0])
			mlx->angle[1] += mlx->speed;
		if (x < mlx->mouse[0])
			mlx->angle[1] -= mlx->speed;
		mlx->mouse[0] = x;
		mlx->mouse[1] = y;
		draw(mlx);
	}
	return (0);
}

int		mouse_events(int button, int x, int y, t_mlx *mlx)
{
	if (button == 5)
		mlx->scale += 0.5;
	if (button == 4)
	{
		if (mlx->scale > 1)
			mlx->scale -= 0.5;
	}
	if (button == 1)
	{
		mlx->mouse[0] = x;
		mlx->mouse[1] = y;
		mlx->mouse_click = 1;
		mouse_move(x, y, mlx);
	}
	draw(mlx);
	return (0);
}
