/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:19:37 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/02 20:03:01 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
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
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img)
		free_exit(vars, 1);
}

void	init_hooks(t_vars *vars)
{
	mlx_hook(vars->win, KeyRelease, KeyReleaseMask, key_press, vars);
	mlx_hook(vars->win, DestroyNotify, NoEventMask, close_window, vars);
}

void	init_fractal(t_vars *vars, char *name)
{
	if (!ft_strncmp(name, "Julia", 6))
		display_julia(vars);
	else if (!ft_strncmp(name, "Mandelbrot", 11))
		display_mandelbrot(vars);
}

void	init_all(t_vars *vars, char *name)
{
	init_vars(vars);
	init_hooks(vars);
	init_fractal(vars, name);
}
