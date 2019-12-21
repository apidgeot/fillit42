/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:32:15 by apidgeot          #+#    #+#             */
/*   Updated: 2019/12/16 13:44:39 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int         solve_map(t_map *map, t_list *list)
{
    t_etris     *tetri;
    int         x;
    int         y;

    if (list == NULL)
        return (1);
    y = 0;
    tetri = (t_etris *)(list->content);
    if (y < map->size - tetri->height + 1)
    {
        x = 0;
        while (x < map->size - tetri->width + 1)
        {
            if (place(tetri, map, x, y))
            {
                if (solve(map, list->next))
                    return (1);
                else 
                    set_piece(tetri, map, new_point(x, y), '.')
            }
            x++;
        }
        y++;
    }
    return (0);
}

int         high_sqrt(int n)
{
    int     size;

    size = 2;
    while (size * size < n)
        size++;
    return (size);
}

t_list      *solve(t_list *list)
{
    t_map   map;
    int     size;

    size = 0;
    size = high_sqrt(ft_listcount(list) * 4);
    map = map_new(size);
    while (!solve_map(map, list))
    {
        size++;
        free_map(map);
        map = map_new(size);
    }
    return (map);
}
