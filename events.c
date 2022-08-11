/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:59:08 by wlahyani          #+#    #+#             */
/*   Updated: 2022/08/11 11:03:11 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	zoom(int key, int x, int y, t_data *img)
{
	img->x_offset = x;
	img->y_offset = y;
	if (key == 4)
		img->scale *= 1.1f;
	else if (key == 5)
		img->scale *= 0.9f;
	return (0);
}

int	close_win(int key, void *p)
{
	(void)p;
	if (key == 53)
		exit(1);
	return (0);
}

int	closex(int keycode, void *p)
{
	(void)keycode;
	(void)p;
	exit(1);
	return (0);
}
