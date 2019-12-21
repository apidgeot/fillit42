/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:57:54 by apidgeot          #+#    #+#             */
/*   Updated: 2019/09/12 14:38:32 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int val, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)a;
	while (len-- > 0)
		*(ptr++) = (unsigned char)val;
	return (a);
}
