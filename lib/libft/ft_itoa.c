/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:13:58 by kpuwar            #+#    #+#             */
/*   Updated: 2022/10/30 02:38:07 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charreq(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	ln;

	ln = n;
	n = ft_charreq(ln);
	ptr = ft_calloc(n + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	if (ln == 0)
		return (ft_memcpy(ptr, "0", 1));
	if (ln < 0)
	{
		ptr[0] = '-';
		ln *= -1;
	}
	while (ln > 0)
	{
		ptr[--n] = (char)((ln % 10) + '0');
		ln /= 10;
	}
	return (ptr);
}
