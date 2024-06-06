#include "minirt.h"

int is_object(char *l)
{
    static char *objs = {"sp", "pl", "cy"}
    int i;

    i = 0;
    while (objs[i])
    {
        if (ft_strncmp(line, objs[i], 2) == 0)
            return (TRUE);
        i++;
    } 
    return (FALSE);
}

int in_range(float a, float b, char *num)
{
     if (ft_atof(rgb[0]) >= a || ft_atof(rgb[0]) <= b)
        return (TRUE);
    return (FALSE);
}

int get_colors(t_vec4 *color, char *line)
{
    char **rgb;

    rgb = ft_split(line, ',');
    if (rgb[3] || !in_range(0.0, 255.0, rgb[0]) || !in_range(0.0, 255.0, rgb[1])
        || !in_range(0.0, 255.0, rgb[1]))
        return (EXIT_FAILURE);
    color = ft_vec4(ft_atof(rgb[0]), ft_atof(rgb[1]), ft_atof(rgb[2]), 1.0);
    return (EXIT_SUCCESS);
}

int get_coords(t_vec3 *vec, char *line)
{
    char **xyz;

    xyz = ft_split(line, ',');
    if (xyz[3] || !in_range(__FLT_MIN__, __FLT_MAX__, xyz[0])
        || !in_range(__FLT_MIN__, __FLT_MAX__, xyz[1])
        || !in_range(__FLT_MIN__, __FLT_MAX__, xyz[1]))
        return (EXIT_FAILURE);
    vec = ft_vec3(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
    return (EXIT_SUCCESS);
}

int get_vector(t_vec3 *vec, char *line)
{
    char **xyz;

    xyz = ft_split(line, ',');
    if (xyz[3] || !in_range(-1.0f, 1.0f, xyz[0])
        || !in_range(-1.0f, 1.0f, xyz[1])
        || !in_range(-1.0f, 1.0f, xyz[1]))
        return (EXIT_FAILURE);
    vec = ft_vec3(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
    return (EXIT_SUCCESS);
}

