/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 03:41:59 by kpuwar            #+#    #+#             */
/*   Updated: 2022/11/19 12:50:43 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (src < dst)
	{
		d = dst + len - 1;
		s = src + len - 1;
		while (len-- > 0)
			*(d--) = *(s--);
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
