#include "minirt.h"

int	init_scene_debug(t_scene	*scene)
{
	scene->lights = (t_light *)malloc(sizeof(t_light) * 2);
    scene->objs = (t_object *)malloc(sizeof(t_object) * 5);
    scene->cam = camera_new();
	
	scene->cam->angle_of_view = 70.0f;
	scene->cam->pos_cam = ft_vec3(-50.0f, 0.0f, 20.0f);
	scene->cam->rot_cam = ft_vec3(0.0f, 0.0f, 0.0f);
	scene->cam->scale_cam = ft_vec3(1.0f, 1.0f, 1.0f);
	scene->cam->img_size[IMG_SIZE_X] = DEFAULT_IMGSIZE_X;
	scene->cam->img_size[IMG_SIZE_Y] = DEFAULT_IMGSIZE_Y;
	scene->cam->clipping[CLIP_NEAR] = DEFAULT_CLIPPING_NEAR;
	scene->cam->clipping[CLIP_FAR] = DEFAULT_CLIPPING_FAR;
	scene->cam->aperture[APERTURE_WIDTH] = DEFAULT_APERTURE_WIDTH;
	scene->cam->aperture[APERTURE_HEIGHT] = DEFAULT_APERTURE_HEIGHT;
	scene->cam->focal = 0.0f;

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
/* 	t_shape sphere1 = new_shape(sh_sphere);
	sphere1.sp->center = ft_vec3(0.0f, 0.0f, 20.0f);
	sphere1.sp->radius = 6.3f;
	t_object *obj0 = object_new(sh_sphere, sphere1);
	obj0->material.color = ft_vec4(55.0f, 55.0f, 55.0f, 1.0f);
	scene->objs[0] = *obj0; */

	// Esfera 2
/* 	t_shape sphere2 = new_shape(sh_sphere);
	sphere2.sp->center = ft_vec3(0.0f, 20.0f, 20.0f);
	sphere2.sp->radius = 4.3f;
	t_object *obj1 = object_new(sh_sphere, sphere2);
	obj1->material.color = ft_vec4(0.0f, 255.0f, 0.0f, 1.0f);
	scene->objs[1] = *obj1;

	// Plano 1
	t_shape plane1 = new_shape(sh_plane);
	plane1.pl->point = ft_vec3(0.0f, 0.0f, -10.0f);
	plane1.pl->normal = ft_vec3(0.0f, 1.0f, 0.0f);
	plane1.pl->material.color = ft_vec4(155.0f, 155.0f, 5.0f, 1.0f);
	t_object *obj2 = object_new(sh_plane, plane1);
	obj2->material.color = ft_vec4(155.0f, 155.0f, 5.0f, 1.0f);// No se si es necesario.
	scene->objs[2] = *obj2;
	
	// Cilindro 1
	t_shape cylinder1 = new_shape(sh_cylinder);
	cylinder1.cy->center = ft_vec3(50.0f, 0.0f, 20.0f);
	cylinder1.cy->normal = ft_vec3(0.0f, 0.0f, 1.0f);
	cylinder1.cy->height = 21.42f;
	cylinder1.cy->radius = 7.1f;
	t_object *obj3 = object_new(sh_cylinder, cylinder1);
	obj3->material.color = ft_vec4(15.0f, 0.0f, 165.0f, 1.0f);
	scene->objs[3] = *obj3;

	// Cilindro 2
	t_shape cylinder2 = new_shape(sh_cylinder);
	cylinder2.cy->center = ft_vec3(50.0f, 50.0f, 20.0f);
	cylinder2.cy->normal = ft_vec3(0.0f, 0.0f, 1.0f);
	cylinder2.cy->height = 13.42f;
	cylinder2.cy->radius = 7.1f;
	t_object *obj4 = object_new(sh_cylinder, cylinder2);
	obj4->material.color = ft_vec4(15.0f, 200.0f, 165.0f, 1.0f);
	scene->objs[4] = *obj4; */
	return (0);
}

// Función para printear las estructuras después del parser.
void	test_parser(t_scene	scene)
{
	int i = 0;
	printf(BROWN"cam->angle_view: %f\n", scene.cam->angle_of_view);
	printf(BROWN"cam->pos: %f,%f,%f\n", scene.cam->pos_cam.x,scene.cam->pos_cam.y,scene.cam->pos_cam.z);
	printf(BROWN"cam->scale: %f,%f,%f\n"END, scene.cam->scale_cam.x, scene.cam->scale_cam.y,scene.cam->scale_cam.z);
	
	while (i < scene.lgts_count)
	{
		printf(GREEN"ligth %d brightness: %f\n", i, scene.lights[i].brightness);
		printf("ligth %d color: %f,%f,%f\n", i, scene.lights[i].color.x, scene.lights[i].color.y, scene.lights[i].color.z);
		printf("ligth %d pos: %f,%f,%f\n"END, i, scene.lights[i].pos.x, scene.lights[i].pos.y, scene.lights[i].pos.z);
		i++;
	}
	i = 0;
	while (i < scene.objs_count)
	{
        if (scene.objs[i].type == sh_cylinder)
		{
            printf(MAGENTA"obj cy: %d type: %d\n", i, scene.objs[i].type);
            printf("obj cy: %d height: %f\n", i, scene.objs[i].shape.cy->height);
            printf("obj cy: %d radius: %f\n", i, scene.objs[i].shape.cy->radius);
            printf("obj cy: %d center: %f,%f,%f\n", i, scene.objs[i].shape.cy->center.x, scene.objs[i].shape.cy->center.y, scene.objs[i].shape.cy->center.z);
            printf("obj cy: %d normal: %f,%f,%f\n", i, scene.objs[i].shape.cy->normal.x, scene.objs[i].shape.cy->normal.y, scene.objs[i].shape.cy->normal.z);
            printf("obj cy: %d color: %f,%f,%f\n"END, i, scene.objs[i].material.color.x, scene.objs[i].material.color.y, scene.objs[i].material.color.z);
			if (scene.objs[i].material.has_texture == TRUE)
				printf("obj cy: %d texture: %s\n"END, i, scene.objs[i].material.texture);
        }
        else if (scene.objs[i].type == sh_plane)
        {
            printf(RED"obj pl: %d type: %d\n", i, scene.objs[i].type);
            printf("obj pl: %d np: %f\n", i, scene.objs[i].shape.pl->np);
            printf("obj pl: %d point: %f,%f,%f\n", i, scene.objs[i].shape.pl->point.x, scene.objs[i].shape.pl->point.y, scene.objs[i].shape.pl->point.z);
            printf("obj pl: %d normal: %f,%f,%f\n", i, scene.objs[i].shape.pl->normal.x, scene.objs[i].shape.pl->normal.y, scene.objs[i].shape.pl->normal.z);
            printf("obj pl: %d color: %f,%f,%f\n"END, i, scene.objs[i].material.color.x, scene.objs[i].material.color.y, scene.objs[i].material.color.z);
        }
		i++;
	}
	
}