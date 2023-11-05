/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:37:39 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/27 10:48:35 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubble_sort(t_array *array)
{
	int				temp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < array->size - 1)
	{
		j = 0;
		while (j < array->size - i - 1)
		{
			if (array->element[j] > array->element[j + 1])
			{
				temp = array->element[j];
				array->element[j] = array->element[j + 1];
				array->element[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
