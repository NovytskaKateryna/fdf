/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:38:21 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/06 15:58:23 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw(t_mlx *mlx)
{
	t_cords	*points;

	clear_image(mlx);
	points = rotation(mlx->dots, mlx);
	rendering(mlx, points, mlx->line);
	ft_memdel((void*)&points);
}

void	program_exit(t_mlx *mlx)
{
	free(mlx->dots);
	free(mlx->line);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx);
	exit(0);
}

void	win_reopen(t_mlx *mlx, int increment)
{
	int	s_line;
	int	endian;

	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->w_width += increment;
	mlx->w_height += increment;
	mlx->scale = mlx->w_width / (mlx->map_width + mlx->map_height);
	mlx->transl[0] = mlx->w_width / 2;
	mlx->transl[1] = mlx->w_height / 2;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->w_width, mlx->w_height,
			"MAGIC WINDOW by knovytsk");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->w_width, mlx->w_height);
	mlx->img = mlx_get_data_addr(mlx->img_ptr, &mlx->img_bpp, &s_line, &endian);
	mlx->img_bpp /= 8;
	draw(mlx);
	mlx_hook(mlx->win_ptr, 2, 5, key_events, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_events, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_move, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, mouse_off, mlx);
	mlx_loop(mlx->mlx_ptr);
}
