/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:00:10 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/09 11:13:43 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "ft_vector.h"

typedef struct s_material
{
	t_vec4	color;
	char	*texture;
	int		has_texture;
}	t_material;

#endif /* MATERIAL_H*/
