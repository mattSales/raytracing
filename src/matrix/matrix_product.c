/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:14:50 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 18:39:53 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static double	product_value(t_matrix a, t_tuple b, int x, int row)
{
	double	result;
	int		index;

	result = 0;
	index = a.size;
	while (index--)
		result += a.values[row][index] * b.values[index];
	return (result);
}

t_tuple			matrix_product(t_matrix a, t_tuple b)
{
	t_tuple	result;
	int		row;
	int		column;

	result = tuple(0, 0, 0, 0);
	row = a.size;
	while (row--)
	{
		result.values[row] = product_value(a, b, column, row);
	}
	return (result);
}
