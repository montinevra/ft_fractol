/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_handlers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 21:40:38 by pvan-erp          #+#    #+#             */
/*   Updated: 2017/04/03 21:40:39 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_HANDLERS_H
# define SDL_HANDLERS_H

int	expose_hook(t_sdl *sdl);
int	motion_hook(int x, int y, t_sdl *sdl);
int	mouse_hook(int button, int x, int y, t_sdl *sdl);
int	key_hook(int key_code, t_sdl *sdl);

#endif
