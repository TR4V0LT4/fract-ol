/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:08:35 by wlahyani          #+#    #+#             */
/*   Updated: 2022/08/09 17:56:38 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	img;
	void *k = NULL ;

	if ((ac == 2) && (!ft_strncmp("M", av[1], 1) || !ft_strncmp("J", av[1], 2)
			|| !ft_strncmp("J1", av[1], 2) || !ft_strncmp("J2", av[1], 2)
			|| !ft_strncmp("J3", av[1], 2)))
	{
	img.t = av[1];
	img.height = 800;
	img.width = 800;
	img.scale = 1.0;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.width, img.height, "Hello");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		mlx_loop_hook(img.mlx, fill_image, &img);
		mlx_mouse_hook(img.win, zoom, &img);
		mlx_key_hook(img.win,close,k);
		mlx_loop(img.mlx);
	}
	else
	{
		write(1, "./fractol [M] or [J]\n\n[M] = mandelbrot set.\n", 45);
		write(1, "[J] = julia set. (use J1 & J2 & J3 for more shapes)", 51);
	}
	return (0);
}
