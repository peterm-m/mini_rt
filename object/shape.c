/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:20:57 by pedromar          #+#    #+#             */
/*   Updated: 2024/06/18 12:56:55 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	new_shape(t_shape_type type)
{
	t_shape	sh;

	if (type == sh_sphere)
		{sh.sp = mallox(sizeof(t_sp));printf(BLUE"%p\n"END, sh.sp);}
	else if (type == sh_box)
		{sh.bx = mallox(sizeof(t_bx));printf(BLUE"%p\n"END, sh.bx);}
	else if (type == sh_plane)
		{sh.pl = mallox(sizeof(t_pl));printf(BLUE"%p\n"END, sh.pl);}
	else if (type == sh_cylinder)
		{sh.cy = mallox(sizeof(t_cy));printf(BLUE"%p\n"END, sh.cy);}
	return (sh);
}

void	delete_shape(t_shape_type type, t_shape sh)
{
	if (type == sh_sphere)
		{free(sh.sp);printf(CYAN"%p\n"END, sh.sp);}
	else if (type == sh_box)
		{free(sh.bx);printf(CYAN"%p\n"END, sh.bx);}
	else if (type == sh_plane)
		{free(sh.pl);printf(CYAN"%p\n"END, sh.pl);}
	else if (type == sh_cylinder)
		{free(sh.cy);printf(CYAN"%p\n"END, sh.cy);}
}