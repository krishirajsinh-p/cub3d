/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:18:27 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/27 10:23:35 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_get_index(t_array *array, int num)
{
	unsigned int	i;

	i = 0;
	while (i < array->size)
	{
		if (num == array->element[i])
			return (i);
		i++;
	}
	return (-1);
}
