/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_disk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 23:54:58 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 19:36:42 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_disk(t_rt_data *data, void	**args)
{
	t_object	*obj;
	t_point		origin;
	double		size;
	t_list		*temp;

	if (!disk(&obj))
		return (false);
	origin = *(t_point*)args[0];
	size = *(double*)args[2] / 2;
	obj->color = *(t_pixel*)args[3];
	add_transformation(obj, translate(origin.x, origin.y, origin.z));
	add_transformation(obj, scaling(size, size, size));
	add_transformation(obj, from_to_rotation(vector(0, 1, 0), *(t_vector*)args[1]));
	temp = ft_lstnew(obj);
	if (!temp)
	{
		free(obj);
		return (false);
	}
	ft_lstadd_front(&data->objects, temp);
	return (true);
}
