/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:53:09 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/15 19:54:27 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

void	error_exit(void)
{
	ft_printf\
	("Available fractals are : 1 (Mandelbrot), 2 (Julia), 3 (Burning Ship)");
	exit(0);
}

void	parse_args(int argc, char **argv, t_vars *vars)
{
	if (argc >= 2 && argc <= 4)
	{
		if (!ft_strncmp(argv[1], "1", 2))
			vars->params.name = "mandelbrot";
		else if (!ft_strncmp(argv[1], "2", 2))
			vars->params.name = "julia";
		else if (!ft_strncmp(argv[1], "3", 2))
			vars->params.name = "ship";
		else
			error_exit();
	}
	else 
		error_exit();
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	parse_args(argc, argv, &vars);
	init_all(&vars);
	mlx_loop(vars.mlx);
}
