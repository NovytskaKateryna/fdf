/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:24:19 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/06 17:05:49 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		win_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->i_win);
	return (0);
}

void	keys(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 110, 20, 0xfffacd, "^");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 130, 30, 0xfffacd, ">");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 90, 30, 0xfffacd, "<");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 110, 45, 0xfffacd, "v");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 20, 80, 0x8b0000,
			"             R");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 20, 110, 0xff00,
			"             G");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 20, 140, 0xffff,
			"             B");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 250, 80, 0xff6347,
			"			      T");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 180, 110, 0x90ee90,
			"             H");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 180, 140, 0xbfefff,
			"             N");
}

void	options(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 20, 30, 0xfffacd, "Move->");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 170, 30, 0xfffacd,
			"Larger window-> 1");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 380, 30, 0xfffacd,
			"Smaller window-> 2");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 20, 80, 0xfffacd,
			"More red->   ");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 20, 110, 0xfffacd,
			"More green-> ");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 20, 140, 0xfffacd,
			"More blue->  ");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 180, 80, 0xfffacd,
			"Less red->   ");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 180, 110, 0xfffacd,
			"Less green-> ");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 180, 140, 0xfffacd,
			"Less blue->  ");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 380, 400, 0xfffacd,
			"RESET-> *");
}

void	instruction(t_mlx *mlx)
{
	mlx->i_win = mlx_new_window(mlx->mlx_ptr, 600, 500, "INSTRUCTION");
	options(mlx);
	keys(mlx);
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 263, 1, 0xcd8162,
			"KEYBORD");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 80, 170, 0xfffacd,
			"Default color-> 0");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 380, 80, 0xfffacd,
			"Rotation X-> W+  S-");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 380, 110, 0xfffacd,
			"Rotation Y-> A+  D-");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 380, 140, 0xfffacd,
			"Rotation Z-> X+  C- ");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 20, 200, 0xfffacd,
			"Increase depth-> +  Decrease depth-> -");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 270, 260, 0xcd8162, "MOUSE");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 20, 290, 0xfffacd,
			"Scale-> SCROLL UP +  SCROLL DOWN -");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 20, 320, 0xfffacd,
			"Rotation-> LEFT BUTTON and MOVE");
	mlx_string_put(mlx->mlx_ptr, mlx->i_win, 20, 350, 0xfffacd,
			"Mouse rotation speed-> O+  P-");
	mlx_hook(mlx->i_win, 17, 1L << 17, win_exit, mlx);
}
