/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:47:07 by apidgeot          #+#    #+#             */
/*   Updated: 2019/12/16 13:36:37 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;

typedef struct	s_etris
{
	int			height;
	int			width;
	char		**pos;
	char		value;
}				t_etris;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

t_etris			read_tetri(int fd);
void			print_map(t_map	*map);
void			free_map(t_map *map);
int				place(t_etris *tetri, t_map *map, int x, int y);
t_map			new_map(int size);
void			set_piece(t_etris *tetri, t_map *map, t_point *point,
		char value);
t_list			*solve(t_list *list);
t_point			new_point(int x, int y);
t_etris			new_tetris(char **pos, int width, int height, char value);
void			*free_tetris(t_etris *tetri);
t_list			*free_list(char *list);

#endif
