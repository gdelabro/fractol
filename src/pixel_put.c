/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:18:44 by gdelabro          #+#    #+#             */
/*   Updated: 2016/12/16 13:11:53 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	pixel_put(t_fract *t, int color)
{
	color = mlx_get_color_value(t->mlx, color);
	ft_memcpy(t->img_ptr + 4 * t->imgx * t->y + 4 * t->x, &color, 4);
}
