/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elements_case.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:07:38 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/05 16:29:14 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_three_elements_sort(t_list **head)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	ft_reassign_temp_values(head, &first, &second, &third);
	while (!ft_lst_content_is_ordered(head))
	{
		if (first->content > second->content
			&& first->content > third->content)
		{
			ft_rotate_a(head);
			ft_reassign_temp_values(head, &first, &second, &third);
		}
		if (first->content > second->content)
		{
			ft_swap_a(head);
			ft_reassign_temp_values(head, &first, &second, &third);
		}
		if (second->content > third->content)
		{
			ft_reverse_rotate_a(head);
			ft_reassign_temp_values(head, &first, &second, &third);
		}
	}
	return ;
}

void	ft_reassign_temp_values(t_list **head, t_list **first, t_list **second,
								t_list **third)
{
	*first = *head;
	*second = (*head)->next;
	*third = (*second)->next;
}
