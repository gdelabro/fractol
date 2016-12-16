/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:42:33 by gdelabro          #+#    #+#             */
/*   Updated: 2016/12/16 19:49:39 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	ft_zoom(int x, int y, t_fract *t)
{
	t->x1 = (x / t->zoom + t->x1) - ((t->zoom * 1.3) / 2);
	t->x1 += ((t->zoom * 1.3) / 2) - (x / (t->zoom * 1.3));
	t->y1 = (y / t->zoom + t->y1) - ((t->zoom * 1.3) / 2);
	t->y1 += ((t->zoom * 1.3) / 2) - (y / (t->zoom * 1.3));
	t->zoom *= 1.3;
	t->imax++;
}

static void	ft_dezoom(int x, int y, t_fract *t)
{
	t->x1 = (x / t->zoom + t->x1) - ((t->zoom / 1.3) / 2);
	t->x1 += ((t->zoom / 1.3) / 2) - (x / (t->zoom / 1.3));
	t->y1 = (y / t->zoom + t->y1) - ((t->zoom / 1.3) / 2);
	t->y1 += ((t->zoom / 1.3) / 2) - (y / (t->zoom / 1.3));
	t->zoom /= 1.3;
	t->imax--;
}

int			mouse_move(int x, int y, t_fract *t)
{
	if (!ft_strcmp(t->str, "julia") && t->p == 0
			&& x > 0 && x < 800 && y > 0 && y < 800)
	{
		ft_putstr("x = ");
		ft_putnbr(t->c_r);
		ft_putstr("   y = ");
		ft_putnbr(t->c_i);
		ft_putendl("");
		t->c_r = (double)x / (t->imgx / 3) - 1.5;
		t->z_r = t->c_r;
		t->c_i = (double)y / (t->imgy / 3) - 1.5;
		t->z_i = t->c_i;
		!ft_strcmp(t->str, "julia") ? ft_julia(*t) : 0;
		!ft_strcmp(t->str, "mandel") ? ft_mandelbrot(*t) : 0;
		!ft_strcmp(t->str, "ship") ? ft_burningship(*t) : 0;
	}
	put_text(t);
	return (1);
}

int			zoom_hook(int mousecode, int x, int y, t_fract *t)
{
	mousecode == 4 || mousecode == 1 ? ft_zoom(x, y, t) : 0;
	mousecode == 5 || mousecode == 2 ? ft_dezoom(x, y, t) : 0;
	!ft_strcmp(t->str, "mandel") ? ft_mandelbrot(*t) : 0;
	!ft_strcmp(t->str, "julia") ? ft_julia(*t) : 0;
	!ft_strcmp(t->str, "ship") ? ft_burningship(*t) : 0;
	put_text(t);
	return (1);
}
