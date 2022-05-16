/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:49:06 by zaabou            #+#    #+#             */
/*   Updated: 2021/12/03 17:50:49 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr(int i);
int	ft_printf(const char *str, ...);
int	ft_puthexa(unsigned int i, char xX);
int	ft_putstr(const char *str);
int	ft_putchar(char x);
int	ft_flagcase(va_list lst, const char *str, int *i);
int	ft_plus(int vlu);
int	ft_puthash(char c);
int	ft_checksf(char sf);
int	ft_chekflags(char chr);
int	ft_normalcase(va_list lst, char sf);
int	ft_putaddr(unsigned long i);
int	ft_checksfnc(char sf);
int	ft_putun(unsigned int i);
#endif
