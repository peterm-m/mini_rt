/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:47:54 by pedromar          #+#    #+#             */
/*   Updated: 2024/07/09 09:48:57 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_image(t_render *r, t_win *win, int w, int h)
{
	r->img = (t_image *) mallox(sizeof(t_image));
	r->img->win = *win;
	r->img->ptr = ft_new_image(w, h);
	r->img->addr = mlx_get_data_addr(r->img->ptr, &(r->img->bpp),
			&(r->img->size_line), &(r->img->endian));
	r->img->w = w;
	r->img->h = h;
}

t_win	ft_program(int h, int w, char *str)
{
	void	*win;

	win = ft_new_windows(w, h, str);
	return ((t_win){ft_getmlx(), win, w, h});
}

t_render	*set_render(t_win *win)
{
	t_render	*new;

	new = (t_render *)mallox(sizeof(t_render));
	new->c = camera_new();
	ft_image(new, win, 1024, 1024);
	return (new);
}

int main (int argc, char* argv[])
{
	t_scene	scene;

	scene.lgts_count = 0;
	scene.objs_count = 0;
	if (ft_parser(&scene, argc, argv))
		return (EXIT_FAILURE);
	test_parser(scene);
	init_scene_debug(&scene);
	printf("MINIRT %s %s\n", __DATE__, __TIME__);
	t_win	win =  ft_program(1024, 1024, "minirt");
	t_render *r = set_render(&win);
	set_control(r);
	mlx_loop(win.mlx);
	return (EXIT_SUCCESS);
}


/*

t_color	color_obj(t_obj *obj, t_hit *hit)
{
	float	uv[2];
	t_color	color;

	color = obj->color;
	if (obj->id == id_sphere && obj->has_texture)
	{
		uv_sphere_map(obj, hit->phit, uv);
		color = get_pixelcolor(&obj->texture, uv[0], uv[1]);
	}
	else if (obj->pattern_num > 0)
		color = pattern_color(obj, hit->phit);
	return (color);
}


*/
