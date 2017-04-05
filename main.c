/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:28:34 by pvan-erp          #+#    #+#             */
/*   Updated: 2017/03/18 15:28:34 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char const **argv)
{
	if (argc != 2 || (!ft_strequ(argv[1], "mandelbrot") &&
			!ft_strequ(argv[1], "multibrot") && !ft_strequ(argv[1], "julia")))
	{
		write(2, "usage:\t", 7);
		write(2, argv[0], ft_strlen(argv[0]));
		write(2, " fractal\navailable fractals:\tmandelbrot\tjulia\tmultibrot\n"
				, 56);
	}
	else
	{
		fractol((char *)argv[1]);
	}
	return (0);
}
