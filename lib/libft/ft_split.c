/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:04:40 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/29 02:55:25 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcount(const char *str, char del)
{
	size_t	i;
	size_t	wcount;

	i = 0;
	wcount = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == del))
			i++;
		if (str[i] && (str[i] != del))
			wcount++;
		while (str[i] && (str[i] != del))
			i++;
	}
	return (wcount);
}

static bool	allocate(char **out, const char *str, char del, \
				size_t wcount)
{
	size_t	count;
	size_t	index;

	index = 0;
	while (*str && index < wcount)
	{
		count = 0;
		while (*str == del && *str)
			str++;
		while (str[count] && str[count] != del)
			count++;
		out[index] = malloc(sizeof(char) * (count + 1));
		if (!out[index])
			return (false);
		ft_strlcpy(out[index], str, count + 1);
		str += count;
		index++;
	}
	return (true);
}

char	**ft_split(const char *str, char del)
{
	char	**out;
	size_t	wcount;

	if (!str)
		return (NULL);
	wcount = ft_wcount(str, del);
	out = malloc(sizeof(char *) * (wcount + 1));
	if (!out)
		return (NULL);
	if (!allocate(out, str, del, wcount))
	{
		while (*out)
		{
			free(*out);
			out++;
		}
		return (NULL);
	}
	out[wcount] = NULL;
	return (out);
}
