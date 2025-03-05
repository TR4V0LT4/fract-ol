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

int zoom(int button, int x, int y, t_data *img)
{
    double zoom_factor;

    if (button == 4) // Scroll up (zoom in)
        zoom_factor = 1.1;
    else if (button == 5) // Scroll down (zoom out)
        zoom_factor = 0.9;
    else
        return (0);

    // Update the mouse position
     double mouse_r, mouse_i;  // Complex coordinates of the mouse
    mouse_r = ((x - img->x_offset) * img->scale);
    mouse_i = ((y - img->y_offset) * img->scale);

    // Update the zoom scale
    img->scale *= zoom_factor;
    img->x_offset = x - (mouse_r / img->scale);
    img->y_offset = y - (mouse_i / img->scale);

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
