/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingh <ysingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:40:16 by ysingh            #+#    #+#             */
/*   Updated: 2022/11/10 20:36:23 by ysingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_get_nbr(int i);
int		ft_printf_putchar_fd(char c, int fd);
int		ft_printf_putstr_fd(char *s, int fd);
int		ft_printf_putnbr_fd(int n, int fd);
int		ft_get_nbr_hex(unsigned int i);
int		ft_printtype(char c, va_list args);
int		ft_puthex(unsigned int n, char *base);
int		ft_putdir(unsigned long long n, char *base);
char	*ft_itoa(int n);
int		ft_get_ptr(unsigned long long i);
void	ft_putptr(unsigned long long n, char *base);
int		ft_cont(unsigned int i);
int		ft_putunbr_fd(unsigned int n, int fd);

#endif