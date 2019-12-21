/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:01:23 by apidgeot          #+#    #+#             */
/*   Updated: 2019/09/20 12:13:04 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *dest, const char *append, size_t n)
{
	unsigned int	i;
	size_t			j;

	i = 0;
	i = ft_strlen(dest);
	j = 0;
	while (append[j] != '\0' && j < n)
	{
		dest[i + j] = append[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
