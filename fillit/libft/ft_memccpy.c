/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:37:44 by apidgeot          #+#    #+#             */
/*   Updated: 2019/09/20 15:53:47 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char*)dst;
	b = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		if (b[i] == (unsigned char)c)
			return ((void*)dst + i + 1);
		i++;
	}
	return (NULL);
}
