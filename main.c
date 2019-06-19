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

int	main(int argc, char **argv)
{
	const char *controls = "Mouse wheel:\t\tzoom\nMiddle click:\t\treset zoom\nLeft/right click:\tchange depth\nEsc:\t\t\tquit";

	if (argc != 2 || (strcmp(argv[1], "mandelbrot") &&
			strcmp(argv[1], "multibrot") && strcmp(argv[1], "julia")))
	{
		write(2, "usage:\t", 7);
		write(2, argv[0], strlen(argv[0]));
		write(2, " fractal\navailable fractals:\tmandelbrot\tjulia\tmultibrot\n"
				, 56);
	}
	else
	{
		write(2, controls, strlen(controls));
		fractol((char *)argv[1]);
	}
	return (0);
}
