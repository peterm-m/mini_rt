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

static float convert_num(char *str, int decimal_found, float fraction, float result)
{
    while (*str) 
    {
        if (ft_isdigit(*str)) 
        {
            if (decimal_found) 
            {
                fraction /= 10.0;
                result += (*str - '0') * fraction;
            } 
            else 
                result = result * 10.0 + (*str - '0');
        } 
        else if (*str == '.')
        {
            if (decimal_found) 
                break;
            decimal_found = 1;
        } 
        else 
            break;
        str++;
    }
    return (result);
}

float ft_atof(const char *str) {
    float result;
    float fraction;
    int sign;
    int decimal_found;

    result = 0.0;
    fraction = 1.0;
    sign = 1;
    decimal_found = 0;
    while (*str == ' ' || *str == '\t')
        str++;
    if (*str == '-') 
    {
        sign = -1;
        str++;
    } 
    else if (*str == '+')
        str++;
    result = convert_num(str, decimal_found, fraction, result);
    return (sign * result);
}

int in_range(float a, float b, char *num)
{
     if (ft_atof(rgb[0]) >= a || ft_atof(rgb[0]) <= b)
        return (TRUE);
    return (FALSE);
}

int get_colors(t_ligth *a_ligth, char *line)
{
    char **rgb;
    float     r;
    float     g;  
    float     b;

    rgb = ft_split(line, ',');
    colors = malloc (sizeof(t_vec4));
    if (!in_range(0.0, 255.0, rgb[0]) || !in_range(0.0, 255.0, rgb[1])
        || !in_range(0.0, 255.0, rgb[1]))
        return (EXIT_FAILURE);
    r = ft_atof(rgb[0]);
    g = ft_atof(rgb[1]);
    b = ft_atof(rgb[2]);
    a_ligth->color = ft_vec4(r, g, b, 1.0);
    return (EXIT_SUCCESS);
}

int get_A_vars(char **l_info,t_scene *scene, char *id)
{
    int i;
    int size;
    t_light *a_ligth;
    t_vec4 colors;

    a_ligth = malloc (sizeof(t_light));
    i = -1;
    size = ft_strlen(id);
    while (l_info[++i])
    {
        if (ft_strncmp(l_info[i], id, size))
            a_ligth->type = lgh_ambient;
        else if (ft_strchr(l_info[i], ',') != NULL)
        {
            if (get_colors(a_ligth, l_info[i]) == EXIT_FAILURE)
                return (EXIT_FAILURE);
        }
        else if (in_range(0.0, 1.0, l_info[i]))
            a_ligth->brightness = ft_atof(l_info[i]);
        else
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int get_C_vars(char **l_info,t_scene *scene, char *id)
{
    int i;
    int size;

    i = 0;
    size = ft_strlen(id);
    while (l_info[i])
    {
        if (ft_strncmp(l_info[i], id, size))
            ;
        else if ()
        i++;
    }
    return (EXIT_SUCCESS);
}

int get_L_vars(char **l_info,t_scene *scene, char *id)
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


static int init_scene(char *line, t_scene *scene)
{
    char        **line_info;

    line_info = ft_split(line, ' ');
    if (ft_strsubstr(line, "A"))
        return (get_A_vars(line_info, scene, "A"));
    if (ft_strsubstr(line, "C"))
        return (get_C_vars(line_info, scene, "C"));
    if (ft_strsubstr(line, "L"))
        return (get_L_vars(line_info, scene, "L"));
    if (ft_strsubstr(line, "sp"))
        return (get_sp_vars(line_info, scene, "sp"));
    if (ft_strsubstr(line, "pl"))
        return (get_pl_vars(line_info, scene, "pl"));
    if (ft_strsubstr(line, "cy"))
        return (get_cy_vars(line_info, scene, "cy"));
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