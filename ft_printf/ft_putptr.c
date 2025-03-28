/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavorapa <pavorapa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 05:34:06 by pavorapa          #+#    #+#             */
/*   Updated: 2025/01/31 01:54:20 by pavorapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_base(const unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += conv_base(n / 16);
		len += conv_base(n % 16);
	}
	else
	{
		if (n < 10)
			len += ft_putchar(n + '0');
		else
			len += ft_putchar('a' + (n - 10));
	}
	return (len);
}

int	ft_putptr(void *nbr)
{
	int			len;
	long int	p;

	p = (unsigned long)nbr;
	if (!nbr)
		return (ft_putstr("(nil)"));
	len = ft_putstr("0x");
	len += conv_base(p);
	return (len);
}
