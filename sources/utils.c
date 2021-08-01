/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:49:47 by frodney           #+#    #+#             */
/*   Updated: 2021/08/01 22:49:49 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	terminate(char const *s)
{
	ft_putendl_fd(s, 1);
	exit(1);
}

float	maxfloat(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	modfloat(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}
