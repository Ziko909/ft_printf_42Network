/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:08:00 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/16 19:46:14 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/ft_printf.h"

int	ft_putun(unsigned int i)
{
	int	len;

	len = 0;
	if (i >= 0 && i <= 9)
		len += ft_putchar(i + 48);
	else
	{
		len += ft_putun(i / 10);
		len += ft_putchar((i % 10) + 48);
	}
	return (len);
}
