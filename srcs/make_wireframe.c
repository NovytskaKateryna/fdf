/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:54:40 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/05 17:39:14 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	initial_drawing(t_mlx *mlx)
{
	mlx->angle[0] = (-176 * M_PI) / 180;
	mlx->angle[1] = (5 * M_PI) / 180;
	mlx->angle[2] = (5 * M_PI) / 180;
	mlx->speed = 0.02;
	mlx->scale = mlx->w_width / (mlx->map_width + mlx->map_height);
	mlx->transl[0] = mlx->w_width / 2;
	mlx->transl[1] = mlx->w_height / 2;
	mlx->color[0] = BOTTOM;
	mlx->color[1] = MIDDLE;
	mlx->color[2] = TOP;
	draw(mlx);
}

void	make_wireframe(t_mlx *mlx)
{
	int	s_line;
	int	endian;

	mlx->w_width = W_WIDTH;
	mlx->w_height = W_HEIGHT;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->w_width, mlx->w_height,
			"MAGIC WINDOW by knovytsk");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->w_width, mlx->w_height);
	mlx->img = mlx_get_data_addr(mlx->img_ptr, &mlx->img_bpp, &s_line, &endian);
	mlx->img_bpp /= 8;
	initial_drawing(mlx);
	instruction(mlx);
	mlx_hook(mlx->win_ptr, 2, 5, key_events, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_events, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_move, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, mouse_off, mlx);
	mlx_loop(mlx->mlx_ptr);
}
