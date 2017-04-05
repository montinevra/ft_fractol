/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_driver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 21:40:48 by pvan-erp          #+#    #+#             */
/*   Updated: 2017/04/03 21:40:49 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_handlers.h"

static int	is_big_endian(void)
{
	const unsigned int	end = 1;

	return (*(((char *)&end) + 3));
}

void		mlx_driver(t_mlx mlx)
{
	char	*wname;

	wname = ft_strjoin("fractol - ", ((t_frac *)mlx.data)->name);
	mlx.id = mlx_init();
	mlx.win = mlx_new_window(mlx.id, mlx.wsize.x, mlx.wsize.y, wname);
	ft_strdel(&wname);
	mlx.img.id = mlx_new_image(mlx.id, mlx.wsize.x, mlx.wsize.y);
	mlx.img.bppx = 32;
	mlx.img.lsize = mlx.wsize.y * mlx.img.bppx / 4;
	mlx.img.endian = is_big_endian();
	mlx.img.start = mlx_get_data_addr(mlx.img.id, &mlx.img.bppx, &mlx.img.lsize,
		&mlx.img.endian);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	if (ft_strequ(((t_frac *)mlx.data)->name, "julia"))
		mlx_hook(mlx.win, 6, 0, motion_hook, &mlx);
	mlx_loop(mlx.id);
}
