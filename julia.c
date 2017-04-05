/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 21:41:00 by pvan-erp          #+#    #+#             */
/*   Updated: 2017/04/03 22:01:04 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	escape time algorithm for z1 = z0^2 + c
*/

int	julia(t_cmplx z0, t_cmplx c, int i_max)
{
	static const float	bail = 2.0;
	int					iter;
	long double			z1a;

	iter = ~0;
	while (++iter < i_max && hypot(z0.a, z0.b) < bail)
	{
		z1a = z0.a * z0.a - z0.b * z0.b + c.a;
		z0.b = 2 * z0.a * z0.b + c.b;
		z0.a = z1a;
	}
	return (iter);
}

/*
**	z1 = z0^3 + c
*/

int	julia3(t_cmplx z0, t_cmplx c, int i_max)
{
	static const float	bail = 2.0;
	int					iter;
	long double			z1a;

	iter = ~0;
	while (++iter < i_max && hypot(z0.a, z0.b) < bail)
	{
		z1a = z0.a * z0.a * z0.a - 3 * z0.a * z0.b * z0.b + c.a;
		z0.b = 3 * z0.a * z0.a * z0.b - z0.b * z0.b * z0.b + c.b;
		z0.a = z1a;
	}
	return (iter);
}
