/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1024/02/02 17:18:37 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/13 18:27:05 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include "fractol.h"

void	modify_x(t_vars *vars, int keycode)
{
	int	x;

	x = vars->params.move_x;
	printf("before x = %d\n", vars->params.move_x);
	if (keycode == XK_Right)
	{
		if (x + PGCD == WIDTH)
			vars->params.move_x = 0;
		else if (x + PGCD > WIDTH)
			vars->params.move_x = PGCD;
		else
			vars->params.move_x += PGCD;
	}
	else
	{
		if (x - PGCD == 0)
			vars->params.move_x = 0;
		else if (x < PGCD)
			vars->params.move_x =  WIDTH - PGCD;
		else
			vars->params.move_x -= PGCD;
	}
}

void	modify_y(t_vars *vars, int keycode)
{
	int	y;

	y = vars->params.move_y;
	if (keycode == XK_Down)
	{
		if (y + PGCD == HEIGHT)
			vars->params.move_y = 0;
		else if (y + PGCD > HEIGHT)
			vars->params.move_y = PGCD;
		else
			vars->params.move_y += PGCD;
	}
	else
	{
		if (y - PGCD == 0)
			vars->params.move_y = 0;
		else if (y < PGCD)
			vars->params.move_y = HEIGHT - PGCD;
		else
			vars->params.move_y -= PGCD;
	}
}

void	modify_zoom(t_vars *vars, int keycode)
{
	if (keycode == XK_i)
		vars->params.zoom += 10;
	else if (keycode == XK_o && vars->params.zoom >= 10)	
		vars->params.zoom -= 10;
	printf("zoom = %d\n", vars->params.zoom);
}

void	reset_params(t_vars *vars)
{
	vars->params.move_y = 0;
	vars->params.move_x = 0;
	vars->params.zoom = 0;
	vars->params.move_color.r = 255;
	vars->params.move_color.g = 255;
	vars->params.move_color.b = 255;
	vars->params.c.z_i = 0;
	vars->params.c.z_r = 0;
}

void	modify_colors(t_vars *vars, int keycode)
{
	if (keycode == XK_r)
		vars->params.move_color.r += 15;
	if (keycode == XK_g)
		vars->params.move_color.g += 15;
	if (keycode == XK_b)
		vars->params.move_color.b += 15;
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
	else if (keycode == XK_a || \
	keycode == XK_r || keycode == XK_g || keycode == XK_b)
		modify_colors(vars, keycode);
	init_fractal(vars);
	return (0);
}

int	close_window(t_vars *vars)
{
	free_exit(vars, 0);
	return (0);
}
