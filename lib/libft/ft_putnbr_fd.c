/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 05:11:43 by kpuwar            #+#    #+#             */
/*   Updated: 2022/11/01 22:27:44 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	arr[10];
	long	ln;

	ln = n;
	n = 0;
	if (ln == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	ft_memset(arr, '0', 10);
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln *= -1;
	}
	while (ln > 0)
	{
		arr[n++] = (char)((ln % 10) + '0');
		ln /= 10;
	}
	while (n--)
		write(fd, &arr[n], 1);
}
