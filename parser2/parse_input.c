#include "minirt.h"

/* int ft_strsubstr(char *str, char *to_find)
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
} */

static int init_scene(char *line, t_scene *scene)
{
    char        **line_info;

    line_info = ft_split(line, ' ');
    if (ft_strncmp(line, 'A', 1))
        return (get_A_vars(line_info, scene, "A"));
    if (ft_strncmp(line, 'C', 1))
        return (get_C_vars(line_info, scene));
    if (ft_strncmp(line, 'L', 1))
        return (get_L_vars(line_info, scene, "L"));
    if (ft_strncmp(line, 'sp', 2))
        return (get_sp_vars(line_info, scene, "sp"));
    if (ft_strncmp(line, 'pl', 2))
        return (get_pl_vars(line_info, scene, "pl"));
    if (ft_strncmp(line, 'cy', 2))
        return (get_cy_vars(line_info, scene, "cy"));
    else
        return (EXIT_FAILURE);
}

static int get_input(int fd, t_scene *scene)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (EXIT_FAILURE);
	while (line)
	{
		if (init_scene(line, scene) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}


int init_struct(t_scene *s, fd)
{
    static int  ACLO[4] = {0, 0, 0, 0};

	while (1)
	{
		line = get_next_line(fd);
        if (!line)
		    return (EXIT_FAILURE);
        if (ft_strncmp(line, "A", 1) == 0)
           ACL0[0] += 1;
        if (ft_strncmp(line, "C", 1) == 0)
           ACLO[1] += 1;
        if (ft_strncmp(line, "L", 1) == 0)
            ACLO[2] += 1;
        if (is_object(line))
            ACLO[3] += 1;
	}
    if (ACLO[0] != 1 || ACLO[1] != 1)
		return (EXIT_FAILURE);
    s->lights = (t_light *)malloc(sizeof(t_light) * (ACLO[2] + 1));
    s->objs = (t_object *)malloc(sizeof(t_object) * ACLO[3]);
    s->cam = (t_camera)malloc(sizeof(t_camera));
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
    if (init_structs(fd, scene) == EXIT_FAILURE)
        return (close(fd), EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (get_input(fd, scene) == EXIT_FAILURE)
		return (close(fd), EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}