/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:00:53 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/05/01 10:57:29 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include <stdlib.h>
#include <math.h>

void	free_exit(t_vars *vars, int err_code)
{
	if (vars->data.img)
		mlx_destroy_image(vars->mlx, vars->data.img);
	if (vars->mlx)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		//mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(err_code);
}

void	put_pixel(t_vars *vars, int x, int y)
{
	char	*dst;

	dst = vars->data.addr + \
	(y * vars->data.line_length + x * (vars->data.bits_per_pixel / 8));
	*(unsigned int *)dst = vars->params.color.color;
}

double	pow_complex(t_complex z)
{
	return (z.z_i * z.z_i + z.z_r * z.z_r);
}

double	absolute_value(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	calculate_color(t_vars *vars, int x, int y)
{
	t_color			color;
	unsigned int	nb_iteration;

	nb_iteration = calculate_limit(vars, x, y);
	if (nb_iteration >= vars->params.max_iteration)
		color.color = 0x00000000;
	else
	{
		//differents colors styles :
		
		//color.r = cos(nb_iteration) * vars->params.move_color.r;
		//color.g = sin(nb_iteration) * vars->params.move_color.g;
		//color.b = tan(nb_iteration) * vars->params.move_color.b;
		
		//color.r = tan(nb_iteration) * vars->params.move_color.r;
		//color.g = tan(nb_iteration) * vars->params.move_color.g;
		//color.b = tan(nb_iteration) * vars->params.move_color.b;
	
		//Most psychedelic
			
		color.r = (int)(pow(nb_iteration, 1.5) * vars->params.move_color.r) % 255;
		color.g = (int)(pow(nb_iteration, 1.6) * vars->params.move_color.g) % 255;
		color.b = (int)(pow(nb_iteration, 1.2) * vars->params.move_color.b) % 255;
	}
	vars->params.color = color;
}
