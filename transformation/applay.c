/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applay.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:12:48 by pedromar          #+#    #+#             */
/*   Updated: 2024/06/07 10:50:03 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "transformation.h"

void	applay_transformation(t_matrix4 *m, t_vec3 *v, t_vec3 *d)//TODO: ULTIMO PARAM ERA VEC3
{
	t_vec4	aux;

	aux = ft_mulm4v(*m, ft_vec4(v->x, v->y, v->z, 1.0f));
	d->x = aux.x / aux.w;
	d->y = aux.y / aux.w;
	d->z = aux.z / aux.w;
}
