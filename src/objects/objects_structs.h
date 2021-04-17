/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/16 20:27:02 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_STRUCTS_H
# define OBJECTS_STRUCTS_H

# include "./../tuple/tuple.h"
# include "./../ray/ray.h"
# include "./../matrix/matrix.h"

struct s_object;
struct s_hit_range;
struct s_intersection;

typedef struct s_object t_object;
typedef struct s_hit_range t_range;
typedef struct s_intersection t_intersection;

typedef struct s_object
{
	t_matrix	inverse_matrix;
	bool	(*intersect)(
		t_object object,
		t_ray ray,
		t_range range,
		t_intersection * hit);
}				t_object;

typedef struct s_hit_range
{
	double	min;
	double	max;
}				t_range;

typedef struct s_intersection
{
	bool		front_face;
	t_object	t_object;
	t_point		point;
	t_vector	normal;
	double		t;
}				t_intersection;

#endif
