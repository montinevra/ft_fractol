/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 21:40:34 by pvan-erp          #+#    #+#             */
/*   Updated: 2017/04/04 23:14:13 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(int button, int x, int y, t_sdl *sdl)
{
	long double	oldscale;

	oldscale = sdl->scale;
	if (button == 5)
		sdl->scale *= sdl->scalefr;
	else if (button == 4)
		sdl->scale /= sdl->scalefr;
	sdl->offset.a += x * (sdl->scale - oldscale);
	sdl->offset.b += y * (sdl->scale - oldscale);
}

int			expose_hook(t_sdl *sdl)
{
	draw(sdl);
	return (0);
}

int			motion_hook(int x, int y, t_sdl *sdl)
{
	((t_frac *)sdl->data)->c.a = x * sdl->scale - sdl->offset.a;
	((t_frac *)sdl->data)->c.b = -(y * sdl->scale - sdl->offset.b);
	draw(sdl);
	return (0);
}

/*
**	1: left
**	2: right
**	3: middle/thumbs
**	4: scroll up
**	5: scroll down
*/

int			mouse_hook(int button, int x, int y, t_sdl *sdl)
{
	if (y >= 0)
	{
		if (button == 1)
			((t_frac *)sdl->data)->i_max++;
		else if (button == 2)
			((t_frac *)sdl->data)->i_max--;
		else if (button == 4 || button == 5)
			zoom(button, x, y, sdl);
		else if (button == 3)
			init_scale(sdl);
		if (button >= 1 && button <= 5)
		{
			if (((t_frac *)sdl->data)->i_max == 0)
				((t_frac *)sdl->data)->i_max = 1;
			draw(sdl);
		}
	}
	return (0);
}

int			key_hook(int key_code, t_sdl *sdl)
{
	if (key_code == SDLK_ESCAPE)
	{
		free(sdl->img.id);
		free(sdl->data);
		free(sdl->win);
		free(sdl->id);
		exit(0);
	}
	else
	{
		if (key_code == SDLK_LEFT)
			sdl->offset.a -= 10 * sdl->scale;
		else if (key_code == SDLK_RIGHT)
			sdl->offset.a += 10 * sdl->scale;
		else if (key_code == SDLK_DOWN)
			sdl->offset.b += 10 * sdl->scale;
		else if (key_code == SDLK_UP)
			sdl->offset.b -= 10 * sdl->scale;
		draw(sdl);
	}
	return (0);
}
