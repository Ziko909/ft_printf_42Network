/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:22:30 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/16 19:45:40 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/ft_printf.h"

int	ft_checksfnc(char sf)
{
	if (sf == 'i' || sf == 'd' || sf == 'x'
		|| sf == 'X' || sf == 'p' || sf == 's'
		|| sf == 'c' || sf == 'u')
		return (1);
	return (0);
}

int	ft_normalcase(va_list lst, char sf)
{
	int	len;

	len = 0;
	if (sf == 's')
		len += ft_putstr(va_arg(lst, char *));
	else if (sf == 'c')
		len += ft_putchar(va_arg(lst, int));
	else if (sf == 'd' || sf == 'i')
		len += ft_putnbr(va_arg(lst, int));
	else if (sf == 'x' || sf == 'X')
		len += ft_puthexa(va_arg(lst, int), sf);
	else if (sf == 'u')
		len += ft_putun(va_arg(lst, unsigned int));
	else if (sf == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_putaddr(va_arg(lst, unsigned long));
	}
	return (len);
}
