/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_driver.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 21:40:51 by pvan-erp          #+#    #+#             */
/*   Updated: 2017/04/03 21:40:53 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DRIVER_H
# define MLX_DRIVER_H
# include "minilibx_macos/mlx.h"

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

typedef struct	s_mlx_img
{
	void	*id;
	char	*start;
	int		bppx;
	int		lsize;
	int		endian;
}				t_mlx_img;

typedef	struct	s_mlx
{
	void		*id;
	void		*win;
	t_mlx_img	img;
	t_coords	wsize;
	t_offset	offset;
	long double	scale;
	float		scalefr;
	void		*data;
}				t_mlx;

void			draw(t_mlx *mlx);

#endif
