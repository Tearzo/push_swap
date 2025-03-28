/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavorapa <pavorapa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:39:45 by pavorapa          #+#    #+#             */
/*   Updated: 2025/01/31 01:55:30 by pavorapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv(char form, va_list args)
{
	if (form == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (form == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (form == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (form == 'd' || form == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (form == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (form == 'x' || form == 'X')
		return (ft_puthex(form, va_arg(args, unsigned int)));
	else if (form == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	n;

	va_list(args);
	va_start(args, format);
	i = 0;
	n = 0;
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			n += conv(format[++i], args);
		else
			n += ft_putchar(format[i]);
		i++;
	}
	return (va_end(args), n);
}

// int	main(void)
//{
//	printf("nb=%d\n", ft_printf(NULL));
//}
