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

void	init_scale(t_mlx *mlx)
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
	t_mlx	mlx;

	mlx.wsize.x = 500;
	mlx.wsize.y = 500;
	mlx.scalefr = 1.1;
	init_scale(&mlx);
	mlx.data = (t_frac *)malloc(sizeof(t_frac));
	((t_frac *)mlx.data)->i_max = 0xFF / 8;
	((t_frac *)mlx.data)->name = name;
	((t_frac *)mlx.data)->c.a = 0;
	((t_frac *)mlx.data)->c.b = 0;
	mlx_driver(mlx);
}
