/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:15:46 by apidgeot          #+#    #+#             */
/*   Updated: 2019/09/20 12:00:52 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char*)arr1;
	b = (unsigned char*)arr2;
	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return ((int)a[i] - b[i]);
		i++;
	}
	return (0);
}
