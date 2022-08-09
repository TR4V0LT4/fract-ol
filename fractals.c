/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:02:59 by wlahyani          #+#    #+#             */
/*   Updated: 2022/08/09 16:08:19 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	mandelbrot_set(t_cor p)
{
	double	temp;

	p.iteration = 0;
	p.max = 200;
	while (fabs(p.x * p.x + p.y * p.y) < 4 && p.iteration < p.max)
	{
		temp = (p.x * p.x - p.y * p.y) + p.c_r;
		p.y = (2 * p.x * p.y) + p.c_i;
		p.x = temp;
		p.iteration++;
	}	
	return (p.iteration);
}

void	initialise_julia(t_cor *p, t_data img)
{
	p->x = p->r;
	p->y = p->i;
	if (!ft_strncmp("J", img.t, 2))
	{	
		p->c_r = -0.4;
		p->c_i = 0.6;
	}
	if (!ft_strncmp("J1", img.t, 2))
	{
		p->c_r = 0.28;
		p->c_i = 0.008;
	}
	if (!ft_strncmp("J2", img.t, 2))
	{
		p->c_r = -0.79;
		p->c_i = 0.15;
	}
	if (!ft_strncmp("J3", img.t, 2))
	{
		p->c_r = -0.162;
		p->c_i = 1.04;
	}
}
