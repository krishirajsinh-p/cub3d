/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 03:51:19 by kpuwar            #+#    #+#             */
/*   Updated: 2022/10/29 06:21:48 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		len_s1;
	int		len_s2;

	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		ptr = (char *) ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
		if (!ptr)
			return (NULL);
		ft_memcpy(ptr, s1, len_s1);
		ft_memcpy((ptr + len_s1), s2, len_s2);
		return (ptr);
	}
	return (NULL);
}
