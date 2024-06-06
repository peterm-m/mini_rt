#include "minirt.h"

int get_sp_vars(char **l_info,t_scene *scene, char *id)
{
    int i;
    int size;

    i = 0;
    size = ft_strlen(id);
    while (l_info[i])
    {
        if (ft_strncmp(l_info[i], id, size))
        i++;
    }
    return (EXIT_SUCCESS);
}

int get_pl_vars(char **l_info,t_scene *scene, char *id)
{
    int i;
    int size;

    i = 0;
    size = ft_strlen(id);
    while (l_info[i])
    {
        if (ft_strncmp(l_info[i], id, size))
        i++;
    }
    return (EXIT_SUCCESS);
}

int get_cy_vars(char **l_info,t_scene *scene, char *id)
{
    int i;
    int size;

    i = 0;
    size = ft_strlen(id);
    while (l_info[i])
    {
        if (ft_strncmp(l_info[i], id, size))
        i++;
    }
    return (EXIT_SUCCESS);
}