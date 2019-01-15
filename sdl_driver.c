/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_driver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 21:40:48 by pvan-erp          #+#    #+#             */
/*   Updated: 2017/04/03 21:40:49 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "sdl_handlers.h"

static int	is_big_endian(void)
{
	const unsigned int	end = 1;

	return (*(((char *)&end) + 3));
}


void		sdl_loop(t_sdl *sdl)
{
	SDL_Event	e;

	draw(sdl);
	while (1)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
				case SDL_QUIT:
					return;
				case SDL_KEYDOWN:
					key_hook(e.key.keysym.sym, sdl);
					break;
				case SDL_MOUSEBUTTONDOWN:
					mouse_hook(e.button.button, e.button.x, e.button.y, sdl);
					break;
				case SDL_MOUSEWHEEL:
					wheel_hook(e.wheel.y, sdl);
					break;
				case SDL_MOUSEMOTION:
					if (!strcmp(((t_frac *)sdl->data)->name, "julia"))
					{
						motion_hook(e.motion.x, e.motion.y, sdl);
					}
					break;
			}
		}
		SDL_UpdateWindowSurface(sdl->win);
	}
}

void		sdl_driver(t_sdl *sdl)
{
	char	*wname;

	wname = malloc(strlen(((t_frac *)sdl->data)->name) + 11);
	strcpy(wname, "fractol - ");
	strcat(wname, ((t_frac *)sdl->data)->name);
	//wname = strjoin("fractol - ", ((t_frac *)sdl->data)->name);
	SDL_Init(SDL_INIT_VIDEO);
	//sdl->id = sdl_init();
	sdl->win = SDL_CreateWindow(wname, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sdl->wsize.x, sdl->wsize.y, 0);
	free(wname);
	//strdel(&wname);
	sdl->img.id = SDL_GetWindowSurface(sdl->win);
	sdl->img.bppx = 32;
	sdl->img.lsize = sdl->wsize.y * sdl->img.bppx / 4;
	sdl->img.endian = is_big_endian();
	//sdl->img.start = sdl_get_data_addr(sdl->img.id, &sdl->img.bppx, &sdl->img.lsize, &sdl->img.endian);
	// sdl_mouse_hook(sdl->win, mouse_hook, &sdl);
	// sdl_key_hook(sdl->win, key_hook, &sdl);
	// sdl_expose_hook(sdl->win, expose_hook, &sdl);
	if (!strcmp(((t_frac *)sdl->data)->name, "julia"))
	{
		//sdl_hook(sdl->win, 6, 0, motion_hook, &sdl);
	}
	sdl_loop(sdl);
}
