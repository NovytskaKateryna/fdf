/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:48:05 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/07 10:26:16 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"

# define ABS(Value) (((Value) < 0) ? -(Value) : (Value))
# define I(X) ((int)(X))
# define R(X) ((int)(((double)(X)) + 0.5))
# define FP(X) (((double)(X)) - (double)I(X))
# define RF(X) (1.0 - FP(X))

# define BOTTOM 0x8b8b
# define MIDDLE 0xffefd5
# define TOP  0xff6a6a
# define W_WIDTH 1000
# define W_HEIGHT 1000

typedef struct		s_cords
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_cords;

typedef struct		s_ln
{
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	double			dx;
	double			dy;
	double			gradient;
	double			xend;
	double			yend;
	double			intery;
	double			interx;
	int				color;
	int				color1;
	int				color2;
}					t_ln;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	void			*i_win;
	int				points;
	int				map_height;
	int				map_width;
	double			angle[3];
	double			scale;
	int				transl[2];
	int				color[3];
	int				w_width;
	int				w_height;
	char			*img;
	int				img_bpp;
	int				mouse[2];
	int				mouse_click;
	double			speed;
	t_cords			*dots;
	t_ln			*line;
}					t_mlx;

int					count_params(const int fd, t_mlx *mlx);
t_cords				*read_file(char *av, int size);
void				make_wireframe(t_mlx *mlx);
t_cords				*rotation(t_cords *point, t_mlx *mlx);
void				rendering(t_mlx *mlx, t_cords *point, t_ln *ln);
void				put_img_pixel(t_mlx *mlx, int x, int y, double br);
void				clear_image(t_mlx *mlx);
int					col_gradient(int color1, int color2, double blend);
int					key_events(int keycode, t_mlx *mlx);
int					mouse_events(int button, int x, int y, t_mlx *mlx);
int					mouse_move(int x, int y, t_mlx *mlx);
int					mouse_off(int button, int x, int y, t_mlx *mlx);
void				initial_drawing(t_mlx *mlx);
void				draw(t_mlx *mlx);
void				win_reopen(t_mlx *mlx, int increment);
void				instruction(t_mlx *mlx);
void				program_exit(t_mlx *mlx);
#endif
