/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:12:56 by kpuwar            #+#    #+#             */
/*   Updated: 2022/12/26 22:57:55 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr(long int n)
{
	char	arr[10];
	short	i;
	short	len;

	if (n == 0)
		return (ft_putchar('0'));
	ft_memset(arr, '\0', 10);
	len = 0;
	i = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	while (n > 0)
	{
		arr[i++] = (n % 10) + '0';
		n /= 10;
	}
	len += i;
	while (i--)
		ft_putchar(arr[i]);
	return (len);
}

static int	ft_tohex(unsigned long int n, char c)
{
	char	arr[16];
	short	i;
	short	temp;

	if (n == 0)
		return (ft_putchar('0'));
	ft_memset(arr, '\0', 16);
	i = 0;
	while (n)
	{
		temp = n % 16;
		if (temp > 9)
			arr[i++] = (temp - 10) + c;
		else
			arr[i++] = temp + '0';
		n /= 16;
	}
	temp = i;
	while (i--)
		ft_putchar(arr[i]);
	return (temp);
}

static int	ft_print_var(char c, va_list valist)
{
	if (c == 'c')
		return (ft_putchar(va_arg(valist, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(valist, char *)));
	else if (c == 'p')
		return (ft_putstr("0x") + \
		ft_tohex((unsigned long int) va_arg(valist, void *), 'a'));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(valist, int)));
	else if (c == 'u')
		return (ft_putnbr(va_arg(valist, unsigned int)));
	else if (c == 'x')
		return (ft_tohex(va_arg(valist, unsigned int), 'a'));
	else if (c == 'X')
		return (ft_tohex(va_arg(valist, unsigned int), 'A'));
	else
		return (ft_putchar('%'));
}

int	ft_printf(const char *args, ...)
{
	va_list	valist;
	int		len;

	len = 0;
	va_start(valist, args);
	while (*args)
	{
		if (*args == '%')
			len += ft_print_var(*(++args), valist);
		else
			len += ft_putchar(*args);
		args++;
	}
	va_end(valist);
	return (len);
}
