/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 21:40:24 by pvan-erp          #+#    #+#             */
/*   Updated: 2017/04/03 21:40:26 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol(char *name)
{
	t_mlx	mlx;

	mlx.wsize.x = 500;
	mlx.wsize.y = 500;
	if (mlx.wsize.x < mlx.wsize.y)
		mlx.scale = 4.0 / mlx.wsize.x;
	else
		mlx.scale = 4.0 / mlx.wsize.y;
	mlx.scalefr = 1.1;
	mlx.offset.a = mlx.wsize.x * mlx.scale / 2;
	mlx.offset.b = mlx.wsize.y * mlx.scale / 2;
	mlx.data = (t_frac *)malloc(sizeof(t_frac));
	((t_frac *)mlx.data)->i_max = 0xFF / 8;
	((t_frac *)mlx.data)->name = name;
	((t_frac *)mlx.data)->c.a = 0;
	((t_frac *)mlx.data)->c.b = 0;
	mlx_driver(mlx);
}
