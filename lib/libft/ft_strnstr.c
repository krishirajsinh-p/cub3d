/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:48:06 by kpuwar            #+#    #+#             */
/*   Updated: 2022/11/11 03:50:00 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;

	len_needle = ft_strlen(needle);
	if (len_needle != 0)
	{
		if (ft_strlen(haystack) < len_needle || len <= 0)
			return (NULL);
		len -= len_needle - 1;
		while (len--)
			if (!ft_strncmp(haystack++, needle, len_needle))
				return ((char *)haystack - 1);
		return (NULL);
	}
	return ((char *)haystack);
}
