/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:51:44 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/02 20:06:48 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1080
# define HEIGHT 1920
# define TITLE "fractol"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_vars;

void	init_all(t_vars *vars, char *name);
void	init_vars(t_vars *vars);
void	free_exit(t_vars *vars, int err_code);
int		key_press(int keycode, t_vars *vars);
int		close_window(t_vars *vars);
void	display_julia(t_vars *vars);
void	display_mandelbrot(t_vars *vars);

#endif