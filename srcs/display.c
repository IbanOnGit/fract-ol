/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:03:44 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/07 19:09:48 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "libft.h"
#include <math.h>

double	get_sqrt_complex(t_complex z)
{
	double	res;
	double	a;
	double	b;

	a = pow(z.z_i, 2);
	b = pow(z.z_r, 2);
	res = sqrt(a + b);
	return (res);
}

int	julia(t_complex p)
{
	int	nb_iteration;
	t_complex	c;
	t_complex	z;
	t_complex	new_z;
	
	nb_iteration = 0;
	c.z_i = 0.5;
	c.z_r = -0.5;
	z.z_i = pow(p.z_i, 2) + c.z_i;
	z.z_r = pow(p.z_r, 2) + c.z_r;
	while (nb_iteration <= MAX_ITERATION)
	{
		
		new_z.z_i = pow(z.z_i, 2);
		new_z.z_r = pow(z.z_r, 2);
		nb_iteration++;	
	}
	if (nb_iteration >= MAX_ITERATION)
		return (MAX_ITERATION);
	return (0);
}

int	mandelbrot(t_complex p)
{
	(void)p;
	return (0);
}

int	calculate_limit(char *name, int x, int y)
{
	int			i;
	t_complex	z;

	i = 0;
	z.z_i = x / WIDTH / CENTER_X;
	z.z_r = y / HEIGHT / CENTER_Y;
	if (!ft_strncmp(name, "julia", 6))
		i = julia(z);
	else if (!ft_strncmp(name, "mandelbrot", 11))
		i = mandelbrot(z);
	return (i);
}

