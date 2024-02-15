/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1024/02/02 17:18:37 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/15 19:25:35 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include "fractol.h"

void	reset_params(t_vars *vars)
{
	vars->params.move_y = 0;
	vars->params.move_x = 0;
	vars->params.zoom = 1;
	vars->params.move_color.r = 255;
	vars->params.move_color.g = 255;
	vars->params.move_color.b = 255;
	vars->params.max_iteration = 50;
	vars->params.c.z_i = 0;
	vars->params.c.z_r = 0;
}

void	modify_complex(t_vars *vars, int keycode)
{
	if (keycode == XK_z)
	{
		vars->params.c.z_r += 0.01;
		vars->params.c.z_i += 0.01;
	}
	else
	{
		vars->params.c.z_r -= 0.01;
		vars->params.c.z_i -= 0.01;
	}
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		close_window(vars);
	else if (keycode == XK_1)
		vars->params.name = "mandelbrot";
	else if (keycode == XK_2)
		vars->params.name = "julia";
	else if (keycode == XK_3)
		vars->params.name = "ship";
	else if (keycode == XK_Down || keycode == XK_Up)
		modify_y(vars, keycode);
	else if (keycode == XK_Left || keycode == XK_Right)
		modify_x(vars, keycode);
	else if (keycode == XK_i || keycode == XK_o)
		modify_zoom(vars, keycode);
	else if (keycode == XK_space)
		reset_params(vars);
	else if (keycode == XK_minus || keycode == XK_equal)
		modify_iteration(vars, keycode);
	else if (keycode == XK_z || keycode == XK_a)
		modify_complex(vars, keycode);
	else if (keycode == XK_a || \
	keycode == XK_r || keycode == XK_g || keycode == XK_b)
		modify_colors(vars, keycode);
	return (0);
}

int	close_window(t_vars *vars)
{
	free_exit(vars, 0);
	return (0);
}
