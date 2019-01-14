/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 21:40:24 by pvan-erp          #+#    #+#             */
/*   Updated: 2017/04/04 23:14:03 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_scale(t_sdl *mlx)
{
	if (mlx->wsize.x < mlx->wsize.y)
		mlx->scale = 4.0 / mlx->wsize.x;
	else
		mlx->scale = 4.0 / mlx->wsize.y;
	mlx->offset.a = mlx->wsize.x * mlx->scale / 2;
	mlx->offset.b = mlx->wsize.y * mlx->scale / 2;
}

void	fractol(char *name)
{
	t_sdl	sdl;

	sdl.wsize.x = 500;
	sdl.wsize.y = 500;
	sdl.scalefr = 1.1;
	init_scale(&sdl);
	sdl.data = (t_frac *)malloc(sizeof(t_frac));
	((t_frac *)sdl.data)->i_max = 0xFF / 8;
	((t_frac *)sdl.data)->name = name;
	((t_frac *)sdl.data)->c.a = 0;
	((t_frac *)sdl.data)->c.b = 0;
	sdl_driver(sdl);
}
