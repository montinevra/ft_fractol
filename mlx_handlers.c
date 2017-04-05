/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 21:40:34 by pvan-erp          #+#    #+#             */
/*   Updated: 2017/04/04 23:14:13 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(int button, int x, int y, t_mlx *mlx)
{
	long double	oldscale;

	oldscale = mlx->scale;
	if (button == 5)
		mlx->scale *= mlx->scalefr;
	else if (button == 4)
		mlx->scale /= mlx->scalefr;
	mlx->offset.a += x * (mlx->scale - oldscale);
	mlx->offset.b += y * (mlx->scale - oldscale);
}

int			expose_hook(t_mlx *mlx)
{
	draw(mlx);
	return (0);
}

int			motion_hook(int x, int y, t_mlx *mlx)
{
	((t_frac *)mlx->data)->c.a = x * mlx->scale - mlx->offset.a;
	((t_frac *)mlx->data)->c.b = -(y * mlx->scale - mlx->offset.b);
	draw(mlx);
	return (0);
}

/*
**	1: left
**	2: right
**	3: middle/thumbs
**	4: scroll up
**	5: scroll down
*/

int			mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	if (y >= 0)
	{
		if (button == 1)
			((t_frac *)mlx->data)->i_max++;
		else if (button == 2)
			((t_frac *)mlx->data)->i_max--;
		else if (button == 4 || button == 5)
			zoom(button, x, y, mlx);
		else if (button == 3)
			init_scale(mlx);
		if (button >= 1 && button <= 5)
		{
			if (((t_frac *)mlx->data)->i_max == 0)
				((t_frac *)mlx->data)->i_max = 1;
			draw(mlx);
		}
	}
	return (0);
}

int			key_hook(int key_code, t_mlx *mlx)
{
	if (key_code == 53)
	{
		free(mlx->img.id);
		free(mlx->data);
		free(mlx->win);
		free(mlx->id);
		exit(0);
	}
	else
	{
		if (key_code == 123)
			mlx->offset.a -= 10 * mlx->scale;
		else if (key_code == 124)
			mlx->offset.a += 10 * mlx->scale;
		else if (key_code == 125)
			mlx->offset.b += 10 * mlx->scale;
		else if (key_code == 126)
			mlx->offset.b -= 10 * mlx->scale;
		draw(mlx);
	}
	return (0);
}
