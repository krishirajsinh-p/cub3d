/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:58:37 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/31 11:24:58 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array(t_array *array)
{
	unsigned int	i;

	i = 0;
	while (i < array->size)
	{
		if (i == 0)
			ft_printf("[%i", array->element[i]);
		else if (i == array->size - 1)
			ft_printf(",%i]\n", array->element[i]);
		else
			ft_printf(",%i", array->element[i++]);
	}
}
