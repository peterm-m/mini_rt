#include "minirt.h"

int  arr_size(char **arr)
{
    int i;
    int size;

    i = 0;
    size = 0;
    while (arr[i])
    {
        size++;
        i++;
    }
    return (size); 
}

void ft_free_arr(char **arr)
{
    int i;

    i = -1;
    while (arr[++i])
        free(arr[i]);
    free(arr);
}

int is_object(char *l)
{
    static  char *objs[4] = {"sp", "pl", "cy", "bx"};
    int             i;

    if (!l)
        return (EXIT_FAILURE);
    i = 0;
    while (i < 4)
    {
        if (ft_strncmp(l, objs[i], 2) == 0)
            return (TRUE);
        i++;
    } 
    return (FALSE);
}

int in_range(float a, float b, char *num)
{
    if (ft_atof(num) >= a && ft_atof(num) <= b)
        return (TRUE);
    return (FALSE);
}

int get_colors(t_vec4 *color, char *line)
{
    char **rgb;

    if (!line)
        return (EXIT_FAILURE);
    rgb = ft_split(line, ',');
    if (arr_size(rgb) != 3 || !in_range(0.0f, 255.0f, rgb[0]) || !in_range(0.0f, 255.0f, rgb[1])
        || !in_range(0.0f, 255.0f, rgb[2]))
    {
        ft_free_arr(rgb);
        return (EXIT_FAILURE);
    }
    *color = ft_vec4(ft_atof(rgb[0]), ft_atof(rgb[1]), ft_atof(rgb[2]), 0.0);
    ft_free_arr(rgb);
    return (EXIT_SUCCESS);
}

int get_coords(t_vec3 *vec, char *line)
{
    char **xyz;

    if (!line)
        return (EXIT_FAILURE);
    xyz = ft_split(line, ',');
    if (arr_size(xyz) != 3 || !in_range(-__FLT_MAX__, __FLT_MAX__, xyz[0])
        || !in_range(-__FLT_MAX__, __FLT_MAX__, xyz[1])
        || !in_range(-__FLT_MAX__, __FLT_MAX__, xyz[2]))
    {
        ft_free_arr(xyz);
        return (EXIT_FAILURE);
    }
    *vec = ft_vec3(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
    ft_free_arr(xyz);
    return (EXIT_SUCCESS);
}

int get_vector(t_vec3 *vec, char *line)
{
    char **xyz;

    if (!line)
        return (EXIT_FAILURE);
    xyz = ft_split(line, ',');
    if (arr_size(xyz) != 3 || !in_range(-1.0f, 1.0f, xyz[0])
        || !in_range(-1.0f, 1.0f, xyz[1])
        || !in_range(-1.0f, 1.0f, xyz[1]))
    {
        ft_free_arr(xyz);
        return (EXIT_FAILURE);
    }
    *vec = ft_vec3(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
    ft_free_arr(xyz);
    return (EXIT_SUCCESS);
}

