/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:01:17 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/04 18:11:31 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		clear_image(t_mlx *mlx)
{
	ft_bzero(mlx->img, mlx->w_width * mlx->w_height * mlx->img_bpp);
}

int			col_gradient(int color1, int color2, double blend)
{
	double	inv_blend;
	int		red;
	int		green;
	int		blue;

	if (color1 == color2)
		return (color1);
	if (blend > 1.0)
		blend = 1.0;
	inv_blend = 1 - blend;
	red = ((color1 >> 16) & 0xFF) * inv_blend + ((color2 >> 16) & 0xFF) * blend;
	green = ((color1 >> 8) & 0xFF) * inv_blend + ((color2 >> 8) & 0xFF) * blend;
	blue = (color1 & 0xFF) * inv_blend + (color2 & 0xFF) * blend;
	return (red << 16 | green << 8 | blue);
}

void		put_img_pixel(t_mlx *mlx, int x, int y, double br)
{
	int	color;
	int	red;
	int	green;
	int	blue;

	if (br > 1.0)
		br = 1.0;
	red = ((mlx->line->color >> 16) & 0xFF) * br;
	green = ((mlx->line->color >> 8) & 0xFF) * br;
	blue = (mlx->line->color & 0xFF) * br;
	color = (red << 16 | green << 8 | blue);
	if ((x > 0 && x < mlx->w_width) && (y > 0 && y < mlx->w_height))
		*(int*)(mlx->img + (x + y * mlx->w_width) * mlx->img_bpp) = color;
}
