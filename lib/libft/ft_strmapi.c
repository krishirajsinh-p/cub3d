/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 02:08:42 by kpuwar            #+#    #+#             */
/*   Updated: 2022/11/19 12:56:49 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*ptr;
	unsigned int		i;

	if (s && f)
	{
		i = ft_strlen(s);
		ptr = ft_calloc(i + 1, sizeof(char));
		if (!ptr)
			return (NULL);
		while (i--)
			ptr[i] = f(i, s[i]);
		return (ptr);
	}
	return (NULL);
}
