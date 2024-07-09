#include "minirt.h"

int parse_extra_params(t_scene *scene, char *param, int o_id)
{
    printf("param: %s\n", param);
    int i;

    i = 0;
    while (param[i])
    {
        if (param[i] == '\n')
            param[i] = '\0';
        i++;
    }
    if (ft_strncmp(param, "txm", 3) == 0)
    {
        if (is_valid_xpm(param) == TRUE)
            {
                scene->objs[o_id].material.has_texture = TRUE;
                scene->objs[o_id].material.texture = param;
            }
        else
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int get_sp_vars(char **l_info, t_scene *scene, int o_id)
{
    t_shape  shape;

    if (arr_size(l_info) != 4 && arr_size(l_info) != 5)
        return (EXIT_FAILURE);
    shape = new_shape(sh_sphere);
    if (get_coords(&shape.sp->center, l_info[1]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (!in_range(0.0f, __FLT_MAX__, l_info[2]))
        return (EXIT_FAILURE);
    shape.sp->radius = ft_atof(l_info[2]);
    scene->objs[o_id] = object_new(sh_sphere, shape);
    if (get_colors(&scene->objs[o_id].material.color, l_info[3]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (arr_size(l_info) == 5)
        if (parse_extra_params(scene, l_info[4], o_id) == EXIT_FAILURE)
            return (EXIT_FAILURE);
    scene->objs[o_id].type = sh_sphere;
    return (EXIT_SUCCESS); 
}

int get_pl_vars(char **l_info, t_scene *scene, int o_id)
{
    t_shape  shape;

    if (arr_size(l_info) != 4)
        return (EXIT_FAILURE);
    shape = new_shape(sh_plane);
    if (get_coords(&shape.pl->point, l_info[1]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (get_vector(&shape.pl->normal, l_info[2]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    scene->objs[o_id] = object_new(sh_plane, shape);
    if (get_colors(&scene->objs[o_id].material.color, l_info[3]) == EXIT_FAILURE)
                return (EXIT_FAILURE);
    scene->objs[o_id].type = sh_plane;
    return (EXIT_SUCCESS); 
}

int get_cy_vars(char **l_info, t_scene *scene, int o_id)
{
    t_shape  shape;

    if (arr_size(l_info) != 6 && arr_size(l_info) != 7)
        return (EXIT_FAILURE);
    shape = new_shape(sh_cylinder);
    if (get_coords(&shape.cy->center, l_info[1]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (get_vector(&shape.cy->normal, l_info[2]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (!in_range(0.0f, __FLT_MAX__, l_info[3]))
        return (EXIT_FAILURE);
    shape.cy->radius = ft_atof(l_info[3]) / 2.0f;
    if (!in_range(0.0f, __FLT_MAX__, l_info[4]))
        return (EXIT_FAILURE);
    shape.cy->height = ft_atof(l_info[4]);
    scene->objs[o_id] = object_new(sh_cylinder, shape);
    if (get_colors(&scene->objs[o_id].material.color, l_info[5]) == EXIT_FAILURE)
                return (EXIT_FAILURE);
    if (arr_size(l_info) == 7)
        if (parse_extra_params(scene, l_info[6], o_id) == EXIT_FAILURE)
            return (EXIT_FAILURE);
    scene->objs[o_id].type = sh_cylinder;
    return (EXIT_SUCCESS); 
}

int get_bx_vars(char **l_info, t_scene *scene, int o_id)
{
    t_shape  shape;

    if (arr_size(l_info) != 4)
        return (EXIT_FAILURE);
    shape = new_shape(sh_box);
    if (get_coords(&shape.bx->center, l_info[1]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (get_vector(&shape.bx->half_side, l_info[2]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    scene->objs[o_id] = object_new(sh_box, shape);
    if (get_colors(&scene->objs[o_id].material.color, l_info[3]) == EXIT_FAILURE)
                return (EXIT_FAILURE);
    scene->objs[o_id].type = sh_box;
    return (EXIT_SUCCESS);
}