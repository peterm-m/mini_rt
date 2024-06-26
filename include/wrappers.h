/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:18:49 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/27 16:57:06 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPERS_H
# define WRAPPERS_H

# include "mlx.h"
# include "mlx_int.h"
# include <stdlib.h>

void	*ft_getmlx(void);
void	*ft_new_image(int w, int h);
void	*ft_new_windows(int w, int h, char *name);
void	ft_put_image_to_window(t_image *img);
void	*mallox(size_t size);

#endif // WRAPPERS_H