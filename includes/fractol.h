/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:51:44 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/02/20 16:51:36 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>
# include <stdio.h>

# define TITLE "fractol"
# define WIDTH 960
# define HEIGHT 960
# define PGCD 120

typedef union u_color
{
	uint32_t	color;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
	};
}	t_color;

typedef struct s_complex
{
	double	z_r;
	double	z_i;
}	t_complex;

typedef struct s_params
{
	double			move_x;
	double			move_y;
	double			zoom;
	unsigned int	max_iteration;
	char			*name;
	t_complex		c;
	t_color			color;
	t_color			move_color;
}	t_params;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	struct s_data	data;
	struct s_params	params;
}	t_vars;

void	init_all(t_vars *vars);
void	init_vars(t_vars *vars);
int		init_fractal(t_vars *vars);
void	free_exit(t_vars *vars, int err_code);
int		key_press(int keycode, t_vars *vars);
int		close_window(t_vars *vars);
int		calculate_limit(t_vars *vars, int x, int y);
void	calculate_color(t_vars *vars, int x, int y);
void	put_pixel(t_vars *vars, int x, int y);
double	pow_complex(t_complex z);
double	absolute_value(double x);
void	modify_x(t_vars *vars, int keycode);
void	modify_y(t_vars *vars, int keycode);
void	modify_zoom(t_vars *vars, int keycode);
void	modify_colors(t_vars *vars, int keycode);
void	modify_iteration(t_vars *vars, int keycode);
int		mouse_wheel(int keycode, int x, int y, t_vars *vars);
#endif