#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*mlx;
	void	*img;
	void 	*win;
	char	*addr;
	char	*t;

	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	width;
	int 	height;
	int x_offset;
	int y_offset;
	double scale ;
}	t_data;

typedef struct s_cor{
	double x;
	double y;
	double r;
	double i;
	double c_r;
	double c_i;
	int color;
	int iteration;
	int max;
	double row;
	double col;
}	t_cor;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int zoom(int key, int x, int y,t_data *img);
int	ft_strncmp( char *s1,  char *s2, int n);
int mandelbrot_set(t_cor p);
void initialise_julia(t_cor *p,t_data img);
void plan_complex(t_cor *p,t_data *img);
void draw_fractal(t_cor *p,t_data *img);
int fill_image(t_data *img);


#endif