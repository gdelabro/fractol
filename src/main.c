/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:40:02 by gdelabro          #+#    #+#             */
/*   Updated: 2016/12/16 19:50:22 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void			put_text(t_fract *t)
{
	char *text;
	char *nb;

	nb = ft_itoa(t->imax);
	text = ft_strjoin("iterations : ", nb);
	mlx_string_put(t->mlx, t->win, 10, 10, 0xFFFFFF, text);
	ft_strdel(&text);
	ft_strdel(&nb);
}

static void		color_selector(t_fract *t, int keycode)
{
	t->tmp = t->color;
	keycode == 18 && t->tmp == 1 ? t->color = 256 : 0;
	keycode == 18 && t->tmp == 256 ? t->color = 256 * 256 : 0;
	keycode == 18 && t->tmp == 256 * 256 ? t->color = 257 : 0;
	keycode == 18 && t->tmp == 257 ? t->color = 256 * 256 + 1 : 0;
	keycode == 18 && t->tmp == 256 * 256 + 1 ? t->color = 1 : 0;
}

static int		my_key_funct(int keycode, void *param)
{
	t_fract	*t;
	int		p;

	ft_putnbr(keycode);
	ft_putendl("");
	t = (t_fract*)param;
	p = t->p;
	keycode == 53 ? exit(0) : 0;
	keycode == UP ? t->y1 += 30 / t->zoom : 0;
	keycode == DOWN ? t->y1 -= 30 / t->zoom : 0;
	keycode == LEFT ? t->x1 += 30 / t->zoom : 0;
	keycode == RIGHT ? t->x1 -= 30 / t->zoom : 0;
	keycode == 69 && t->imax < 400 ? t->imax += 1 : 0;
	keycode == 78 && t->imax > 1 ? t->imax -= 1 : 0;
	keycode == 35 && !ft_strcmp(t->str, "julia") && p == 1 ? t->p = 0 : 0;
	keycode == 35 && !ft_strcmp(t->str, "julia") && p == 0 ? t->p = 1 : 0;
	color_selector(t, keycode);
	keycode == 17 ? t_init(t, t->str) : 0;
	!ft_strcmp(t->str, "mandel") ? ft_mandelbrot(*t) : 0;
	!ft_strcmp(t->str, "julia") ? ft_julia(*t) : 0;
	!ft_strcmp(t->str, "ship") ? ft_burningship(*t) : 0;
	put_text(t);
	return (1);
}

int				main(int argc, char **argv)
{
	t_fract t;

	if (argc != 2 || (ft_strcmp(argv[1], "mandel")
			&& ft_strcmp(argv[1], "julia") && ft_strcmp(argv[1], "ship")))
	{
		ft_putendl("usage : ./fractol \"mandel\", \"julia\", \"ship\"");
		return (0);
	}
	t_init(&t, argv[1]);
	t.mlx = mlx_init();
	t.win = mlx_new_window(t.mlx, t.imgx, t.imgy, "Fractol");
	t.img = mlx_new_image(t.mlx, t.imgx, t.imgy);
	t.img_ptr = mlx_get_data_addr(t.img, &t.bpp, &t.sl, &t.endian);
	!ft_strcmp(argv[1], "mandel") ? ft_mandelbrot(t) : 0;
	!ft_strcmp(argv[1], "julia") ? ft_julia(t) : 0;
	!ft_strcmp(t.str, "ship") ? ft_burningship(t) : 0;
	mlx_key_hook(t.win, my_key_funct, &t);
	put_text(&t);
	mlx_mouse_hook(t.win, zoom_hook, &t);
	mlx_hook(t.win, 6, 1L < 6, mouse_move, &t);
	mlx_loop(t.mlx);
	return (0);
}
