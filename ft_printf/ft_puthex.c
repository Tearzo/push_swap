/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavorapa <pavorapa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 04:19:22 by pavorapa          #+#    #+#             */
/*   Updated: 2025/01/31 01:53:36 by pavorapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(char form, unsigned int num)
{
	int		len;
	char	*digits;

	len = 0;
	digits = NULL;
	if (form == 'x')
		digits = "0123456789abcdef";
	else if (form == 'X')
		digits = "0123456789ABCDEF";
	else
		return (0);
	if (num >= 16)
		len += ft_puthex(form, (num / 16));
	len += ft_putchar(digits[num % 16]);
	return (len);
}
