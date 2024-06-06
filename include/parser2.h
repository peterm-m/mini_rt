#ifndef PARSER2_H
# define PARSER2_H

int ft_parser(t_scene *scene, int argc, char **argv);

int get_A_vars(char **l_info, t_scene *scene);
int get_C_vars(char **l_info, t_scene *scene);
int get_L_vars(char **l_info, t_scene *scene);

int get_sp_vars(char **l_info, t_scene *scene, char *id);
int get_pl_vars(char **l_info, t_scene *scene, char *id);
int get_cy_vars(char **l_info, t_scene *scene, char *id);

int is_object(char *l);
int in_range(float a, float b, char *num);
int get_colors(t_ligth *a_ligth, char *line);
int get_coords(t_vec3 *vec, char *line);
int get_vector(t_vec3 *vec, char *line);

float ft_atof(const char *str);


#endif