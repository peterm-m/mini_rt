/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:45:23 by pedromar          #+#    #+#             */
/*   Updated: 2024/06/07 11:05:05 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>//

# include "ft_vector.h"

# include "colors.h"
# include "geometric.h"
# include "shape.h"
# include "object.h"
# include "camera.h"
# include "render.h"
# include "light.h"
# include "ray.h"
# include "controls.h"
# include "transformation.h"
# include "wrappers.h"
# include "parser.h"
# include "parser2.h"
# include "get_next_line.h"
# include "libft.h"

# include "plotter.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif
# ifndef M_PROJECT_LIMITS
#  define M_PROJECT_LIMITS 1
#  define OBJS_LIMIT 15
#  define LIGHTS_LIMIT 5
# endif


typedef struct s_scene
{
	t_camera	*cam;
	t_object	*objs;
	t_light		*lights;
}				t_scene;

//
void	*mallox(size_t size);
int		render_loop(t_render *r);
int		ft_plot_points(t_render *r);
//
int		raster_loop(t_render *r);
int		raytracer_loop(t_render *r);
//
int		ft_end_program(t_render *r);

#endif // MINIRT_H
