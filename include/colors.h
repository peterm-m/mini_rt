/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:48:06 by pedromar          #+#    #+#             */
/*   Updated: 2024/06/18 12:16:49 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "ft_vector.h"

typedef t_vec3	t_xyz;
typedef t_vec3	t_rgb;
typedef t_vec4	t_argb;

/*
	log colors
*/

# define END    "\x1b[0m"
# define RED         "\x1b[31m"
# define GREEN       "\x1b[32m"
# define BROWN       "\x1b[33m"
# define BLUE        "\x1b[34m"
# define MAGENTA     "\x1b[35m"
# define CYAN        "\x1b[36m"
# define GRAY        "\x1b[37m"

# define RGB_RANGE_MAX 255
# define RGB_RANGE_MIN 0

int		set_rgba(t_vec4	c);
t_vec4	get_rgba(float color);

# define BINS_SPECTRUM 82

typedef struct s_spectrum
{
	float	s[BINS_SPECTRUM];
}	t_spectrum;

void	spectrum_xyz(t_spectrum *s, t_xyz *c);

#endif // COLORS_H
