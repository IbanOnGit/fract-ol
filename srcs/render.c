/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 06:06:55 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/13 18:12:22 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_color(t_vars *vars, int x, int y)
{
	if (x + vars->params.move_x >= WIDTH)
		x = WIDTH - vars->params.move_x;
	else
		x += vars->params.move_x;
	if (y + vars->params.move_y >= HEIGHT)
		y = HEIGHT - vars->params.move_y;
	else
		y += vars->params.move_y;
	put_pixel(vars, x, y);
}

void	render_zoom(t_vars *vars, int keycode)
{
	(void)vars;
	(void)keycode;
}
