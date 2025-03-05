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


void	plan_complex(t_cor *p, t_data *img)
{
    double scale_x = (4 * img->scale) / img->width;
    double scale_y = (4 * img->scale) / img->height;

    p->r = (p->col - img->x_offset) * scale_x;
    p->i = (p->row - img->y_offset) * scale_y;
}

int trippy_color(int iteration)
{
    double t = (double)iteration / 200.0; // Normalize between 0 and 1
    int r = (int)(9 * (1 - t) * t * t * t * 255);
    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    
    return (r << 16) | (g << 8) | b;
}

void	draw_fractal(t_cor *p, t_data *img)
{
    p->color = (p->iteration < MAX_ITER) ? trippy_color(p->iteration) : 0x000000;
    my_mlx_pixel_put(img, p->col, p->row, p->color);
}



int fill_image(t_data *img)
{
    t_cor p;

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