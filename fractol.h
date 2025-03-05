/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:36:58 by wlahyani          #+#    #+#             */
/*   Updated: 2022/08/11 11:35:39 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>

#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define MAX_ITER 200
int colors[MAX_ITER];



typedef struct s_data{
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
	char	*t;

	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		x_offset;
	int		y_offset;
	double	scale ;
	int		x_shift;
	int		y_shift;
}	t_data;

typedef struct s_cor{
	double	x;
	double	y;
	double	r;
	double	i;
	double	c_r;
	double	c_i;
	int		color;
	int		iteration;
	int		max;
	double	row;
	double	col;
	int		k;
}	t_cor;

// typedef struct s_julia_constants {
//     char *type; 
//     double c_r;
//     double c_i;
// } t_julia_constants;


// t_julia_constants julia_constants[] = {
//     {"J", -0.4, 0.6},
//     {"J1", 0.28, 0.008},
//     {"J2", -0.79, 0.15},
//     {"J3", -0.162, 1.04},
// };


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	initialise_julia(t_cor *p, t_data img);
void	plan_complex(t_cor *p, t_data *img);
void	draw_fractal(t_cor *p, t_data *img);
void	guide(void);
int		zoom(int key, int x, int y, t_data *img);
int		ft_strncmp(char *s1, char *s2, int n);
int		mandelbrot_set(t_cor p);
int		fill_image(t_data *img);
int		close_win(int key, void *p);
int		closex(int keycode, void *p);
int handle_keypress(int keycode, t_data *img);
int trippy_color(int iteration);


#endif
