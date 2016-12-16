/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:42:23 by gdelabro          #+#    #+#             */
/*   Updated: 2016/12/16 19:52:44 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	t_init_mandel(t_fract *t)
{
	t->x1 = -2.1;
	t->y1 = -1.2;
	t->imax = 50;
	t->x = -1;
	t->z_i = 0;
	t->z_r = 0;
	t->imgx = 800;
	t->imgy = 800;
	t->zoom = 300;
	t->color = 1;
	t->p = 1;
}

static void	t_init_burningship(t_fract *t)
{
	t->x1 = -2.4;
	t->y1 = -2.1;
	t->imax = 50;
	t->x = -1;
	t->z_i = 0;
	t->z_r = 0;
	t->imgx = 800;
	t->imgy = 800;
	t->zoom = 200;
	t->color = 1;
	t->p = 1;
}

static void	t_init_julia(t_fract *t)
{
	t->x1 = -1.4;
	t->y1 = -1.3;
	t->imax = 50;
	t->x = -1;
	t->c_r = 0.285;
	t->c_i = 0.01;
	t->imgx = 800;
	t->imgy = 800;
	t->zoom = 300;
	t->color = 1;
	t->p = 0;
}

void		t_init(t_fract *t, char *str)
{
	t->str = str;
	if (!ft_strcmp(str, "mandel"))
		t_init_mandel(t);
	else if (!ft_strcmp(str, "julia"))
		t_init_julia(t);
	else if (!ft_strcmp(str, "ship"))
		t_init_burningship(t);
	else
		exit(0);
}
