/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_array_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:46:08 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/27 15:08:54 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_array_sorted(t_array *array)
{
	unsigned int	i;

	if (array->size < 2)
		return (true);
	i = 0;
	while (i < array->size - 1)
	{
		if (array->element[i] > array->element[i + 1])
			return (false);
		i++;
	}
	return (true);
}
