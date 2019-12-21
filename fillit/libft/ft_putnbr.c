/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:41:22 by apidgeot          #+#    #+#             */
/*   Updated: 2019/09/17 11:47:37 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int p;
	int last;

	last = n % 10;
	n /= 10;
	if (last < 0 || n < 0)
	{
		ft_putchar('-');
		n = -n;
		last = -last;
	}
	if (n != 0)
	{
		p = 1;
		while (p * 10 <= n)
			p *= 10;
		while (p != 0)
		{
			ft_putchar(n / p % 10 + '0');
			p /= 10;
		}
	}
	ft_putchar(last + '0');
}
