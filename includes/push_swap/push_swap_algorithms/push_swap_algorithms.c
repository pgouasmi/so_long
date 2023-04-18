/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithms.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:23:00 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/06 15:45:56 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_swap_algorithms(t_list **a_head, t_list **b_head, size_t argc)
{
	if (ft_lst_content_is_ordered(a_head))
		return ;
	else
	{
		if (argc == 0 || argc == 1)
			return ;
		if (argc == 2)
			ft_lst_two_elements_sort(a_head);
		else if (argc == 3)
			ft_lst_three_elements_sort(a_head);
		else
			ft_lst_radix_sort(a_head, b_head);
	}
	return ;
}
