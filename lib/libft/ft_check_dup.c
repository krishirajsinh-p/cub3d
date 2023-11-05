/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:34:33 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/25 11:21:55 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_check_dup(t_array *array)
{
	unsigned short	i;
	unsigned short	j;

	i = 0;
	while (i < array->size)
	{
		j = i + 1;
		while (j < array->size)
		{
			if (array->element[i] == array->element[j])
			{
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}
