/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 03:51:01 by kpuwar            #+#    #+#             */
/*   Updated: 2022/11/11 02:00:39 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	len_str;

	len_str = ft_strlen(s);
	if (start > len_str)
		return (ft_strdup(""));
	if (len > len_str - start)
		len = len_str - start;
	ptr = (char *) ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	return ((char *)ft_memcpy(ptr, (s + start), len));
}
