#include "minirt.h"

int get_sp_vars(char **l_info, t_scene *scene, int o_id)
{
    t_object *obj;
    t_shape  *shape;

    shape = new_shape(sh_sphere);
    if (get_coords(shape.sp->center, l_info[1]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (!in_range(0.0f, __FLT_MAX__, l_info[2]))
        return (EXIT_FAILURE);
    shape->sp->radius = ft_atof(l_info[2]);
    obj = object_new(sh_sphere, shape);
    if (get_colors(obj->material.color, l_info[3]) == EXIT_FAILURE)
                return (EXIT_FAILURE);
    if (l_info[4])
        return (EXIT_FAILURE);
    obj.type = sh_sphere;
    scene->objs[o_id] = obj;
    return (EXIT_SUCCESS); 
}

int get_pl_vars(char **l_info, t_scene *scene, int o_id)
{
    t_object *obj;
    t_shape  *shape;

    shape = new_shape(sh_plane);
    if (get_coords(shape.pl->point, l_info[1]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (get_vector(shape.pl->normal, l_info[2]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    obj = object_new(sh_plane, shape);
    if (get_colors(obj->material.color, l_info[3]) == EXIT_FAILURE)
                return (EXIT_FAILURE);
    if (l_info[4])
        return (EXIT_FAILURE);
    obj->type = sh_plane;
    scene->objs[o_id] = obj;
    return (EXIT_SUCCESS); 
}

int get_cy_vars(char **l_info, t_scene *scene, int o_id)
{
    t_object *obj;
    t_shape  *shape;

    shape = new_shape(sh_cylinder);
    if (get_coords(shape->cy->center, l_info[1]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (get_vector(shape->cy->normal, l_info[2]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (!in_range(0.0f, __FLT_MAX__, l_info[3]))
        return (EXIT_FAILURE);
    shape->cy->radius = ft_atof(l_info[3]) / 2.0f;
    if (!in_range(0.0f, __FLT_MAX__, l_info[4]))
        return (EXIT_FAILURE);
    shape->cy->height = ft_atof(l_info[4]);
    obj = object_new(sh_cylinder, shape);
    if (get_colors(obj->material.color, l_info[5]) == EXIT_FAILURE)
                return (EXIT_FAILURE);
    if (l_info[6])
        return (EXIT_FAILURE);
    obj.type = sh_cylinder;
    scene->objs[o_id] = obj;
    return (EXIT_SUCCESS); 
}

int get_bx_vars(char **l_info, t_scene *scene, int o_id)
{
    t_object *obj;
    t_shape  *shape;

    shape = new_shape(sh_box);
    if (get_coords(shape->bx->center, l_info[1]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (get_vector(shape->bx->half_side, l_info[2]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    obj = object_new(sh_box, shape);
    if (get_colors(obj->material.color, l_info[3]) == EXIT_FAILURE)
                return (EXIT_FAILURE);
    if (l_info[4])
        return (EXIT_FAILURE);
    obj.type = sh_box;
    scene->objs[o_id] = obj;
    return (EXIT_SUCCESS); 
}