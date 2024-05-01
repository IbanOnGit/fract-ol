/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1024/02/02 17:18:37 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/05/01 08:02:12 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include "fractol.h"

int	mouse_wheel(int keycode, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	modify_zoom(vars, keycode);
	return (0);
}

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
	if (keycode == 6)
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
	printf("key = %d\n", keycode);
	if (keycode == 53)
		close_window(vars);
	else if (keycode == 18)
		vars->params.name = "mandelbrot";
	else if (keycode == 19)
		vars->params.name = "julia";
	else if (keycode == 20)
		vars->params.name = "ship";
	else if (keycode == 125 || keycode == 126)
		modify_y(vars, keycode);
	else if (keycode == 123 || keycode == 124)
		modify_x(vars, keycode);
	else if (keycode == 34 || keycode == 31)
		modify_zoom(vars, keycode);
	else if (keycode == 49)
		reset_params(vars);
	else if (keycode == 12 || keycode == 13)
		modify_iteration(vars, keycode);
	else if (keycode == 6 || keycode == 7)
		modify_complex(vars, keycode);
	else if (keycode == 15 || keycode == 5 || keycode == 11)
		modify_colors(vars, keycode);
	return (0);
}

int	close_window(t_vars *vars)
{
	free_exit(vars, 0);
	return (0);
}
