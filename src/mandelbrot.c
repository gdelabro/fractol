/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:07:22 by gdelabro          #+#    #+#             */
/*   Updated: 2016/12/16 17:48:54 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_mandelbrot(t_fract t)
{
	while (++t.x < t.imgx && (t.y = -1))
		while (++t.y < t.imgy)
		{
			t.c_r = t.x / t.zoom + t.x1;
			t.c_i = t.y / t.zoom + t.y1;
			t.z_r = 0;
			t.z_i = 0;
			t.i = 0;
			while (t.z_r * t.z_r + t.z_i * t.z_i < 4 && t.i < t.imax)
			{
				t.tmp = t.z_r;
				t.z_r = t.z_r * t.z_r - t.z_i * t.z_i + t.c_r;
				t.z_i = 2 * t.z_i * t.tmp + t.c_i;
				t.i++;
			}
			if (t.i == t.imax)
				pixel_put(&t, 0);
			else
				pixel_put(&t, (t.i * 255 / t.imax) * t.color);
		}
	mlx_put_image_to_window(t.mlx, t.win, t.img, 0, 0);
}
