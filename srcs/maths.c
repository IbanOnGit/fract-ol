/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:03:44 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/20 16:54:32 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "libft.h"
#include <math.h>

int	julia(t_vars *vars, t_complex p)
{
	unsigned int	nb_iteration;
	double			tp;
	t_complex		c;

	c.z_r = -0.33 + vars->params.c.z_r ;
	c.z_i = 0.66 + vars->params.c.z_i;
	nb_iteration = 0;
	while (nb_iteration < vars->params.max_iteration && pow_complex(p) <= 4)
	{
		tp = p.z_r;
		p.z_r = tp * tp - p.z_i * p.z_i + c.z_r;
		p.z_i = 2 * tp * p.z_i + c.z_i;
		nb_iteration++;
	}
	return (nb_iteration);
}

int	mandelbrot(t_vars *vars, t_complex p)
{
	unsigned int	nb_iteration;
	t_complex		z;
	double			tp;

	z.z_r = 0 + vars->params.c.z_r;
	z.z_i = 0 + vars->params.c.z_i;
	nb_iteration = 0;
	while (nb_iteration < vars->params.max_iteration && pow_complex(z) <= 4)
	{
		tp = z.z_r;
		z.z_r = tp * tp - z.z_i * z.z_i + p.z_r;
		z.z_i = 2 * z.z_i * tp + p.z_i;
		nb_iteration++;
	}
	return (nb_iteration);
}

int	ship(t_vars *vars, t_complex p)
{
	unsigned int	nb_iteration;
	t_complex		z;
	double			tp;

	z.z_r = 0 + vars->params.c.z_r;
	z.z_i = 0 + vars->params.c.z_i;
	nb_iteration = 0;
	while (nb_iteration < vars->params.max_iteration && pow_complex(z) <= 4)
	{
		tp = z.z_r;
		z.z_r = tp * tp - z.z_i * z.z_i + p.z_r;
		z.z_i = 2 * absolute_value(z.z_i * tp) + p.z_i;
		nb_iteration++;
	}
	return (nb_iteration);
}

int	calculate_limit(t_vars *vars, int x, int y)
{
	int			i;
	t_complex	p;

	i = 0;
	p.z_r = ((((double)x + ((double)vars->params.move_x)) \
	/ (double)WIDTH) * 4 - 2) / vars->params.zoom;
	p.z_i = ((((double)y + ((double)vars->params.move_y)) \
	/ (double)HEIGHT) * 4 - 2) / vars->params.zoom;
	if (!ft_strncmp(vars->params.name, "julia", 6))
		i = julia(vars, p);
	else if (!ft_strncmp(vars->params.name, "mandelbrot", 11))
		i = mandelbrot(vars, p);
	else if (!ft_strncmp(vars->params.name, "ship", 5))
		i = ship(vars, p);
	return (i);
}
