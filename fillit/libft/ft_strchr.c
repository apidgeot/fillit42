/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:57:12 by apidgeot          #+#    #+#             */
/*   Updated: 2019/12/02 11:03:04 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int s)
{
	while (*str)
	{
		if (*str == s)
			return ((char*)str);
		++str;
	}
	if (s == '\0')
		return ((char*)str);
	return (NULL);
}
