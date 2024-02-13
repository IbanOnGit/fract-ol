/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:03:44 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/11 11:15:57 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "libft.h"
#include <math.h>

int	julia(t_complex p)
{
	int			nb_iteration;
	double		tp;
	t_complex	c;

	c.z_r = 0.333;
	c.z_i = -0.666;
	nb_iteration = 0;
	while (nb_iteration < MAX_ITERATION && pow_complex(p) <= 4)
	{
		tp = p.z_r;
		p.z_r = tp * tp - p.z_i * p.z_i + c.z_r;
		p.z_i = 2 * tp * p.z_i + c.z_i;
		nb_iteration++;
	}
	return (nb_iteration);
}

int	mandelbrot(t_complex p)
{
	int			nb_iteration;
	double		tp;
	t_complex	c;

	c.z_r = -1;
	c.z_i = 0;
	nb_iteration = 0;
	while (nb_iteration < MAX_ITERATION && pow_complex(p) <= 4)
	{
		tp = p.z_r;
		p.z_r = tp * tp - p.z_i * p.z_i + c.z_r;
		p.z_i = 2 * tp * p.z_i + c.z_i;
		nb_iteration++;
	}
	return (nb_iteration);
}

int	ship(t_complex p)
{
	int			nb_iteration;
	double		tp;
	t_complex	c;

	c.z_r = 0;
	c.z_i = 0;
	nb_iteration = 0;
	while (nb_iteration < MAX_ITERATION && pow_complex(p) <= 4)
	{
		tp = p.z_r;
		p.z_r = tp * tp - p.z_i * p.z_i + c.z_r;
		p.z_i = absolute_value(tp * p.z_i) * 2 + c.z_i;
		nb_iteration++;
	}
	return (nb_iteration);
}

int	calculate_limit(char *name, int x, int y)
{
	int			i;
	t_complex	p;

	i = 0;
	p.z_r = ((double)x / (double)WIDTH) * 4 - 2;
	p.z_i = ((double)y / (double)HEIGHT) * 4 - 2;
	if (!ft_strncmp(name, "julia", 6))
		i = julia(p);
	else if (!ft_strncmp(name, "mandelbrot", 11))
		i = mandelbrot(p);	
	else if (!ft_strncmp(name, "ship", 5))
		i = ship(p);
	return (i);
}

