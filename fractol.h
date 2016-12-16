/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:16:19 by gdelabro          #+#    #+#             */
/*   Updated: 2016/12/16 19:48:53 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

typedef struct		s_fract
{
	double			tmp;
	int				x;
	int				y;
	double			x1;
	double			y1;
	double			zoom;
	int				color;
	int				imax;
	int				imgx;
	int				imgy;
	int				i;
	double			z_r;
	double			z_i;
	double			c_r;
	double			c_i;
	void			*mlx;
	void			*win;
	void			*img;
	void			*img_ptr;
	int				*tab;
	char			*str;
	int				endian;
	int				bpp;
	int				sl;
	int				p;
	int				pause;
}					t_fract;

void				t_init(t_fract *t, char *str);
void				ft_mandelbrot(t_fract t);
void				ft_julia(t_fract t);
void				ft_burningship(t_fract t);
void				pixel_put(t_fract *t, int color);
void				put_text(t_fract *t);
int					mouse_move(int x, int y, t_fract *t);
int					zoom_hook(int mousecode, int x, int y, t_fract *t);

#endif
