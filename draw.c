/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 21:34:04 by pvan-erp          #+#    #+#             */
/*   Updated: 2017/04/03 21:34:17 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_clr(int h)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	if (h <= 0xFF)
		b = h;
	else if (h <= 0xFF * 2)
	{
		r = h - 0xFF;
		g = h - 0xFF;
		b = 0xFF;
	}
	else if (h <= 0xFF * 3)
	{
		r = 0xFF;
		g = 0xFF * 3 - h;
		b = 0xFF * 3 - h;
	}
	else
		return (0);
	return (((r << 16) + (g << 8) + b));
}

static void	draw_man3(t_mlx *mlx)
{
	t_coords	px;
	t_cmplx		c;
	t_cmplx		z;
	int			color;
	int			iter;

	px.y = ~0;
	while (++px.y < mlx->wsize.y)
	{
		c.b = -(px.y * mlx->scale - mlx->offset.b);
		z.b = 0;
		px.x = ~0;
		while (++px.x < mlx->wsize.x)
		{
			c.a = px.x * mlx->scale - mlx->offset.a;
			z.a = 0;
			iter = julia3(z, c, ((t_frac *)mlx->data)->i_max);
			color = get_clr((iter + 1) * 0x2FD / ((t_frac *)mlx->data)->i_max);
			*(int *)(mlx->img.start + px.y * mlx->img.lsize + px.x * 4) = color;
		}
	}
	mlx_put_image_to_window(mlx->id, mlx->win, mlx->img.id, 0, 0);
}

static void	draw_man(t_mlx *mlx)
{
	t_coords	px;
	t_cmplx		c;
	t_cmplx		z;
	int			color;
	int			iter;

	px.y = ~0;
	while (++px.y < mlx->wsize.y)
	{
		c.b = -(px.y * mlx->scale - mlx->offset.b);
		z.b = 0;
		px.x = ~0;
		while (++px.x < mlx->wsize.x)
		{
			c.a = px.x * mlx->scale - mlx->offset.a;
			z.a = 0;
			iter = julia(z, c, ((t_frac *)mlx->data)->i_max);
			color = get_clr((iter + 1) * 0x2FD / ((t_frac *)mlx->data)->i_max);
			*(int *)(mlx->img.start + px.y * mlx->img.lsize + px.x * 4) = color;
		}
	}
	mlx_put_image_to_window(mlx->id, mlx->win, mlx->img.id, 0, 0);
}

static void	draw_jul(t_mlx *mlx)
{
	t_coords	px;
	t_cmplx		c;
	t_cmplx		z;
	int			color;
	int			iter;

	px.y = ~0;
	while (++px.y < mlx->wsize.y)
	{
		c.b = ((t_frac *)mlx->data)->c.b;
		z.b = -(px.y * mlx->scale - mlx->offset.b);
		px.x = ~0;
		while (++px.x < mlx->wsize.x)
		{
			c.a = ((t_frac *)mlx->data)->c.a;
			z.a = px.x * mlx->scale - mlx->offset.a;
			iter = julia(z, c, ((t_frac *)mlx->data)->i_max);
			color = get_clr((iter + 1) * 0x2FD / ((t_frac *)mlx->data)->i_max);
			*(int *)(mlx->img.start + px.y * mlx->img.lsize + px.x * 4) = color;
		}
	}
	mlx_put_image_to_window(mlx->id, mlx->win, mlx->img.id, 0, 0);
}

void		draw(t_mlx *mlx)
{
	if (ft_strequ(((t_frac *)mlx->data)->name, "mandelbrot"))
		draw_man(mlx);
	else if (ft_strequ(((t_frac *)mlx->data)->name, "multibrot"))
		draw_man3(mlx);
	else
		draw_jul(mlx);
}
