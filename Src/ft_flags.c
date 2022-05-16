/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:23:08 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/16 19:45:33 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/ft_printf.h"

int	ft_chekflags(char chr)
{
	if (chr == '#' || chr == '+' || chr == ' ')
		return (1);
	return (0);
}

int	ft_checksf(char sf)
{
	if (sf == 'i' || sf == 'd' || sf == 'x' || sf == 'X')
		return (1);
	return (0);
}

int	ft_puthash(char c)
{
	if (c == 'x')
		write(1, "0x", 2);
	else if (c == 'X')
		write(1, "0X", 2);
	return (2);
}

int	ft_plus(int vlu)
{
	int	len;

	len = 0;
	if (vlu >= 0)
		len += write(1, "+", 1);
	len += ft_putnbr(vlu);
	return (len);
}

int	ft_flagcase(va_list lst, const char *str, int *i)
{
	int	vlu;
	int	len;

	len = 0;
	while (!ft_checksf(str[*i]))
	{
		if (str[*i] == '#' && (str[*i + 1] == 'x' || str[*i + 1] == 'X'))
		{
			vlu = va_arg(lst, int);
			if (vlu)
				len += ft_puthash(str[*i + 1]);
			len += ft_puthexa(vlu, str[*i + 1]);
		}
		else if (str[*i] == '+' && (str[*i + 1] == 'd' || str[*i + 1] == 'i'))
			len += ft_plus(va_arg(lst, int));
		else if (str[*i] == ' ' && (str[*i + 1] == 'd' || str[*i + 1] == 'i'))
		{
			vlu = va_arg(lst, int);
			if (vlu >= 0)
				len += write(1, " ", 1);
			len += ft_putnbr(vlu);
		}
		(*i)++;
	}
	return (len);
}
