/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_driver.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 21:40:51 by pvan-erp          #+#    #+#             */
/*   Updated: 2017/04/03 21:40:53 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_DRIVER_H
# define SDL_DRIVER_H
//# include "minilibx_macos/sdl.h"
# define THREADS 4

typedef struct	s_px
{
	int	x;
	int	y;
	int	clr;
}				t_px;

typedef struct	s_coords
{
	int	x;
	int	y;
}				t_coords;

typedef struct	s_offset
{
	long double	a;
	long double	b;
}				t_offset;

typedef struct	s_sdl_img
{
	SDL_Surface	*id;
	char		*start;
	int			bppx;
	int			lsize;
	int			endian;
}				t_sdl_img;

typedef	struct	s_sdl
{
	void		*id;
	SDL_Window	*win;
	t_sdl_img	img;
	t_coords	wsize;
	t_offset	offset;
	long double	scale;
	float		scalefr;
	void		*data;
}				t_sdl;

typedef struct	s_sdl_thread
{
	t_sdl	*sdl;
	int		y;	
}				t_sdl_thread;

void			draw(t_sdl *sdl);
void			sdl_loop(t_sdl *sdl);

#endif
