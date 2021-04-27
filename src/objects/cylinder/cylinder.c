/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 15:22:24 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

t_object	cylinder(void)
{
	t_cylinder	*c;

	c = malloc(sizeof(t_cylinder));
	if (!c)
		exit(1);
	c->min = -INFINITY;
	c->max = INFINITY;
	c->closed = false;
	return ((t_object){
		.data = c,
		.intersect = cylinder_intersect,
		.normal_at = cylinder_normal_at,
		.matrix = matrix_identity(4),
		.inverse_matrix = matrix_identity(4),
		.material = color_normal()
	});
}
