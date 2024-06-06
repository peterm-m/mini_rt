/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:47:54 by pedromar          #+#    #+#             */
/*   Updated: 2024/06/05 12:57:23 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_scene_debug(t_scene	*scene)
{
	scene->cam.angle_of_view = 70.0f;
	scene->cam.pos_cam = ft_vec3(-50.0f, 0.0f, 20.0f);
	scene->cam.rot_cam = ft_vec3(0.0f, 0.0f, 0.0f);
	scene->cam.scale_cam = ft_vec3(1.0f, 1.0f, 1.0f);
	scene->cam.img_size[IMG_SIZE_X] = DEFAULT_IMGSIZE_X;
	scene->cam.img_size[IMG_SIZE_Y] = DEFAULT_IMGSIZE_Y;
	scene->cam.clipping[CLIP_NEAR] = DEFAULT_CLIPPING_NEAR;
	scene->cam.clipping[CLIP_FAR] = DEFAULT_CLIPPING_FAR;
	scene->cam.aperture[APERTURE_WIDTH] = DEFAULT_APERTURE_WIDTH;
	scene->cam.aperture[APERTURE_HEIGHT] = DEFAULT_APERTURE_HEIGHT;
	scene->cam.focal = 0.0f;

	//Lights[0] es la luz ambiente.
	scene->lights[0].type = lgh_ambient;
	scene->lights[0].brightness = 0.2f;
	scene->lights[0].color = ft_vec4(255.0f, 255.0f, 255.0f, 1.0f);
	// TODO: Creo que el color deberia ser vec3.

	//Light[1] es la luz, en caso de bonus: light[1] - light[n]
	scene->lights[1].type = lgh_point;
	scene->lights[1].brightness = 0.6f;
	scene->lights[1].color = ft_vec4(15.0f, 0.0f, 255.0f, 1.0f);
	scene->lights[1].pos = ft_vec3(-30.0f, 60.0f, 0.0f);

	// Esfera 1
	t_sp *sphere1 = (t_sp)malloc(sizeof(t_sp));
	sphere1->center = ft_vec3(0.0f, 0.0f, 20.0f);
	sphere1->radius = 6.3f;
	scene->objs[0].type = sh_sphere;
	scene->objs[0].shape.sp = sphere1;
	scene->objs[0].material.color = ft_vec4(55.0f, 55.0f, 55.0f, 1.0f);
	scene->objs[0].pos_obj = ft_vec3(0.0f, 0.0f, 20.0f); // No se si es necesario.

	// Plano 1
	t_pl *plane1 = (t_pl)malloc(sizeof(t_pl));
	plane1->point = ft_vec3(0.0f, 0.0f, -10.0f);
	plane1->normal = ft_vec3(0.0f, 1.0f, 0.0f);
	plane1->material.color = ft_vec4(155.0f, 155.0f, 5.0f, 1.0f);
	scene->objs[1].type = sh_plane;
	scene->objs[1].shape.pl = plane1;
	scene->objs[1].material.color = ft_vec4(155.0f, 155.0f, 5.0f, 1.0f);// No se si es necesario.
	scene->objs[1].pos_obj = ft_vec3(0.0f, 0.0f, -10.0f); // No se si es necesario.
	
	// Cilindro 1
	t_cy *cylinder1 = (t_pl)malloc(sizeof(t_pl));
	cylinder1->center = ft_vec3(50.0f, 0.0f, 20.0f);
	cylinder1->normal = ft_vec3(0.0f, 0.0f, 1.0f);
	cylinder1->material.color = ft_vec4(15.0f, 0.0f, 165.0f, 1.0f);
	cylinder1->height = 21.42f;
	cylinder1->radius = 7.1f;
	scene->objs[1].type = sh_cylinder;
	scene->objs[1].shape.cy = cylinder1;
	scene->objs[1].material.color = ft_vec4(15.0f, 0.0f, 165.0f, 1.0f);// No se si es necesario.
	scene->objs[1].pos_obj = ft_vec3(0.0f, 0.0f, -10.0f); // No se si es necesario.
}

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

/* 	if (ft_parser(&scene, argc, argv))
		perror ("Error\n"); */
	init_scene_debug(&scene);
	printf("MINIRT %s %s\n", __DATE__, __TIME__);
	t_win	win =  ft_program(1024, 1024, "minirt");
	t_render *r = set_render(&win);
	set_control(r);
	mlx_loop(win.mlx);
	return (EXIT_SUCCESS);
}
