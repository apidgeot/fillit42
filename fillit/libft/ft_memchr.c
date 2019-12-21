/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:53:35 by apidgeot          #+#    #+#             */
/*   Updated: 2019/09/17 12:51:34 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char*)src;
	i = 0;
	while (++i <= n)
	{
		if (*(a++) == (unsigned char)c)
			return ((void*)--a);
	}
	return (NULL);
}
