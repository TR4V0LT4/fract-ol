/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:52:41 by wlahyani          #+#    #+#             */
/*   Updated: 2022/08/09 16:02:24 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	zoom(int key, int x, int y, t_data *img)
{
	img->x_offset = x;
	img->y_offset = y;
	printf("x = %d ; y = %d ; key = %d \n ",x,y,key);
	if (key == 4)
		img->scale *= 1.1f;
	else if (key == 5)
		img->scale *= 0.9f;
	
	return (0);
}

int close_win(int key,void *p)
{
	p = 0;
	//p->k = key;
	//printf("key = %d \n " ,key);
		if(key == 53)
			exit(1);
		
	return (0);
}

void	plan_complex(t_cor *p, t_data *img)
{
	p->r = ((p->col - (img->width / 2)) * 4) * img->scale / (img->width);
	p->i = ((p->row - (img->height / 2)) * 4) * img->scale / (img->height);
}

void	draw_fractal(t_cor *p, t_data *img)
{
	p->max = 200;
	p->color = ((p->iteration *0.19) * 0xade8f4);
	if (p->iteration < p->max)
		my_mlx_pixel_put(img, p->col, p->row, p->color);
	else
		my_mlx_pixel_put(img, p->col, p->row, 0x000000);
}

int	fill_image(t_data *img)
{
	t_cor	p;

	p.row = 0;
	while (p.row < img->height)
	{
		p.col = 0;
		while (p.col < img->width)
		{
			plan_complex(&p, img);
			if (!ft_strncmp("M", img->t, 1))
			{	
				p.c_r = p.r;
				p.c_i = p.i;
				p.x = 0;
				p.y = 0;
			}
			initialise_julia(&p, *img);
			p.iteration = mandelbrot_set(p);
			draw_fractal(&p, img);
			p.col++;
		}
		p.row++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}
