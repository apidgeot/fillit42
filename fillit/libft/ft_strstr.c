/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:41:51 by apidgeot          #+#    #+#             */
/*   Updated: 2019/09/21 16:16:52 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t n;

	n = ft_strlen((char*)str2);
	if (ft_memcmp(str1++, str2, n) == 0)
		return ((char*)str1 - 1);
	while (*str1 != '\0')
	{
		if (ft_memcmp(str1++, str2, n) == 0)
			return ((char*)(str1 - 1));
	}
	return (NULL);
}
