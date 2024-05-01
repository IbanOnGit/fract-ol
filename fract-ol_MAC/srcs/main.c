/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:53:09 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/20 17:23:15 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "libft.h"

void	error_exit(t_vars *vars)
{
	ft_printf \
	("\nAvailable fractals are : 1 (Mandelbrot), 2 (Julia), 3 (Burning Ship)");
	ft_printf \
	("\n\nAdd up to 3 more arguments to modify the constant or the zoom\n\n");
	ft_printf \
	("Ex : ./fractal 1 0 -1 5 \n1 is the Mandelbrot fractal, 0 is ");
	ft_printf \
	("the real part, -1 the imaginary part and 5 the zoom factor");
	free_exit(vars, 1);
}

void	parse_args(int argc, char **argv, t_vars *vars)
{
	if (argc >= 2 && argc <= 5)
	{
		if (!ft_strncmp(argv[1], "1", 2))
			vars->params.name = "mandelbrot";
		else if (!ft_strncmp(argv[1], "2", 2))
			vars->params.name = "julia";
		else if (!ft_strncmp(argv[1], "3", 2))
			vars->params.name = "ship";
		else
			error_exit(vars);
		if (argc >= 3)
			vars->params.c.z_r = ft_atoi(argv[2]);
		if (argc >= 4)
			vars->params.c.z_i = ft_atoi(argv[3]);
		if (argc == 5)
			vars->params.zoom = ft_atoi(argv[4]);
	}
	else
		error_exit(vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	init_all(&vars);
	parse_args(argc, argv, &vars);
	mlx_loop(vars.mlx);
}
