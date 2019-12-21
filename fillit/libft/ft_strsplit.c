/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:09:50 by apidgeot          #+#    #+#             */
/*   Updated: 2019/09/21 18:58:16 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number(char const *s, char c)
{
	int	i;
	int	count;

	if (s[0] == '\0')
		return (0);
	count = 0;
	if (s[0] != c)
		count++;
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int	ft_len(const char *s, char c)
{
	int len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		word_number;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	word_number = ft_number(s, c);
	tab = (char**)malloc((word_number + 1) * sizeof(char*));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_number)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		tab[i] = ft_strsub(s, j, ft_len(s + j, c));
		while (s[j] != '\0' && s[j] != c)
			j++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
