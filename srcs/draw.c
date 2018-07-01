/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:52:44 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/06 18:11:31 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_h_lines(t_ln *l, t_mlx *m)
{
	double	blend;
	double	step;

	blend = 0;
	l->yend = l->y1 + l->gradient * (R(l->x1) - l->x1);
	put_img_pixel(m, R(l->x1), I(l->yend), RF(l->yend) * RF(l->x1 + 0.5));
	put_img_pixel(m, R(l->x1), I(l->yend) + 1, FP(l->yend) * RF(l->x1 + 0.5));
	l->intery = l->yend + l->gradient;
	l->yend = l->y2 + l->gradient * (R(l->x2) - l->x2);
	put_img_pixel(m, R(l->x2), I(l->yend), RF(l->yend) * FP(l->x2 + 0.5));
	put_img_pixel(m, R(l->x2), I(l->yend) + 1, FP(l->yend) * FP(l->x2 + 0.5));
	l->x = R(l->x1);
	step = 1 / (double)(R(l->x2) - 1 - l->x);
	while (++l->x <= R(l->x2) - 1)
	{
		m->line->color = col_gradient(m->line->color1, m->line->color2, blend);
		blend += step;
		put_img_pixel(m, l->x, I(l->intery), RF(l->intery));
		put_img_pixel(m, l->x, I(l->intery) + 1, FP(l->intery));
		l->intery += l->gradient;
	}
}

void	draw_v_lines(t_ln *l, t_mlx *m)
{
	double	blend;
	double	step;

	blend = 0;
	l->xend = l->x1 + l->gradient * (R(l->y1) - l->y1);
	put_img_pixel(m, I(l->xend), R(l->y1), RF(l->xend) * RF(l->y1 + 0.5));
	put_img_pixel(m, I(l->xend), R(l->y1) + 1, FP(l->xend) * RF(l->y1 + 0.5));
	l->interx = l->xend + l->gradient;
	l->xend = l->x2 + l->gradient * (R(l->y2) - l->y2);
	put_img_pixel(m, I(l->xend), R(l->y2), RF(l->xend) * FP(l->y2 + 0.5));
	put_img_pixel(m, I(l->xend), R(l->y2) + 1, FP(l->xend) * FP(l->y2 + 0.5));
	l->y = R(l->y1);
	step = 1 / (double)(R(l->y2) - 1 - l->y);
	while (++l->y <= R(l->y2) - 1)
	{
		m->line->color = col_gradient(m->line->color1, m->line->color2, blend);
		blend += step;
		put_img_pixel(m, I(l->interx), l->y, RF(l->interx));
		put_img_pixel(m, I(l->interx) + 1, l->y, FP(l->interx));
		l->interx += l->gradient;
	}
}

void	swap_data(t_ln *ln, t_mlx *mlx)
{
	int	tmp;

	tmp = mlx->line->color1;
	mlx->line->color1 = mlx->line->color2;
	mlx->line->color2 = tmp;
	ft_swap(&ln->x1, &ln->x2);
	ft_swap(&ln->y1, &ln->y2);
}

void	draw_lines(t_ln *ln, int color1, int color2, t_mlx *mlx)
{
	mlx->line->color = color1;
	mlx->line->color1 = color1;
	mlx->line->color2 = color2;
	ln->dx = (double)ln->x2 - (double)ln->x1;
	ln->dy = (double)ln->y2 - (double)ln->y1;
	if (ABS(ln->dx) > ABS(ln->dy))
	{
		if (ln->x2 < ln->x1)
			swap_data(ln, mlx);
		ln->gradient = ln->dy / ln->dx;
		draw_h_lines(ln, mlx);
	}
	else
	{
		if (ln->y2 < ln->y1)
			swap_data(ln, mlx);
		ln->gradient = ln->dx / ln->dy;
		draw_v_lines(ln, mlx);
	}
}

void	rendering(t_mlx *mlx, t_cords *point, t_ln *ln)
{
	int	n;

	n = 0;
	while (n + 1 < mlx->points)
	{
		ln->x1 = point[n].x + mlx->transl[0];
		ln->y1 = point[n].y + mlx->transl[1];
		ln->x2 = point[n + 1].x + mlx->transl[0];
		ln->y2 = point[n + 1].y + mlx->transl[1];
		draw_lines(ln, point[n].color, point[n + 1].color, mlx);
		n++;
		if ((n + 1) % mlx->map_width == 0)
			n++;
	}
	n = 0;
	while (n + mlx->map_width < mlx->points)
	{
		ln->x1 = point[n].x + mlx->transl[0];
		ln->y1 = point[n].y + mlx->transl[1];
		ln->x2 = point[n + mlx->map_width].x + mlx->transl[0];
		ln->y2 = point[n + mlx->map_width].y + mlx->transl[1];
		draw_lines(ln, point[n].color, point[n + mlx->map_width].color, mlx);
		n++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
