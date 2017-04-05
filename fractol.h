/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 21:40:14 by pvan-erp          #+#    #+#             */
/*   Updated: 2017/04/04 23:13:58 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "libft/libft.h"
# include "mlx_driver.h"

typedef struct	s_cmplx
{
	long double	a;
	long double	b;
}				t_cmplx;

typedef struct	s_frac
{
	char	*name;
	int		i_max;
	t_cmplx	c;
}				t_frac;

void			fractol(char *name);
void			mlx_driver(t_mlx mlx);
void			init_scale(t_mlx *mlx);
int				julia(t_cmplx z0, t_cmplx c, int i_max);
int				julia3(t_cmplx z0, t_cmplx c, int i_max);

#endif
