/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:03:39 by apidgeot          #+#    #+#             */
/*   Updated: 2019/09/17 12:56:12 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcat(char *dest, const char *append)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		++i;
	while (append[j] != '\0')
	{
		dest[i] = append[j];
		++j;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
