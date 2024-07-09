#include "minirt.h"

int	is_valid_xpm(char *path)
{
	int	fd;
	int	size;
    char *file;
    
	size = ft_strlen(path) - 4;
	if (size < 5 || ft_strncmp(path + size, ".xpm", 4) != 0)
		return (FALSE);
    file = ft_strjoin("./", path + 4);
 	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (free(file), FALSE);
	close(fd);
    free(file);
	return (TRUE);
}

int	is_valid_rt(char *path)
{
	int	size;

	size = ft_strlen(path) - 3;
	if (size < 3 || ft_strncmp(path + size, ".rt", 3) != 0)
		return (FALSE);
	return (TRUE);
}