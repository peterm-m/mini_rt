#include "minirt.h"

void free_scene(t_scene *scene)
{
    int i;

    i = 0; 
/*     while (&scene->lights[i])
    {
        ft_putendl_fd("freeeeeee", 1);
        free(&scene->lights[i]);
        i++;
    } */
    free(scene->lights);
    i = -1;
    while (&scene->objs[++i])
    {
        object_destroy(&scene->objs[i]);
        printf("objeto: %d\n", i);
    }
    printf(CYAN"%p\n"END, scene->objs);
    //free(scene->objs);
    camera_destroy(scene->cam);
}

static int init_scene(char *line, t_scene *scene, int lgt_id, int obj_id)
{
    char        **line_info;
    int         exit;

    if (line[0] == '\n')
        return (EXIT_SUCCESS);
    line_info = ft_split(line, ' ');
    printf("line: %s\n", line_info[0]);
    if (ft_strncmp(line, "A", 1) == 0)
        exit = get_A_vars(line_info, scene);
    else if (ft_strncmp(line, "C", 1) == 0)
        exit = get_C_vars(line_info, scene);
    else if (ft_strncmp(line, "L", 1) == 0)
        exit = get_L_vars(line_info, scene, lgt_id);
    else if (ft_strncmp(line, "sp", 2 == 0))
        exit = get_sp_vars(line_info, scene, obj_id);
    else if (ft_strncmp(line, "pl", 2) == 0)
        exit = get_pl_vars(line_info, scene, obj_id);
    else if (ft_strncmp(line, "cy", 2) == 0)
        exit = get_cy_vars(line_info, scene, obj_id);
    else if (ft_strncmp(line, "bx", 2 == 0))
        exit = get_bx_vars(line_info, scene, obj_id);
    else
        exit = EXIT_FAILURE;
    ft_free_arr(line_info);
    return (exit);
}

static int get_input(int fd, t_scene *scene)
{
	char	*line;
    int     light_index;
    int     obj_index;

    light_index = 0;
    obj_index = -1;
	while (1)
	{
		line = get_next_line(fd);
        if (!line)
            break;
        if (ft_strncmp(line, "L", 1) == 0)
            light_index++;
        else if (is_object(line))
            obj_index++;
		if (init_scene(line, scene, light_index, obj_index) == EXIT_FAILURE) 
			return (free(line), EXIT_FAILURE);
        free(line);
	}
    free(line);
	return (EXIT_SUCCESS);
}


int init_structs(t_scene *s, int fd)
{
    static int  aclo[4] = {0, 0, 0, 0};
    char        *line;

	while (1)
	{
		line = get_next_line(fd);
        if (!line)
            break;
        if (ft_strncmp(line, "A", 1) == 0)
            aclo[0] += 1;
        else if (ft_strncmp(line, "C", 1) == 0)
            aclo[1] += 1;
        else if (ft_strncmp(line, "L", 1) == 0)
            aclo[2] += 1;
        else if (is_object(line))
            aclo[3] += 1;
        free(line);
	}
    free(line);
    if (aclo[0] != 1 || aclo[1] != 1)
		return (EXIT_FAILURE);
    printf(GREEN "suma luces: %d\n", aclo[2] + 1);
    printf("suma objetos: %d\n"END, aclo[3]);
    s->lights = malloc(sizeof(t_light) * (aclo[2] + 1));
    s->objs = malloc(sizeof(t_object) * aclo[3]);
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
		return (close(fd), EXIT_FAILURE);
    else if (init_structs(scene, fd) == EXIT_FAILURE)
        return (close(fd), EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (get_input(fd, scene) == EXIT_FAILURE)
    {
        free_scene(scene);
        perror (RED"Erro000r\n"END);
		return (close(fd), EXIT_FAILURE);// TODO: Liberar structuras
    }
	close(fd);
    perror (GREEN"OK\n"END);
    free_scene(scene);
	return (EXIT_SUCCESS);
}