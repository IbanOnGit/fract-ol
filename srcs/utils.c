/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:00:53 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/11 16:26:20 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "libft.h"
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
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(err_code);
}

void	put_pixel(t_vars *vars, int x, int y)
{
	char	*dst;

	dst = vars->data.addr + \
	(y * vars->data.line_length + x * (vars->data.bits_per_pixel / 8));
	*(unsigned int*)dst = vars->params.color.color;
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

t_color	calculate_color(t_vars *vars, int x, int y)
{
	t_color	color;
	int		nb_iteration;

	nb_iteration = calculate_limit(vars->params.name, x , y);
	if (nb_iteration >= MAX_ITERATION)
		color.color = 0x00000000;
	else
	{
		color.r = sin(nb_iteration) * 667;
		color.g = sin(nb_iteration) * 7.007;
		color.b = sin(nb_iteration) * 61;
		color.a = 0;
	}
	return (color);
}
