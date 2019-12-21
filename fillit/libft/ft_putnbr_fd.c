/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:58:46 by apidgeot          #+#    #+#             */
/*   Updated: 2019/09/17 12:07:35 by apidgeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int p;
	int last;

	last = n % 10;
	n /= 10;
	if (last < 0 || n < 0)
	{
		ft_putchar_fd('-', fd);
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
			ft_putchar_fd(n / p % 10 + '0', fd);
			p /= 10;
		}
	}
	ft_putchar_fd(last + '0', fd);
}
