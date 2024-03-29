/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:36:20 by apidgeot          #+#    #+#             */
/*   Updated: 2019/11/16 16:50:53 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_map(t_map	*map)
{
    int i;

    i = 0;
    while (i < map->size)
    {
        ft_putstr(map->array[i]);
        ft_putchar('\n');
        i++;
    }
}
void		free_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->size)
    {
        ft_memdel((void **)&(map->array[i]));
        i++;
    }
    ft_memdel((void **)&(map->array));
    ft_memdel((void **)&map);
}

t_map       new_map(int size)
{
    t_map   *map;
    int     i;
    int     j;

    map = (t_map *)ft_memalloc(sizeof(t_map));
    map->size = size;
    map->array = (char *)ft_memalloc(sizeof(char *) * size);
    i = 0;
    while(i < size)
    {
        map->array[i] = ft_strnew(size);
        j = 0;
        while (j < size)
        {
            map->array[i][j] = ".";
            j++;
        }
        i++;
    }
    return (map);
}

void        set_piece(t_etris *tetri, t_map *map, t_point *point, char value)
{
    int     i;
    int     j;

    i = 0;
    while (i < tetri->width)
    {
        j = 0;
        while (j < tetri->height)
        {
            if (tetri->pos[j][i] == '#')
                map->array[point->y + j][point ->x + i] = value;
            j++;
        }
        i++;
    }
    ft_memdel(void ** (&point));
}

int         place(t_etris *tetri, t_map *map, int x, int y)
{
    int i;
    int j;

    i = 0;
    while (i < tetri->width)
    {
        j = 0;
        while (j < tetri->height)
        {
            if (tetri->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
                return (0);
            j++;
        }
        i++;
    }
    set_piece(tetri, map, new_point(x, y), tetri->value);
    return (1);
}