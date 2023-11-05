/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 03:42:46 by kpuwar            #+#    #+#             */
/*   Updated: 2022/11/19 12:51:55 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	strlen_s;
	size_t	strlen_d;
	char	*d;

	strlen_s = ft_strlen(src);
	strlen_d = ft_strlen(dst);
	if (dstsize > 0 && strlen_d < dstsize)
	{
		d = dst + strlen_d;
		i = 0;
		while (src[i] && i < (dstsize - strlen_d - 1))
		{
			d[i] = src[i];
			i++;
		}
		d[i] = '\0';
		return (strlen_s + strlen_d);
	}
	return (strlen_s + dstsize);
}
