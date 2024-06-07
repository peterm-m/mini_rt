#include "minirt.h"

static int init_scene(char *line, t_scene *scene, int lgt_id, int obj_id)
{
    char        **line_info;

    line_info = ft_split(line, ' ');
    if (ft_strncmp(line, 'A', 1))
        return (get_A_vars(line_info, scene));
    if (ft_strncmp(line, 'C', 1))
        return (get_C_vars(line_info, scene));
    if (ft_strncmp(line, 'L', 1))
        return (get_L_vars(line_info, scene, lgt_id));
    if (ft_strncmp(line, 'sp', 2))
        return (get_sp_vars(line_info, scene, obj_id));
    if (ft_strncmp(line, 'pl', 2))
        return (get_pl_vars(line_info, scene, obj_id));
    if (ft_strncmp(line, 'cy', 2))
        return (get_cy_vars(line_info, scene, obj_id));
    if (ft_strncmp(line, 'bx', 2))
        return (get_bx_vars(line_info, scene, obj_id));
    else
        return (EXIT_FAILURE);
}

static int get_input(int fd, t_scene *scene)
{
	char	*line;
    int     light_index;
    int     obj_index;

    light_index = 1;
    obj_index = 1;
	line = get_next_line(fd);
	if (!line)
		return (EXIT_FAILURE);
	while (line)
	{
        if (ft_strncmp(line, "L", 1) == 0)
            light_index++;
        else if (is_object(line))
            obj_index++;
		if (init_scene(line, scene, light_index, obj_index) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}


int init_struct(t_scene *s, int fd)
{
    static int  ACLO[4] = {0, 0, 0, 0};
    char *line;

	while (1)
	{
		line = get_next_line(fd);
        if (!line)
		    return (EXIT_FAILURE);
        if (ft_strncmp(line, "A", 1) == 0)
            ACLO[0] += 1;
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
    s->cam = camera_new();
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