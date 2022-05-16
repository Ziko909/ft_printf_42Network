/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:01:22 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/16 19:45:58 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/ft_printf.h"

int	ft_putaddr(unsigned long i)
{
	char	*str;
	int		len;

	len = 0;
	str = "0123456789abcdef";
	if (i < 16)
		len += ft_putchar(str[i]);
	else
	{
		len += ft_putaddr(i / 16);
		len += ft_putaddr(i % 16);
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n >= 0 && n <= 9)
		len += ft_putchar(n + 48);
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putchar(n % 10 + 48);
	}
	if (n < 0 && n > -2147483648)
	{
		n *= -1;
		len += ft_putchar('-');
		len += ft_putnbr(n);
	}
	if (n == -2147483648)
		len += write(1, "-2147483648", 11);
	return (len);
}

int	ft_puthexa(unsigned int i, char xX)
{
	char	*str;
	int		len;
	int		mdlo;

	len = 0;
	if (xX == 'x')
		str = "0123456789abcdef";
	else if (xX == 'X')
		str = "0123456789ABCDEF";
	mdlo = i % 16;
	if (!(i / 16))
		len += write(1, &str[mdlo], 1);
	else
	{
		len += ft_puthexa((i / 16), xX);
		len += write(1, &str[mdlo], 1);
	}
	return (len);
}
