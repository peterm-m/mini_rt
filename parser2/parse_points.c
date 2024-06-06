#include "minirt.h"

int get_A_vars(char **l_info, t_scene *scene)
{
    int i;

    i = 1;
    scene->lights[0].type = lgh_ambient;
    while (l_info[i])
    {
        else if (ft_strchr(l_info[i], ',') != NULL)
        {
            if (get_colors(scene->lights[0], l_info[i]) == EXIT_FAILURE)
                return (EXIT_FAILURE);
        }
        else if (in_range(0.0, 1.0, l_info[i]))
            scene->lights[0]->brightness = ft_atof(l_info[i]);
        else
            return (EXIT_FAILURE);
        i++;
    }
    return (EXIT_SUCCESS);
}


int get_C_vars(char **l_info, t_scene *scene)
{
    if (get_coords(scene->cam.pos_cam, l_info[1]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (get_vector(scene->cam.scale_cam, l_info[2]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (!in_range(0.0f, 180.0f, l_info[3]))
        return (EXIT_FAILURE);
    scene->cam.angle_of_view = ft_atof(l_info[3]);
    if (l_info[4])
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int get_L_vars(char **l_info, t_scene *scene, int light_id)
{
    if (get_coords(scene->lights[light_id]->pos, l_info[1]) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (!in_range(0.0f, 1.0f, l_info[2]))
        return (EXIT_FAILURE);
    scene->lights[light_id]->brightness = ft_atof(l_info[2]);
    if (get_colors(scene->lights[light_id].color, l_info[3]) == EXIT_FAILURE)
                return (EXIT_FAILURE);
    if (l_info[4])
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS); 
}   