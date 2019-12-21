/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:46:04 by apidgeot          #+#    #+#             */
/*   Updated: 2019/11/26 11:44:09 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	min_max(char *str, t_point min, t_point max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5  < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

t_etris	*get_piece(char *str, char value)
{
	t_etris	*tetri;
	int		i;
	t_point	*min;
	t_point	*max;
	char	**pos;
	
	min = new_point(3, 3);
	max = new_point(0, 0);
	min_max(str, min, max);
	pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i <= max->y - min->y)
	{
		pos[i] = ft_strnew(str, max->x - min->x + 1);
		ft_strncpy(pos[i], str + (min->x) + (i + min->y) * 5, max->x - min->x + 1);
		i++;
	}
	tetri = new_teris(pos, max->x - min->x, max->y - min->y, value);
	ft_memdel(void**(&min));
	ft_memdel(void**(&max));
	return (tetri);
}

int		connection(char *str)
{
	int i;
	int b;

	i = 0;
	b = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				b++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				b++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				b++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				b++;
		}
		i++;
	}
	return ( b == 6 || b == 8);
}

int		check(char *str, int count)
{
	int b;
	int i;

	i = 0;
	b = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++b > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (count == 21 && str[i] != '\n')
		return (4);
	if (!connection(str))
		return (5);
	return (0);
}

t_list		*read_tetri(int fd)
{
	int		count;
	char	*str;
	t_list	*list;
	char	value;

	str = ft_strnew(21);
	list = NULL;
	value = 'A';
	while (count = read(fd, str, 21) >= 20)
	{
		if (check(str, count) != 0 || (tetris = get_piece(*str, value++)) == NULL)
		{
			ft_memdel(void** (&str));
			return (free_list(list));
		}
	ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_etris)));
	ft_memdel((** void)&tetris);
	}
	ft_memdel((** void)&str);
	if (count != 0)
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}