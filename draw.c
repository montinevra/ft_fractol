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

static void	draw_man3(t_sdl *sdl)
{
	t_coords	px;
	t_cmplx		c;
	t_cmplx		z;
	int			color;
	int			iter;

	px.y = ~0;
	while (++px.y < sdl->wsize.y)
	{
		c.b = -(px.y * sdl->scale - sdl->offset.b);
		z.b = 0;
		px.x = ~0;
		while (++px.x < sdl->wsize.x)
		{
			c.a = px.x * sdl->scale - sdl->offset.a;
			z.a = 0;
			iter = julia3(z, c, ((t_frac *)sdl->data)->i_max);
			color = get_clr((iter + 1) * 0x2FD / ((t_frac *)sdl->data)->i_max);
			*(int *)(sdl->img.start + px.y * sdl->img.lsize + px.x * 4) = color;
		}
	}
}

static void	*draw_man_thread(void *sdlt)
{
	t_sdl		*sdl;
	t_coords	px;
	t_cmplx		c;
	t_cmplx		z;
	int			color;
	int			iter;

	sdl = ((t_sdl_thread *)sdlt)->sdl;
	px.y = ((t_sdl_thread *)sdlt)->y;
	while (px.y < sdl->wsize.y)
	{
		c.b = -(px.y * sdl->scale - sdl->offset.b);
		z.b = 0;
		px.x = ~0;
		while (++px.x < sdl->wsize.x)
		{
			c.a = px.x * sdl->scale - sdl->offset.a;
			z.a = 0;
			iter = julia(z, c, ((t_frac *)sdl->data)->i_max);
			color = get_clr((iter + 1) * 0x2FD / ((t_frac *)sdl->data)->i_max);
			*(int *)(sdl->img.start + px.y * sdl->img.lsize + px.x * 4) = color;
		}
		px.y += THREADS;
	}
	return (NULL);
}

static void	draw_man(t_sdl *sdl)
{
	t_sdl_thread	sdlt[THREADS];
	pthread_t		thread[THREADS];
	// t_cmplx		c;
	// t_cmplx		z;
	// int			color;
	// int			iter;
	int i;
	// sdlt.sdl = sdl;
	i = ~0;
	while (++i < THREADS)
	{
		sdlt[i].sdl = sdl;
		sdlt[i].y = i;
		pthread_create(&thread[i], NULL, draw_man_thread, &sdlt[i]);
	}
	i = ~0;
	while (++i < THREADS)
	{
		pthread_join(thread[i], NULL);
	}
	// while (++px.y < sdl->wsize.y)
	// {
	// 	c.b = -(px.y * sdl->scale - sdl->offset.b);
	// 	z.b = 0;
	// 	px.x = ~0;
	// 	while (++px.x < sdl->wsize.x)
	// 	{
	// 		c.a = px.x * sdl->scale - sdl->offset.a;
	// 		z.a = 0;
	// 		iter = julia(z, c, ((t_frac *)sdl->data)->i_max);
	// 		color = get_clr((iter + 1) * 0x2FD / ((t_frac *)sdl->data)->i_max);
	// 		*(int *)(sdl->img.start + px.y * sdl->img.lsize + px.x * 4) = color;
	// 	}
	// }
}

static void	draw_jul(t_sdl *sdl)
{
	t_coords	px;
	t_cmplx		c;
	t_cmplx		z;
	int			color;
	int			iter;

	px.y = ~0;
	while (++px.y < sdl->wsize.y)
	{
		c.b = ((t_frac *)sdl->data)->c.b;
		z.b = -(px.y * sdl->scale - sdl->offset.b);
		px.x = ~0;
		while (++px.x < sdl->wsize.x)
		{
			c.a = ((t_frac *)sdl->data)->c.a;
			z.a = px.x * sdl->scale - sdl->offset.a;
			iter = julia(z, c, ((t_frac *)sdl->data)->i_max);
			color = get_clr((iter + 1) * 0x2FD / ((t_frac *)sdl->data)->i_max);
			*(int *)(sdl->img.start + px.y * sdl->img.lsize + px.x * 4) = color;
		}
	}
}

void		draw(t_sdl *sdl)
{
	if (!strcmp(((t_frac *)sdl->data)->name, "mandelbrot"))
		draw_man(sdl);
	else if (!strcmp(((t_frac *)sdl->data)->name, "multibrot"))
		draw_man3(sdl);
	else
		draw_jul(sdl);
	//sdl_put_image_to_window(sdl->id, sdl->win, sdl->img.id, 0, 0);
}
