/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:19:20 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/09 11:14:40 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	object_new(t_shape_type type, t_shape shape)
{
	t_object	obj;

	//obj = malloc(sizeof(t_object)); //TODO cambio emulando new_shape
	obj.type = type;
	obj.shape = shape;
	obj.material.has_texture = FALSE;
	obj.pos_obj = ft_vec3(0.0f, 0.0f, 0.0f);
	obj.rot_obj = ft_vec3(0.0f, 0.0f, 0.0f);
	obj.scale_obj = ft_vec3(1.0f, 1.0f, 1.0f);
	obj.local_world = ft_ident4();
	return (obj);
}

void	object_destroy(t_object *obj)
{
	delete_shape(obj->type, obj->shape);
}

void	update_object(t_object *obj)
{
	obj->local_world = get_invtransform(obj->pos_obj, \
		obj->rot_obj, obj->scale_obj);
	obj->world_local = get_transform(obj->pos_obj, \
		obj->rot_obj, obj->scale_obj);
}
