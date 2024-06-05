#include "minirt.h"

int ft_strsubstr(char *str, char *to_find)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == to_find[j])
        {
            while (to_find[j])
            {
                if (str[i] != to_find[j])
                    return (False);
                i++;
                j++;
            }
        }
        i++;
    }
    return (True);
}

int get_A_vars(char **info,t_scene *scene, char *id)
{
    int i;
    int size;

    i = 0;
    size = ft_strlen(id);
    while (info[i])
    {
        if (ft_strncmp(info[i], id, size))
        i++;
    }
    return (EXIT_SUCCESS);
}

int get_C_vars(char **info,t_scene *scene, char *id)
{
    int i;
    int size;

    i = 0;
    size = ft_strlen(id);
    while (info[i])
    {
        if (ft_strncmp(info[i], id, size))
        i++;
    }
    return (EXIT_SUCCESS);
}

int get_L_vars(char **info,t_scene *scene, char *id)
{
    int i;
    int size;

    i = 0;
    size = ft_strlen(id);
    while (info[i])
    {
        if (ft_strncmp(info[i], id, size))
        i++;
    }
    return (EXIT_SUCCESS);
}   

int get_sp_vars(char **info,t_scene *scene, char *id)
{
    int i;
    int size;

    i = 0;
    size = ft_strlen(id);
    while (info[i])
    {
        if (ft_strncmp(info[i], id, size))
        i++;
    }
    return (EXIT_SUCCESS);
}

int get_pl_vars(char **info,t_scene *scene, char *id)
{
    int i;
    int size;

    i = 0;
    size = ft_strlen(id);
    while (info[i])
    {
        if (ft_strncmp(info[i], id, size))
        i++;
    }
    return (EXIT_SUCCESS);
}

int get_cy_vars(char **info,t_scene *scene, char *id)
{
    int i;
    int size;

    i = 0;
    size = ft_strlen(id);
    while (info[i])
    {
        if (ft_strncmp(info[i], id, size))
        i++;
    }
    return (EXIT_SUCCESS);
}


static int init_scene(char *line, t_scene *scene)
{
    char        **info;

    info = ft_split(line, ' ');
    if (ft_strsubstr(line, "A"))
        return (get_A_vars(info, scene, "A"));
    if (ft_strsubstr(line, "C"))
        return (get_C_vars(info, scene, "C"));
    if (ft_strsubstr(line, "L"))
        return (get_L_vars(info, scene, "L"));
    if (ft_strsubstr(line, "sp"))
        return (get_sp_vars(info, scene, "sp"));
    if (ft_strsubstr(line, "pl"))
        return (get_pl_vars(info, scene, "pl"));
    if (ft_strsubstr(line, "cy"))
        return (get_cy_vars(info, scene, "cy"));
    else
        return (EXIT_FAILURE);
}

static int get_input(int fd, t_scene *scene)
{
	char	*line;
    static int  AC[2] = {0, 0};

	line = get_next_line(fd);
	if (!line)
		return (EXIT_FAILURE);
	while (line)
	{
        if (ft_strsubstr(line, "A"))
            AC[0] += 1;
        if (ft_strsubstr(line, "C"))
            AC[1] += 1;
		if (init_scene(line, scene) == EXIT_FAILURE || AC[0] > 1 || AC[1 > 1])
			return (EXIT_FAILURE);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}

int ft_parser(t_scene *scene, int argc, char **argv)
{
	int fd;

	if (argc > 2)
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		return (EXIT_FAILURE);
	if (get_input(fd, scene) == EXIT_FAILURE)
		return (close(fd), EXIT_FAILURE);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (ft_init_vars(scene, fd))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}