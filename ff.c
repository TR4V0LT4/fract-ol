
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




void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int zoom(int key, int x, int y,t_data *img)
{
	img->x_offset = x;
	img->y_offset = y;

	if ( key == 4)
		img->scale *= 1.1f;
	else if (key == 5)
		img->scale *= 0.9f;
		return 0;

}

int	ft_strncmp( char *s1,  char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] -s2[i]);
		i++;
	}
	return (0);
}
int fractals(t_cor p)
{
	double temp;
	

	p.iteration = 0;
	p.max = 200;

	while (fabs(p.x * p.x + p.y * p.y) < 4 && p.iteration < p.max) 
			{
				temp = (p.x * p.x - p.y * p.y ) + p.c_r;
				p.y = (2* p.x * p.y ) + p.c_i ;
				p.x = temp;
				p.iteration++;	
			}	
			return (p.iteration);
}
void initialise_julia(t_cor *p,t_data img)
{
	p->x = p->r;
	p->y = p->i;
	if(!ft_strncmp("J",img.t,1))
	{	
		p->c_r = -0.4;
		p->c_i = 0.6;				
	}
	if(!ft_strncmp("J1",img.t,2))
	{
		p->c_r = 0.28;
		p->c_i = 0.008;
	}
	if(!ft_strncmp("J2",img.t,2))
	{
		p->c_r = -0.79;
		p->c_i = 0.15;
	}
	if(!ft_strncmp("J3",img.t,2))
	{
		p->c_r = -0.162;
		p->c_i = 1.04;
	}
}
void plan_complex(t_cor *p,t_data *img)
{
	p->r = ((p->col - (img->width /2 ) ) * 4) * img->scale  /  (img->width );
	p->i = ((p->row - (img->height/2) )  * 4 )  * img->scale /    ( img->height);
}

void draw_fractal(t_cor *p,t_data *img)
{
	p->max = 200;
		p->color = ((p->iteration * 0.19) * 0xade8f4  );
			if (p->iteration < p->max)
				my_mlx_pixel_put(img, p->col, p->row, p->color );
			else
				my_mlx_pixel_put(img, p->col, p->row, 0x000000 );
}
int main_loop(t_data *img)
{
	t_cor p;
	
	p.row = 0;
while (p.row < img->height) 
	{
		p.col = 0;
		while (p.col < img->width) 
		{ 
			plan_complex(&p,img);
			if(!ft_strncmp("M",img->t,1))
			{	
				p.c_r = p.r;
				p.c_i = p.i;
				p.x = 0;
				p.y = 0;
			}
			initialise_julia(&p,*img);
			p.iteration = fractals(p);
			draw_fractal(&p,img);
			p.col++;
		}
		p.row++;	
	}
  	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return 0;
}


int	main(int ac , char **av)
{
	t_data	img;

	if(ac == 2)
	{
		if(!ft_strncmp("M",av[1],1) || !ft_strncmp("J",av[1],1) 
		|| !ft_strncmp("J1",av[1],2) ||  !ft_strncmp("J2",av[1],2) || !ft_strncmp("J3",av[1],2))
			img.t = av[1];
		else 
		{
			printf("./a.out [J] or [M]\n [j] = julia set.\n [M] = mandelbrot set.\n");
		return 0;
		}
	
	
	img.height = 800;
	img.width = 800;
	img.scale = 1.0;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx,img.width,img.height, "Hello");
	img.img = mlx_new_image(img.mlx,img.width,img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian);
	mlx_loop_hook(img.mlx, main_loop,  &img);
	mlx_mouse_hook(img.win, zoom, &img);	
	mlx_loop(img.mlx);
	}
	return 0;
}
