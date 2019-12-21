/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:41:09 by apidgeot          #+#    #+#             */
/*   Updated: 2019/12/16 13:21:29 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		new_point(int x, int y)
{
	t_point	*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

t_etris		new_tetris(char **pos, int width, int height, char value)
{
	t_etris		*tetris;

	tetris = ft_memalloc(sizeof(t_etris);
	tetris->pos = pos;
	tetris->width = width;
	tetris->height = height;
	tetris->value = value;
	return (tetris);
}

t_list		*free_list(char *list)
{
	t_etris		*tetris;
	t_list		*list;

	while (list)
	{
		tetris = (t_etris *)list->content;
		next = list->next;
		free_tetris(tetris);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void		*free_tetris(t_etris *tetri)
{
	int		i;

	i = 0;
	while (i < tetri->height)
	{
		ft_memdel((void **)&(tetri->pos[i]));
		i++;
	}
	ft_memdel((void **)&(tetri->pos));
	ft_memdel((void **)&tetri);
}
