/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 03:46:31 by kpuwar            #+#    #+#             */
/*   Updated: 2022/11/19 12:55:51 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup_str;
	int		n;

	n = ft_strlen(s1);
	dup_str = (char *)ft_calloc(n + 1, sizeof(char));
	if (!dup_str)
		return (NULL);
	return (ft_memcpy(dup_str, s1, n));
}
