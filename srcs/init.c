/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:19:37 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/13 16:25:02 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>
#include "fractol.h"
#include "libft.h"

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		free_exit(vars, 1);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, TITLE);
	if (!vars->win)
		free_exit(vars, 1);
	vars->data.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->data.img)
		free_exit(vars, 1);
	vars->data.addr = mlx_get_data_addr(vars->data.img, \
	&vars->data.bits_per_pixel, &vars->data.line_length, &vars->data.endian);
	if (!vars->data.addr)
		free_exit(vars, 1);
	vars->params.move_x = 0;
	vars->params.move_y = 0;
	vars->params.zoom = 0;
	vars->params.color.a = 0;
	vars->params.color.r = 0;
	vars->params.color.g = 0;
	vars->params.color.b = 0;
}

void	init_hooks(t_vars *vars)
{
	mlx_hook(vars->win, KeyRelease, KeyReleaseMask, key_press, vars);
	mlx_hook(vars->win, DestroyNotify, NoEventMask, close_window, vars);
}

int	init_fractal(t_vars *vars)
{
	int			win_x;
	int			win_y;
	
	memset(vars->data.addr, 0, WIDTH * sizeof(t_color) * HEIGHT);
	win_y = 0;
	while (win_y <= HEIGHT)
	{
		win_x = 0;
		while (win_x <= WIDTH)
		{
			vars->params.color = calculate_color(vars, win_x, win_y);
			render_color(vars, win_x, win_y);
			win_x++;
		}
		win_y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}


void	init_all(t_vars *vars)
{
	init_vars(vars);
	init_hooks(vars);
	init_fractal(vars);
}
